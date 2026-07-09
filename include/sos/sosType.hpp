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
##  @file sosType.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
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

/* type simplification */
using Byte = std::uint16_t;
using Bytes = std::vector<sos::Byte>;
using Key = Bytes;

} // namespace end
#endif /* SOSTYPE_H */
