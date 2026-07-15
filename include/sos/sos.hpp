/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 15/07/2026 by @author Tsukini

File Name:
##  @file sos.hpp

File Description:
##  Header for include all the different algorithm
\**************************************************************/

#ifndef SOS_H
    #define SOS_H

#include "algorithm/embed_optimized.hpp"    // sos::algorithm::sos_embed_optimized
#include "algorithm/extract_optimized.hpp"  // sos::algorithm::sos_extract_optimized
#include "tools/convert.hpp"                // sos::tools::to_bytes
#include "sosDefine.hpp"                    // sos::Option
#include "sosType.hpp"                      // std::vector<ByteT>
#include <optional>                         // std::optional, std::nullopt
#include <cstdint>                          // std::uint8_t
#include <vector>                           // std::vector

namespace sos { // namespace start

// rediretion (auto handle of the optional build of the key)
template<sos::Option options = sos::Option::None, std::uint8_t magic = MAGIC, typename ByteT>
inline void sos_embed(std::vector<ByteT>& carrier, const std::vector<ByteT>& payload)
{
    static_assert(std::unsigned_integral<ByteT>, "ByteT must be an unsigned integer type");
    sos::algorithm::sos_embed_optimized<options, magic>(carrier, payload);
}
template<sos::Option options = sos::Option::None, std::uint8_t magic = MAGIC, typename ByteT>
inline void sos_embed(std::vector<ByteT>& carrier, const std::vector<ByteT>& payload, const std::vector<ByteT>& key)
{
    static_assert(std::unsigned_integral<ByteT>, "ByteT must be an unsigned integer type");
    sos::algorithm::sos_embed_optimized<options, magic>(carrier, payload, std::make_optional(key));
}

template<std::uint8_t magic = MAGIC, typename ByteT>
[[nodiscard]] inline std::vector<ByteT> sos_extract(const std::vector<ByteT>& carrier)
{
    static_assert(std::unsigned_integral<ByteT>, "ByteT must be an unsigned integer type");
    return sos::algorithm::sos_extract_optimized<magic>(carrier);
}
template<std::uint8_t magic = MAGIC, typename ByteT>
[[nodiscard]] inline std::vector<ByteT> sos_extract(const std::vector<ByteT>& carrier, const std::vector<ByteT>& key)
{
    static_assert(std::unsigned_integral<ByteT>, "ByteT must be an unsigned integer type");
    return sos::algorithm::sos_extract_optimized<magic>(carrier, std::make_optional(key));
}

} // namespace end
#endif /* SOS_H */
