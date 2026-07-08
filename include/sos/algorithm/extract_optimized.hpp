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
##  @file extract_optimized.hpp

File Description:
##  Optimized extract version of the s.o.s algorithm
\**************************************************************/

#include "../sosDefine.hpp"
#include "../sosType.hpp"
#include <optional>
#include <cstdint>

namespace sos::algorithm { // namespace start

#ifndef SOS_EXTRACT_OPTIMIZED
    #define SOS_EXTRACT_OPTIMIZED
template<std::uint8_t magic = MAGIC>
[[nodiscard]] sos::Bytes sos_extract_optimized(const sos::Bytes& carrier, const std::optional<sos::algorithm::Key>& key)
{
}
#endif /* SOS_EXTRACT_OPTIMIZED */

} // namespace end
