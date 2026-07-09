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
##  @file extract_simplified.hpp

File Description:
##  Simplified (outdated) extract version of the s.o.s algorithm
\**************************************************************/

#include "../sosDefine.hpp"         // sos::* (define)
#include "../sosType.hpp"           // sos::* (type)
#include "../tools/threshold.hpp"   // sos::tools::getThresholdIndex
#include "../tools/noise.hpp"       // sos::tools::noise
#include "../tools/hash.hpp"        // sos::tools::hash
#include <stdexcept>                // std::* (exception)
#include <optional>                 // std::optional
#include <cstdint>                  // std::uint8_t, std::uint_fast32_t
#include <new>                      // std::hardware_destructive_interference_size

namespace sos::algorithm { // namespace start

#ifndef SOS_EXTRACT_SIMPLIFIED
    #define SOS_EXTRACT_SIMPLIFIED
template<std::uint8_t magic = MAGIC>
[[deprecated("This version isn't the most optimized one, you should use sos_extract_optimized or sos_extract")]]
[[nodiscard]] sos::Bytes sos_extract_simplified(const sos::Bytes& carrier, const std::optional<sos::Key>& key = std::nullopt)
{
    alignas(std::hardware_destructive_interference_size) std::vector<std::uint_fast32_t> index;
    alignas(std::hardware_destructive_interference_size) sos::Bytes bytes;

    // Get the valid index within the accepted amplitude
    sos::tools::getThresholdIndex(index, carrier);

    // Check for the minimum space that is required (magic + size) + index used for the seed
    if (index.size() < (sizeof(sos::Byte) + std::max(std::size_t{1}, sizeof(std::size_t) / sizeof(sos::Byte))) * 8 + SEED_ELEMENT_COUNT) [[unlikely]] {
        throw std::out_of_range("Too few valide bytes that allow data storage, no hidden message");
    }

    // Generate a seed
    std::uint_fast32_t seed = sos::tools::hash(index, carrier);
    index.resize(index.size() - SEED_ELEMENT_COUNT);

    // Apply key to the seed if given
    if (key.has_value()) [[unlikely]] {
        for (sos::Byte byte: *key) {
            seed ^= static_cast<std::uint_fast32_t>(byte);
            seed *= 16777619u;
        }
    }

    // Shuffle the index using the generated seed
    std::mt19937 gen(seed);
    std::shuffle(index.begin(), index.end(), gen);

    // Reading byte methode
    std::size_t idx = 0;
    auto read_byte = [&](sos::Byte& byte)
    {
        byte = 0;
        for (std::size_t b = 0; b < sizeof(sos::Byte) * 8; ++b) {
            std::size_t pos = index[idx++];
            sos::Byte bit = carrier[pos] & 1;
            byte |= (bit << b);
        }
    };

    // Check the header (magic)
    sos::Byte identifier = 0;
    read_byte(identifier);
    if (identifier != magic) [[unlikely]] {
        throw std::invalid_argument("Invalid MAGIC byte, no hidden message");
    }

    // Check the header (size)
    std::size_t size = 0;
    for (std::size_t i = 0; i < std::max(std::size_t{1}, sizeof(std::size_t) / sizeof(sos::Byte)); ++i) {
        sos::Byte byte = 0;
        read_byte(byte);
        size |= (static_cast<std::size_t>(byte) << (sizeof(sos::Byte) * 8 * i));
    }

    // Check if there is place for the index used for the seed & payload
    if (index.size() < sizeof(sos::Byte) * 8 * size + SEED_ELEMENT_COUNT) [[unlikely]] {
        throw std::out_of_range("Invalid carrier, there is less valide bytes that allow data storage than excepted: " + std::to_string(sizeof(sos::Byte) * 8 * size + SEED_ELEMENT_COUNT));
    }

    // Get the payload
    bytes.resize(size);
    for (std::size_t i = 0; i < size; ++i) read_byte(bytes[i]);

    return bytes;
}
#endif /* SOS_EXTRACT_SIMPLIFIED */

} // namespace end
