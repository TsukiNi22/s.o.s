/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 08/07/2026 by @author Tsukini

File Name:
##  @file threshold.cpp

File Description:
##  Different threshold tools used for the s.o.s algorithm
\**************************************************************/

#include "sos/tools/threshold.hpp"  // namespace
#include "sos/sosDefine.hpp"        // sos::* (define)
#include "sos/sosType.hpp"          // sos::* (type)
#include <stdexcept>                // std::* (exception)
#include <algorithm>                // std::count
#include <optional>                 // std::optional
#include <cstdint>                  // std::uint_fast32_t
#include <vector>                   // std::vector
#include <string>                   // std::to_string
#include <array>                    // std::array

void sos::tools::getThresholdIndex(std::vector<std::uint_fast32_t>& index, const sos::Bytes& bytes)
{
    static bool init = false;
    if (!init) [[unlikely]] {init = true; index.reserve(bytes.size());}
    index.clear();
    for (std::size_t i = 0; i < bytes.size(); ++i) {
        if (bytes[i] >= THRESHOLD_MIN && __builtin_expect(bytes[i] <= THRESHOLD_MAX, 1)) [[likely]] {index.push_back(i);}
    }
}

void sos::tools::removeThreshold(sos::Bytes& bytes)
{
    // Check the limits
    std::array<bool, UINTN_MAX + 1> seen{false};
    for (sos::Byte byte: bytes) seen[byte] = true;
    std::size_t rangeUsed = std::count(seen.begin(), seen.end(), true);
    if (rangeUsed < RANGE_USED_MIN) [[unlikely]] {
        throw std::out_of_range("Too few range used can't edit thresholds, the limit was reach: " + std::to_string(rangeUsed));
    } else if (rangeUsed > RANGE_USED_MAX) [[unlikely]] {
        throw std::out_of_range("Too many range used can't edit thresholds, the limit was reach: " + std::to_string(rangeUsed));
    }

    // Remove those on threshold
    for (sos::Byte& byte: bytes) {
        if (byte == THRESHOLD_MIN)      byte -= (byte > 0) ? 1 : -1;
        else if (byte == THRESHOLD_MAX) byte += (byte > 0) ? 1 : -1;
    }
}
