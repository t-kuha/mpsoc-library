#pragma once

#include <ATen/Type.h>
#include <ATen/core/Half.h>
#include <c10/util/Exception.h>

#define AT_PRIVATE_CASE_TYPE(enum_type, type, ...) \
  case enum_type: {                                \
    using scalar_t = type;                         \
    return __VA_ARGS__();                          \
  }

#define AT_DISPATCH_FLOATING_TYPES(TYPE, NAME, ...)                          \
  [&] {                                                                      \
    const at::Type& the_type = TYPE;                                         \
    switch (the_type.scalarType()) {                                         \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Double, double, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Float, float, __VA_ARGS__)        \
      default:                                                               \
        AT_ERROR(#NAME, " not implemented for '", the_type.toString(), "'"); \
    }                                                                        \
  }()

#define AT_DISPATCH_FLOATING_TYPES_AND_HALF(TYPE, NAME, ...)                 \
  [&] {                                                                      \
    const at::Type& the_type = TYPE;                                         \
    switch (the_type.scalarType()) {                                         \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Double, double, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Float, float, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Half, at::Half, __VA_ARGS__)      \
      default:                                                               \
        AT_ERROR(#NAME, " not implemented for '", the_type.toString(), "'"); \
    }                                                                        \
  }()

#define AT_DISPATCH_FLOATING_AND_COMPLEX_TYPES(TYPE, NAME, ...)              \
  [&] {                                                                      \
    const at::Type& the_type = TYPE;                                         \
    switch (the_type.scalarType()) {                                         \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Double, double, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Float, float, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Half, at::Half, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(                                                  \
          at::ScalarType::ComplexDouble, std::complex<double>, __VA_ARGS__)  \
      AT_PRIVATE_CASE_TYPE(                                                  \
          at::ScalarType::ComplexFloat, std::complex<float>, __VA_ARGS__)    \
      AT_PRIVATE_CASE_TYPE(                                                  \
          at::ScalarType::ComplexHalf, std::complex<at::Half>, __VA_ARGS__)  \
      default:                                                               \
        AT_ERROR(#NAME, " not implemented for '", the_type.toString(), "'"); \
    }                                                                        \
  }()

#define AT_DISPATCH_INTEGRAL_TYPES(TYPE, NAME, ...)                          \
  [&] {                                                                      \
    const at::Type& the_type = TYPE;                                         \
    switch (the_type.scalarType()) {                                         \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Byte, uint8_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Char, int8_t, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Int, int32_t, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Long, int64_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Short, int16_t, __VA_ARGS__)      \
      default:                                                               \
        AT_ERROR(#NAME, " not implemented for '", the_type.toString(), "'"); \
    }                                                                        \
  }()

#define AT_DISPATCH_ALL_TYPES(TYPE, NAME, ...)                               \
  [&] {                                                                      \
    const at::Type& the_type = TYPE;                                         \
    switch (the_type.scalarType()) {                                         \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Byte, uint8_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Char, int8_t, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Double, double, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Float, float, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Int, int32_t, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Long, int64_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Short, int16_t, __VA_ARGS__)      \
      default:                                                               \
        AT_ERROR(#NAME, " not implemented for '", the_type.toString(), "'"); \
    }                                                                        \
  }()

#define AT_DISPATCH_ALL_TYPES_AND_HALF(TYPE, NAME, ...)                      \
  [&] {                                                                      \
    const at::Type& the_type = TYPE;                                         \
    switch (the_type.scalarType()) {                                         \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Byte, uint8_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Char, int8_t, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Double, double, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Float, float, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Int, int32_t, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Long, int64_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Short, int16_t, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Half, at::Half, __VA_ARGS__)      \
      default:                                                               \
        AT_ERROR(#NAME, " not implemented for '", the_type.toString(), "'"); \
    }                                                                        \
  }()

#define AT_DISPATCH_COMPLEX_TYPES(TYPE, NAME, ...)                           \
  [&] {                                                                      \
    const at::Type& the_type = TYPE;                                         \
    switch (the_type.scalarType()) {                                         \
      AT_PRIVATE_CASE_TYPE(                                                  \
          at::ScalarType::ComplexFloat, std::complex<float>, __VA_ARGS__)    \
      AT_PRIVATE_CASE_TYPE(                                                  \
          at::ScalarType::ComplexDouble, std::complex<double>, __VA_ARGS__)  \
      default:                                                               \
        AT_ERROR(#NAME, " not implemented for '", the_type.toString(), "'"); \
    }                                                                        \
  }()

#define AT_DISPATCH_ALL_TYPES_AND_COMPLEX(TYPE, NAME, ...)                   \
  [&] {                                                                      \
    const at::Type& the_type = TYPE;                                         \
    switch (the_type.scalarType()) {                                         \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Byte, uint8_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Char, int8_t, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Double, double, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Float, float, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Int, int32_t, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Long, int64_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Short, int16_t, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(                                                  \
          at::ScalarType::ComplexFloat, std::complex<float>, __VA_ARGS__)    \
      AT_PRIVATE_CASE_TYPE(                                                  \
          at::ScalarType::ComplexDouble, std::complex<double>, __VA_ARGS__)  \
      default:                                                               \
        AT_ERROR(#NAME, " not implemented for '", the_type.toString(), "'"); \
    }                                                                        \
  }()

#define AT_DISPATCH_ALL_TYPES_AND_HALF_AND_COMPLEX(TYPE, NAME, ...)          \
  [&] {                                                                      \
    const at::Type& the_type = TYPE;                                         \
    switch (the_type.scalarType()) {                                         \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Byte, uint8_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Char, int8_t, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Double, double, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Float, float, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Int, int32_t, __VA_ARGS__)        \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Long, int64_t, __VA_ARGS__)       \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Short, int16_t, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(at::ScalarType::Half, at::Half, __VA_ARGS__)      \
      AT_PRIVATE_CASE_TYPE(                                                  \
          at::ScalarType::ComplexFloat, std::complex<float>, __VA_ARGS__)    \
      AT_PRIVATE_CASE_TYPE(                                                  \
          at::ScalarType::ComplexDouble, std::complex<double>, __VA_ARGS__)  \
      default:                                                               \
        AT_ERROR(#NAME, " not implemented for '", the_type.toString(), "'"); \
    }                                                                        \
  }()
