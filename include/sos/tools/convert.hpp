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
##  @file convert.hpp

File Description:
##  Include of the convertion tools
\**************************************************************/

#ifndef CONVERT_H
    #define CONVERT_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../sosType.hpp"   // sos::* (type)
    #include <concepts>
    #include <cstring>
    #include <ranges>

namespace sos::tools { // namespace start
//----------------------------------------------------------------//
/* PROTOTYPE */

template<std::ranges::input_range Range>
sos::Bytes to_bytes(const Range& range)
{
    using T = std::ranges::range_value_t<Range>;
    static_assert(std::is_trivially_copyable_v<T>, "Element type must be trivially copyable.");

    sos::Bytes bytes;
    bytes.reserve(std::ranges::size(range) * sizeof(T));
    for (const T& value: range) {
        const auto* ptr = reinterpret_cast<const sos::Byte*>(&value);
        bytes.insert(bytes.end(), ptr, ptr + sizeof(T));
    }

    return bytes;
}

template<std::ranges::input_range Range>
Range bytes_to(const sos::Bytes& bytes)
{
    using T = std::ranges::range_value_t<Range>;
    static_assert(std::is_trivially_copyable_v<T>, "Element type must be trivially copyable.");

    if (bytes.size() % sizeof(T) != 0) [[unlikely]] {
        throw std::invalid_argument("Invalid byte count.");
    }

    Range range;
    if constexpr (requires {range.reserve(0);}) [[likely]] {
        range.reserve(bytes.size() / sizeof(T));
    }
    for (std::size_t i = 0; i < bytes.size(); i += sizeof(T)) {
        T value;
        std::memcpy(&value, bytes.data() + i, sizeof(T));
        if constexpr (requires {range.push_back(value);}) [[likely]] {
            range.push_back(value);
        } else {
            range.insert(range.end(), value);
        }
    }

    return range;
}

} // namespace end
#endif /* CONVERT_H */
