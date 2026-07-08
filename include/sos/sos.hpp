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
    #include <optional> // std::optional, std::nullopt
    #include <cstdint>  // std::uint8_t
    #include <vector>   // std::vector

namespace sos::algorithm { // namespace start
//----------------------------------------------------------------//
/* TYPE */

/* type simplification */
using Byte = std::uint8_t;
using Bytes = std::vector<sos::algorithm::Byte>;
using Key = Bytes;

//----------------------------------------------------------------//
/* PROTOTYPE */

/* optimized */
void sos_embed_optimized(const sos::algorithm::Bytes& carrier, const sos::algorithm::Bytes& payload, const std::optional<sos::algorithm::Key>& key = std::nullopt);
sos::algorithm::Bytes sos_extract_optimized(const sos::algorithm::Bytes& carrier, const std::optional<sos::algorithm::Key>& key = std::nullopt);

/* simplified */
void sos_embed_simplified(const sos::algorithm::Bytes& carrier, const sos::algorithm::Bytes& payload, const std::optional<sos::algorithm::Key>& key = std::nullopt);
sos::algorithm::Bytes sos_extract_simplified(const sos::algorithm::Bytes& carrier, const std::optional<sos::algorithm::Key>& key = std::nullopt);

} // namespace end

namespace sos { // namespace start

// rediretion
inline void sos_embed(const sos::algorithm::Bytes& carrier, const sos::algorithm::Bytes& payload, const std::optional<sos::algorithm::Key>& key = std::nullopt)
{
    sos::algorithm::sos_embed_optimized(carrier, payload);
}

[[nodiscard]] inline sos::algorithm::Bytes sos_extract(const sos::algorithm::Bytes& carrier, const std::optional<sos::algorithm::Key>& key = std::nullopt)
{
    return sos::algorithm::sos_extract_optimized(carrier);
}

} // namespace end
#endif /* SOS_H */
