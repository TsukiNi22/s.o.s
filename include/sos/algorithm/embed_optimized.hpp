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
##  @file embed_optimized.hpp

File Description:
##  Optimized embed version of the s.o.s algorithm
\**************************************************************/

#include "../sosDefine.hpp"
#include "../sosType.hpp"
#include <optional>
#include <cstdint>

namespace sos::algorithm { // namespace start

#ifndef SOS_EMBED_OPTIMIZED
    #define SOS_EMBED_OPTIMIZED
template<sos::Option options = sos::Option::None, std::uint8_t magic = MAGIC>
void sos_embed_optimized(sos::Bytes& carrier, const sos::Bytes& payload, const std::optional<sos::Key>& key = std::nullopt)
{
}
#endif /* SOS_EMBED_OPTIMIZED */

} // namespace end
