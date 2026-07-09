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
##  @file sosDefine.hpp

File Description:
##  You know, I don t think there are good or bad descriptions,
##  for me, life is all about functions...
\**************************************************************/

#ifndef SOSDEFINE_H
    #define SOSDEFINE_H

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* type */
    #include "sosType.hpp"  // sos::Byte
    #include <cstdint>      // std::uint8_t
    #include <limits>       // std::numeric_limits<T>

    //----------------------------------------------------------------//
    /* DEFINE */

    /* const */
    #define MAGIC 0x22
    #define NOISE_COEF 0.0025 // 0.001 < Studio < 0.005 < Mic < 0.02 (noise coef for amplitude)
    #define SEED_ELEMENT_COUNT 256 // number of index used for the seed creation

    /* values */
    #define UINTN_MIN std::numeric_limits<sos::Byte>::min()
    #define UINTN_MAX std::numeric_limits<sos::Byte>::max()

    /* limits */
    #define RMS_LIMIT 250.0 // 100 ~ 5000 normal
    #define PAYLOAD_PERCENTAGE_LIMIT 0.075 // The payload can only be x percent of the total signal at max
    #define THRESHOLD_MIN (1u << (sizeof(sos::Byte) * 8 / 2))
    #define THRESHOLD_MAX (UINTN_MAX - (1u << (sizeof(sos::Byte) * 8 / 2)))
    #define RANGE_USED_MIN (UINTN_MAX * 0.05) // Need at least x percentage of the whole range to ensure some security
    #define RANGE_USED_MAX (UINTN_MAX * (1.0 - 0.05)) // Need less than x percentage of the whole range to ensure some security

namespace sos { // namespace start
//----------------------------------------------------------------//
/* ENUM */

enum Option {
    None        = 0,
    Noise       = 1 << 0,
    GlobalNoise = 1 << 1,
};

} // namespace end
#endif /* SOSDEFINE_H */
