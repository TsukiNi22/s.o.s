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
##  @file extract_simplified.hpp

File Description:
##  Simplified (outdated) extract version of the s.o.s algorithm
\**************************************************************/

#include "../sosDefine.hpp"
#include "../sosType.hpp"
#include <optional>
#include <cstdint>

namespace sos::algorithm { // namespace start

#ifndef SOS_EXTRACT_SIMPLIFIED
    #define SOS_EXTRACT_SIMPLIFIED
template<std::uint8_t magic = MAGIC>
[[deprecated("This version isn't the most optimized one, you should use sos_extract_optimized or sos")]]
[[nodiscard]] sos::Bytes sos_extract_simplified(const sos::Bytes& carrier, const std::optional<sos::algorithm::Key>& key)
{
}
#endif /* SOS_EXTRACT_SIMPLIFIED */

} // namespace end
