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
##  @file hash.hpp

File Description:
##  Include of the hash generation tools
\**************************************************************/

#ifndef HASH_H
    #define HASH_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../sosType.hpp"   // sos::* (type)
    #include <cstdint>          // std::uint_fast32_t
    #include <vector>           // std::vector

namespace sos::tools { // namespace start
//----------------------------------------------------------------//
/* PROTOTYPE */

std::uint_fast32_t hash(const std::vector<std::uint_fast32_t>& index, const sos::Bytes& bytes);

} // namespace end
#endif /* HASH_H */
