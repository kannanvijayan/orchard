#ifndef ORCHARD__COMMON_HPP
#define ORCHARD__COMMON_HPP

#include <inttypes.h>
#include <stddef.h>
#include <limits.h>
#include "config.h"

// Exactly one of ARCH_BITS_32 or ARCH_BITS_64 should be defined.
#if defined(ARCH_BITS_32) && defined(ARCH_BITS_64)
#   error "Both ARCH_BITS_32 and ARCH_BITS_64 are defined!"
#endif

#if !defined(ARCH_BITS_32) && !defined(ARCH_BITS_64)
#   error "Neither ARCH_BITS_32 nor ARCH_BITS_64 are defined!"
#endif

namespace Orchard {


#if defined(ARCH_BITS_32)
constexpr unsigned WordBits = 32;
constexpr unsigned WordBytes = 4;
typedef uint32_t word_t;
typedef int32_t sword_t;
    
#else // defined(ARCH_BITS_64)
constexpr unsigned WordBits = 64;
constexpr unsigned WordBytes = 8;
typedef uint64_t word_t;
typedef int64_t sword_t;
#endif

// NOTE: Maximal allowed character is 0x10FFFF
// See ECMA-262 Edition 6, Clause 6.
typedef int32_t unic_t;
constexpr unic_t InvalidUnicode = -1;
constexpr unic_t MaxUnicode = 0x10FFFFu;

// Helper to convert integer to [u]int[64|32]_t
template <typename IntT>
constexpr uint64_t ToUInt64(IntT val) {
    return static_cast<uint64_t>(val);
}

template <typename IntT>
constexpr uint32_t ToUInt32(IntT val) {
    return static_cast<uint32_t>(val);
}

template <typename IntT>
constexpr uint16_t ToUInt16(IntT val) {
    return static_cast<uint16_t>(val);
}

template <typename IntT>
constexpr uint8_t ToUInt8(IntT val) {
    return static_cast<uint8_t>(val);
}

template <typename IntT>
constexpr int64_t ToInt64(IntT val) {
    return static_cast<int64_t>(val);
}

template <typename IntT>
constexpr int32_t ToInt32(IntT val) {
    return static_cast<int32_t>(val);
}

template <typename IntT>
constexpr int16_t ToInt16(IntT val) {
    return static_cast<int16_t>(val);
}

template <typename IntT>
constexpr int8_t ToInt8(IntT val) {
    return static_cast<int8_t>(val);
}

template <typename IntT>
constexpr int8_t ToSize(IntT val) {
    return static_cast<size_t>(val);
}

// Casting between pointers and words.
template <typename T>
constexpr inline word_t PtrToWord(T *ptr) {
    return reinterpret_cast<word_t>(ptr);
}
template <typename T>
constexpr inline T *WordToPtr(word_t word) {
    return reinterpret_cast<T *>(word);
}


} // namespace Orchard

#endif // ORCHARD__COMMON_HPP
