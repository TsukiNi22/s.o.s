/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  @date 10/07/2026 by @author Tsukini

File Name:
##  @file noise.cpp

File Description:
##  Different noise tools used for the s.o.s algorithm
\**************************************************************/

#include "sos/tools/noise.hpp"  // namespace
#include "sos/sosDefine.hpp"    // sos::* (define)
#include "sos/sosType.hpp"      // sos::* (type)
#include <stdexcept>            // std::* (exception)
#include <algorithm>            // std::clamp
#include <optional>             // std::optional
#include <cstdint>              // std::uint_fast32_t
#include <random>               // std::random_device, std::mt19937, std::normal_distribution
#include <vector>               // std::vector

/* global */
void sos::tools::noise(sos::Bytes& bytes)
{
    // Compute signal amplitudes RMS
    double rms = 0.0;
    for (sos::Byte byte: bytes) rms += static_cast<double>(byte) * static_cast<double>(byte);
    rms /= static_cast<double>(bytes.size());

    // Check if the noise won't litteraly become the content
    if (rms < RMS_LIMIT * RMS_LIMIT)
        throw std::out_of_range("RMS is too small");

    // Noise generation setup
    static thread_local std::random_device rd;
    static thread_local std::mt19937 gen(rd());
    std::normal_distribution<double> values(0.0, rms * NOISE_COEF);

    // Apply random values
    for (sos::Byte& byte: bytes)
        byte = std::clamp(byte + values(gen), 0.0, static_cast<double>(UINTN_MAX));
}

/* local */
void sos::tools::noise(sos::Bytes& bytes, const std::vector<std::uint_fast32_t>& index)
{
    // Compute signal amplitudes RMS
    double rms = 0.0;
    for (std::uint_fast32_t i: index) rms += static_cast<double>(bytes[i]) * static_cast<double>(bytes[i]);
    rms /= static_cast<double>(index.size());

    // Check if the noise won't litteraly become the content
    if (rms < RMS_LIMIT * RMS_LIMIT)
        throw std::out_of_range("RMS is too small");

    // Noise generation setup
    static thread_local std::random_device rd;
    static thread_local std::mt19937 gen(rd());
    std::normal_distribution<double> values(0.0, rms * NOISE_COEF);

    // Apply random values
    for (std::uint_fast32_t i: index)
        bytes[i] = std::clamp(bytes[i] + values(gen), 0.0, static_cast<double>(UINTN_MAX));
}
