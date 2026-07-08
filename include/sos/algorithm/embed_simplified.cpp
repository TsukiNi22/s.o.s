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
##  @file embed_simplified.cpp

File Description:
##  Simplified (outdated) embed version of the s.o.s algorithm
\**************************************************************/

#include "../sosDefine.hpp"
#include "../sosType.hpp"
#include <optional>

namespace sos::algorithm { // namespace start

template<sos::algorithm::Option options = sos::algorithm::Option::None, std::uint8_t magic = 0x22>
[[deprecated("This version isn't the most optimized one, you should use sos_embed_optimized or sos")]]
void sos::algorithm::sos_embed_simplified(const sos::algorithm::Bytes& carrier, const sos::algorithm::Bytes& payload, const std::optional<sos::algorithm::Key>& key)
{
}

} // namespace end
