/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 09/07/2026 by @author Tsukini

File Name:
##  @file embed_simplified.hpp

File Description:
##  Simplified (outdated) embed version of the s.o.s algorithm
\**************************************************************/

#include "../sosDefine.hpp"         // sos::* (define)
#include "../sosType.hpp"           // sos::* (type)
#include "../tools/threshold.hpp"   // sos::tools::getThresholdIndex, sos::tools::removeThreshold
#include "../tools/noise.hpp"       // sos::tools::noise
#include "../tools/hash.hpp"        // sos::tools::hash
#include <stdexcept>                // std::* (exception)
#include <optional>                 // std::optional
#include <cstdint>                  // std::uint8_t, std::uint_fast32_t
#include <new>                      // std::hardware_destructive_interference_size

namespace sos::algorithm { // namespace start

#ifndef SOS_EMBED_SIMPLIFIED
    #define SOS_EMBED_SIMPLIFIED
template<sos::Option options = sos::Option::None, std::uint8_t magic = MAGIC>
[[deprecated("This version isn't the most optimized one, you should use sos_embed_optimized or sos")]]
void sos_embed_simplified(sos::Bytes& carrier, const sos::Bytes& payload, const std::optional<sos::Key>& key)
{
    alignas(std::hardware_destructive_interference_size) std::vector<std::uint_fast32_t> index;
    alignas(std::hardware_destructive_interference_size) sos::Bytes bytes;

    // Setup message (header data + payload)
    bytes.push_back(magic);
    std::size_t size = payload.size();
    for (std::size_t i = 0; i < sizeof(size); ++i) bytes.push_back((size >> (8 * i)) & 0xFF);
    bytes.insert(bytes.end(), payload.begin(), payload.end());

    // On noise generation (global)
    if constexpr (options & sos::Option::GlobalNoise) {
        // Get the valid index within the accepted amplitude
        sos::tools::getThresholdIndex(index, carrier);

        // Generate noise on already valid values
        sos::tools::noise(carrier, index);
    }

    // On noise generation (local)
    else if constexpr (options & sos::Option::Noise) {
        // Generate noise on all values
        sos::tools::noise(carrier);
    }

    // Remove the values on the brink of the accepted amplitude
    sos::tools::removeThreshold(carrier);

    // Get the valid index within the accepted amplitude
    sos::tools::getThresholdIndex(index, carrier);

    // Check if the payload can be hiden in the carrier
    double percentage = static_cast<double>(sizeof(sos::Byte) * 8 * bytes.size()) / static_cast<double>(index.size());
    if (percentage > PAYLOAD_PERCENTAGE_LIMIT) [[unlikely]] {
        throw std::out_of_range("Too few valide bytes that allow data storage, the payload percentage limit was reach: " + std::to_string(percentage / 100.0) + "%");
    }

    // Check if there is place for the element used for the seed
    if (index.size() < sizeof(sos::Byte) * 8 * bytes.size() + SEED_ELEMENT_COUNT) [[unlikely]] {
        throw std::out_of_range("Too few valide bytes that allow data storage, the limit was reach: " + std::to_string(sizeof(sos::Byte) * 8 * bytes.size() + UINTN_MAX));
    }

    // Generate a seed
    std::uint_fast32_t seed = sos::tools::hash(index, carrier);
    index.resize(index.size() - SEED_ELEMENT_COUNT);

    // Apply key to the seed if given
    if (key.has_value()) [[unlikely]] {
        for (sos:Byte byte: *key) {
            seed ^= static_cast<std::uint_fast32_t>(b);
            seed *= 16777619u;
        }
    }

    // Shuffle the index using the generated seed
    std::mt19937 gen(seed);
    std::shuffle(index.begin(), index.end(), gen);

    // Store the payload
    std::size_t idx = 0;
    for (std::size_t i = 0; i < sizeof(sos::Byte) * bytes.size(); ++i)
    for (std::size_t j = 0; j < 8; ++j) {
        int bit = (bytes[i] >> j) & 0b1;
        std::size_t pos = index[idx++];
        carrier[pos] = (carrier[pos] & ~1) | bit;
    }
}
#endif /* SOS_EMBED_SIMPLIFIED */

} // namespace end
