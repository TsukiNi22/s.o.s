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
##  @file sos.hpp

File Description:
##  Header for include all the different algorithm
\**************************************************************/

#ifndef SOS_H
    #define SOS_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "algorithm/embed_optimized.cpp"    // sos::algorithm::sos_embed_optimized
    #include "algorithm/extract_optimized.cpp"  // sos::algorithm::sos_extract_optimized
    #include "sosDefine.hpp"                    // sos::Option
    #include "sosType.hpp"                      // sos::Bytes
    #include <optional>                         // std::optional, std::nullopt
    #include <cstdint>                          // std::uint8_t

namespace sos { // namespace start

// rediretion
template<sos::Option options = sos::Option::None, std::uint8_t magic = MAGIC>
inline void sos_embed(sos::Bytes& carrier, const sos::Bytes& payload, const std::optional<sos::Key>& key = std::nullopt)
{
    sos::algorithm::sos_embed_optimized<options, magic>(carrier, payload);
}

template<std::uint8_t magic = MAGIC>
[[nodiscard]] inline sos::Bytes sos_extract(const sos::Bytes& carrier, const std::optional<sos::Key>& key = std::nullopt)
{
    return sos::algorithm::sos_extract_optimized<magic>(carrier);
}

} // namespace end
#endif /* SOS_H */
