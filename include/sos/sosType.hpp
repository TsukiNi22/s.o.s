/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 27/07/2026 by @author Tsukini

File Name:
##  @file sosType.hpp

File Description:
##  Default type used by the s.o.s algorithm
\**************************************************************/

#ifndef SOSTYPE_H
    #define SOSTYPE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include <cstdint>  // std::uint16_t
    #include <vector>   // std::vector

namespace sos { // namespace start
//----------------------------------------------------------------//
/* TYPE */

/* type simplification (default) */
[[maybe_unused]] using Byte  = std::uint16_t; // Default Byte type
[[maybe_unused]] using Bytes = std::vector<sos::Byte>;
[[maybe_unused]] using Key   = sos::Bytes;

} // namespace end
#endif /* SOSTYPE_H */
