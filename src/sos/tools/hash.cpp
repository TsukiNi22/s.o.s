/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 10/07/2026 by @author Tsukini

File Name:
##  @file hash.cpp

File Description:
##  Different hash tools used for the s.o.s algorithm
\**************************************************************/

#include "sos/tools/hash.hpp"   // namespace
#include "sos/sosDefine.hpp"    // sos::* (define)
#include "sos/sosType.hpp"      // sos::* (type)
#include <stdexcept>            // std::* (exception)
#include <optional>             // std::optional
#include <cstdint>              // std::uint_fast32_t
#include <vector>               // std::vector
#include <cmath>                // std::sin, std::abs

[[nodiscard]] std::uint_fast32_t sos::tools::hash(const std::vector<std::uint_fast32_t>& index, const sos::Bytes& bytes)
{
    constexpr double magic = -1.460354508809587;
    std::uint_fast32_t seed = 0x811c9dc5;
    for (std::size_t i = 0; i < SEED_ELEMENT_COUNT; ++i) {
        double s = std::sin(bytes[index[index.size() - 1 - i]]) / magic;
        std::uint_fast32_t v = static_cast<std::uint_fast32_t>(std::abs(s) * 1e9);
        seed ^= v + (seed << (seed % 6)) + (seed >> (seed & 1)) + 0x9e3779b9;
    }
    return seed;
}
