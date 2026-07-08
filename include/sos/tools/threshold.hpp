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
##  @file threshold.hpp

File Description:
##  Include of the threshold tools
\**************************************************************/

#ifndef THRESHOLD_H
    #define THRESHOLD_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "../sosType.hpp"   // sos::* (type)
    #include <cstdint>          // std::uint_fast32_t
    #include <vector>           // std::vector

namespace sos::tools { // namespace start
//----------------------------------------------------------------//
/* PROTOTYPE */

void getThresholdIndex(std::vector<std::uint_fast32_t>& index, const sos::Bytes& bytes);
void removeThreshold(sos::Bytes& bytes);

} // namespace end
#endif /* THRESHOLD_H */
