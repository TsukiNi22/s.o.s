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
##  @file noise.hpp

File Description:
##  Include of the noise generation tools
\**************************************************************/

#ifndef NOISE_H
    #define NOISE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../sosType.hpp"   // sos::* (type)
    #include <cstdint>          // std::uint_fast32_t
    #include <vector>           // std::vector

namespace sos::tools { // namespace start
//----------------------------------------------------------------//
/* PROTOTYPE */

void noise(sos::Bytes& bytes);
void noise(sos::Bytes& bytes, const std::vector<std::uint_fast32_t>& index);

} // namespace end
#endif /* NOISE_H */
