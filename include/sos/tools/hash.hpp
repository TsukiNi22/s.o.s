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
##  @file hash.hpp

File Description:
##  Include of the hash generation tools
\**************************************************************/

#ifndef HASH_H
    #define HASH_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../sosDefine.hpp" // sos::* (define)
    #include "../sosType.hpp"   // sos::* (type)
    #include <stdexcept>        // std::* (exception)
    #include <optional>         // std::optional
    #include <cstdint>          // std::uint_fast32_t
    #include <vector>           // std::vector
    #include <cmath>            // std::sin, std::abs

namespace sos::tools { // namespace start
//----------------------------------------------------------------//
/* PROTOTYPE */

template<typename ByteT>
[[nodiscard]] std::uint_fast32_t hash(const std::vector<std::uint_fast32_t>& index, const std::vector<ByteT>& bytes)
{
    // Check given type
    static_assert(std::unsigned_integral<ByteT>, "ByteT must be an unsigned integer type");

    constexpr double magic = -1.460354508809587;
    std::uint_fast32_t seed = 0x811c9dc5;
    for (std::size_t i = 0; i < SEED_ELEMENT_COUNT; ++i) {
        double s = std::sin(bytes[index[index.size() - 1 - i]]) / magic;
        std::uint_fast32_t v = static_cast<std::uint_fast32_t>(std::abs(s) * 1e9);
        seed ^= v + (seed << (seed % 6)) + (seed >> (seed & 1)) + 0x9e3779b9;
    }
    return seed;
}

} // namespace end
#endif /* HASH_H */
