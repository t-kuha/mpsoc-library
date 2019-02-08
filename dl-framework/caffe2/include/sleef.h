//          Copyright Naoki Shibata 2010 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef __SLEEF_H__
#define __SLEEF_H__

#include <stddef.h>
#include <stdint.h>

#if (defined(__GNUC__) || defined(__CLANG__)) && !defined(__INTEL_COMPILER)
#define CONST const
#else
#define CONST
#endif

#if (defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(_MSC_VER)) && !defined(SLEEF_STATIC_LIBS)
#ifdef IMPORT_IS_EXPORT
#define IMPORT __declspec(dllexport)
#else // #ifdef IMPORT_IS_EXPORT
#define IMPORT __declspec(dllimport)
#if (defined(_MSC_VER))
#pragma comment(lib,"sleef.lib")
#endif // #if (defined(_MSC_VER))
#endif // #ifdef IMPORT_IS_EXPORT
#else // #if (defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(_MSC_VER)) && !defined(SLEEF_STATIC_LIBS)
#define IMPORT
#endif // #if (defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(_MSC_VER)) && !defined(SLEEF_STATIC_LIBS)

#if (defined(__GNUC__) || defined(__CLANG__)) && (defined(__i386__) || defined(__x86_64__))
#include <x86intrin.h>
#endif

#if (defined(_MSC_VER))
#include <intrin.h>
#endif

#if defined(__ARM_NEON__) || defined(__ARM_NEON)
#include <arm_neon.h>
#endif

#if defined(__ARM_FEATURE_SVE)
#include <arm_sve.h>
#endif

//

#ifndef SLEEF_FP_ILOGB0
#define SLEEF_FP_ILOGB0 ((int)-2147483648)
#endif

#ifndef SLEEF_FP_ILOGBNAN
#define SLEEF_FP_ILOGBNAN ((int)2147483647)
#endif

//

IMPORT void *Sleef_malloc(size_t z);
IMPORT void Sleef_free(void *ptr);
IMPORT uint64_t Sleef_currentTimeMicros();

#if defined(__i386__) || defined(__x86_64__) || defined(_MSC_VER)
IMPORT void Sleef_x86CpuID(int32_t out[4], uint32_t eax, uint32_t ecx);
#endif

//

#ifndef Sleef_double2_DEFINED
#define Sleef_double2_DEFINED
typedef struct {
  double x, y;
} Sleef_double2;
#endif

#ifndef Sleef_float2_DEFINED
#define Sleef_float2_DEFINED
typedef struct {
  float x, y;
} Sleef_float2;
#endif

#ifndef Sleef_longdouble2_DEFINED
#define Sleef_longdouble2_DEFINED
typedef struct {
  long double x, y;
} Sleef_longdouble2;
#endif

#if defined(ENABLEFLOAT128) && !defined(Sleef_quad2_DEFINED)
#define Sleef_quad2_DEFINED
typedef __float128 Sleef_quad;
typedef struct {
  __float128 x, y;
} Sleef_quad2;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

IMPORT CONST double Sleef_sin_u35(double);
IMPORT CONST double Sleef_cos_u35(double);
IMPORT CONST Sleef_double2 Sleef_sincos_u35(double);
IMPORT CONST double Sleef_tan_u35(double);
IMPORT CONST double Sleef_asin_u35(double);
IMPORT CONST double Sleef_acos_u35(double);
IMPORT CONST double Sleef_atan_u35(double);
IMPORT CONST double Sleef_atan2_u35(double, double);
IMPORT CONST double Sleef_log_u35(double);
IMPORT CONST double Sleef_cbrt_u35(double);
IMPORT CONST double Sleef_sin_u10(double);
IMPORT CONST double Sleef_cos_u10(double);
IMPORT CONST Sleef_double2 Sleef_sincos_u10(double);
IMPORT CONST double Sleef_tan_u10(double);
IMPORT CONST double Sleef_asin_u10(double);
IMPORT CONST double Sleef_acos_u10(double);
IMPORT CONST double Sleef_atan_u10(double);
IMPORT CONST double Sleef_atan2_u10(double, double);
IMPORT CONST double Sleef_log_u10(double);
IMPORT CONST double Sleef_cbrt_u10(double);
IMPORT CONST double Sleef_exp_u10(double);
IMPORT CONST double Sleef_pow_u10(double, double);
IMPORT CONST double Sleef_sinh_u10(double);
IMPORT CONST double Sleef_cosh_u10(double);
IMPORT CONST double Sleef_tanh_u10(double);
IMPORT CONST double Sleef_asinh_u10(double);
IMPORT CONST double Sleef_acosh_u10(double);
IMPORT CONST double Sleef_atanh_u10(double);
IMPORT CONST double Sleef_exp2_u10(double);
IMPORT CONST double Sleef_exp10_u10(double);
IMPORT CONST double Sleef_expm1_u10(double);
IMPORT CONST double Sleef_log10_u10(double);
IMPORT CONST double Sleef_log2_u10(double);
IMPORT CONST double Sleef_log1p_u10(double);
IMPORT CONST Sleef_double2 Sleef_sincospi_u05(double);
IMPORT CONST Sleef_double2 Sleef_sincospi_u35(double);
IMPORT CONST double Sleef_sinpi_u05(double);
IMPORT CONST double Sleef_cospi_u05(double);
IMPORT CONST double Sleef_ldexp(double, int);
IMPORT CONST int Sleef_ilogb(double);
IMPORT CONST double Sleef_fma(double, double, double);
IMPORT CONST double Sleef_sqrt(double);
IMPORT CONST double Sleef_sqrt_u05(double);
IMPORT CONST double Sleef_sqrt_u35(double);

IMPORT CONST double Sleef_hypot_u05(double, double);
IMPORT CONST double Sleef_hypot_u35(double, double);

IMPORT CONST double Sleef_fabs(double);
IMPORT CONST double Sleef_copysign(double, double);
IMPORT CONST double Sleef_fmax(double, double);
IMPORT CONST double Sleef_fmin(double, double);
IMPORT CONST double Sleef_fdim(double, double);
IMPORT CONST double Sleef_trunc(double);
IMPORT CONST double Sleef_floor(double);
IMPORT CONST double Sleef_ceil(double);
IMPORT CONST double Sleef_round(double);
IMPORT CONST double Sleef_rint(double);
IMPORT CONST double Sleef_nextafter(double, double);
IMPORT CONST double Sleef_frfrexp(double);
IMPORT CONST int Sleef_expfrexp(double);
IMPORT CONST double Sleef_fmod(double, double);
IMPORT CONST Sleef_double2 Sleef_modf(double);

IMPORT CONST double Sleef_lgamma_u10(double);
IMPORT CONST double Sleef_tgamma_u10(double);
IMPORT CONST double Sleef_erf_u10(double);
IMPORT CONST double Sleef_erfc_u15(double);

IMPORT CONST float Sleef_sinf_u35(float);
IMPORT CONST float Sleef_cosf_u35(float);
IMPORT CONST Sleef_float2 Sleef_sincosf_u35(float);
IMPORT CONST float Sleef_tanf_u35(float);
IMPORT CONST float Sleef_asinf_u35(float);
IMPORT CONST float Sleef_acosf_u35(float);
IMPORT CONST float Sleef_atanf_u35(float);
IMPORT CONST float Sleef_atan2f_u35(float, float);
IMPORT CONST float Sleef_logf_u35(float);
IMPORT CONST float Sleef_cbrtf_u35(float);
IMPORT CONST float Sleef_sinf_u10(float);
IMPORT CONST float Sleef_cosf_u10(float);
IMPORT CONST Sleef_float2 Sleef_sincosf_u10(float);
IMPORT CONST float Sleef_tanf_u10(float);
IMPORT CONST float Sleef_asinf_u10(float);
IMPORT CONST float Sleef_acosf_u10(float);
IMPORT CONST float Sleef_atanf_u10(float);
IMPORT CONST float Sleef_atan2f_u10(float, float);
IMPORT CONST float Sleef_logf_u10(float);
IMPORT CONST float Sleef_cbrtf_u10(float);
IMPORT CONST float Sleef_expf_u10(float);
IMPORT CONST float Sleef_powf_u10(float, float);
IMPORT CONST float Sleef_sinhf_u10(float);
IMPORT CONST float Sleef_coshf_u10(float);
IMPORT CONST float Sleef_tanhf_u10(float);
IMPORT CONST float Sleef_asinhf_u10(float);
IMPORT CONST float Sleef_acoshf_u10(float);
IMPORT CONST float Sleef_atanhf_u10(float);
IMPORT CONST float Sleef_exp2f_u10(float);
IMPORT CONST float Sleef_exp10f_u10(float);
IMPORT CONST float Sleef_expm1f_u10(float);
IMPORT CONST float Sleef_log10f_u10(float);
IMPORT CONST float Sleef_log2f_u10(float);
IMPORT CONST float Sleef_log1pf_u10(float);
IMPORT CONST Sleef_float2 Sleef_sincospif_u05(float);
IMPORT CONST Sleef_float2 Sleef_sincospif_u35(float);
IMPORT CONST float Sleef_sinpif_u05(float d);
IMPORT CONST float Sleef_cospif_u05(float d);
IMPORT CONST float Sleef_ldexpf(float, int);
IMPORT CONST int Sleef_ilogbf(float);
IMPORT CONST float Sleef_fmaf(float, float, float);
IMPORT CONST float Sleef_sqrtf(float);
IMPORT CONST float Sleef_sqrtf_u05(float);
IMPORT CONST float Sleef_sqrtf_u35(float);

IMPORT CONST float Sleef_hypotf_u05(float, float);
IMPORT CONST float Sleef_hypotf_u35(float, float);

IMPORT CONST float Sleef_fabsf(float);
IMPORT CONST float Sleef_copysignf(float, float);
IMPORT CONST float Sleef_fmaxf(float, float);
IMPORT CONST float Sleef_fminf(float, float);
IMPORT CONST float Sleef_fdimf(float, float);
IMPORT CONST float Sleef_truncf(float);
IMPORT CONST float Sleef_floorf(float);
IMPORT CONST float Sleef_ceilf(float);
IMPORT CONST float Sleef_roundf(float);
IMPORT CONST float Sleef_rintf(float);
IMPORT CONST float Sleef_nextafterf(float, float);
IMPORT CONST float Sleef_frfrexpf(float);
IMPORT CONST int Sleef_expfrexpf(float);
IMPORT CONST float Sleef_fmodf(float, float);
IMPORT CONST Sleef_float2 Sleef_modff(float);

IMPORT CONST float Sleef_lgammaf_u10(float);
IMPORT CONST float Sleef_tgammaf_u10(float);
IMPORT CONST float Sleef_erff_u10(float);
IMPORT CONST float Sleef_erfcf_u15(float);

IMPORT CONST Sleef_longdouble2 Sleef_sincospil_u05(long double);
IMPORT CONST Sleef_longdouble2 Sleef_sincospil_u35(long double);

#if defined(Sleef_quad2_DEFINED)
IMPORT CONST Sleef_quad2 Sleef_sincospiq_u05(Sleef_quad);
IMPORT CONST Sleef_quad2 Sleef_sincospiq_u35(Sleef_quad);
#endif
#ifdef __ARM_NEON
#define STRUCT_KEYWORD___ARM_NEON struct

#ifndef Sleef_float64x2_t_2_DEFINED
typedef STRUCT_KEYWORD___ARM_NEON {
  float64x2_t x, y;
} Sleef_float64x2_t_2;
#define Sleef_float64x2_t_2_DEFINED
#endif

IMPORT CONST float64x2_t Sleef_sind2_u35(float64x2_t);
IMPORT CONST float64x2_t Sleef_cosd2_u35(float64x2_t);
IMPORT CONST Sleef_float64x2_t_2 Sleef_sincosd2_u35(float64x2_t);
IMPORT CONST float64x2_t Sleef_tand2_u35(float64x2_t);
IMPORT CONST float64x2_t Sleef_asind2_u35(float64x2_t);
IMPORT CONST float64x2_t Sleef_acosd2_u35(float64x2_t);
IMPORT CONST float64x2_t Sleef_atand2_u35(float64x2_t);
IMPORT CONST float64x2_t Sleef_atan2d2_u35(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_logd2_u35(float64x2_t);
IMPORT CONST float64x2_t Sleef_cbrtd2_u35(float64x2_t);
IMPORT CONST float64x2_t Sleef_sind2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_cosd2_u10(float64x2_t);
IMPORT CONST Sleef_float64x2_t_2 Sleef_sincosd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_tand2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_asind2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_acosd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_atand2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_atan2d2_u10(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_logd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_cbrtd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_expd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_powd2_u10(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_sinhd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_coshd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_tanhd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_asinhd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_acoshd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_atanhd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_exp2d2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_exp10d2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_expm1d2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_log10d2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_log2d2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_log1pd2_u10(float64x2_t);
IMPORT CONST Sleef_float64x2_t_2 Sleef_sincospid2_u05(float64x2_t);
IMPORT CONST Sleef_float64x2_t_2 Sleef_sincospid2_u35(float64x2_t);
IMPORT CONST float64x2_t Sleef_sinpid2_u05(float64x2_t);
IMPORT CONST float64x2_t Sleef_cospid2_u05(float64x2_t);
IMPORT CONST float64x2_t Sleef_ldexpd2(float64x2_t, int32x2_t);
IMPORT CONST int32x2_t Sleef_ilogbd2(float64x2_t);
IMPORT CONST float64x2_t Sleef_fmad2(float64x2_t, float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_sqrtd2(float64x2_t);
IMPORT CONST float64x2_t Sleef_sqrtd2_u05(float64x2_t);
IMPORT CONST float64x2_t Sleef_sqrtd2_u35(float64x2_t);
IMPORT CONST float64x2_t Sleef_hypotd2_u05(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_hypotd2_u35(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_fabsd2(float64x2_t);
IMPORT CONST float64x2_t Sleef_copysignd2(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_fmaxd2(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_fmind2(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_fdimd2(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_truncd2(float64x2_t);
IMPORT CONST float64x2_t Sleef_floord2(float64x2_t);
IMPORT CONST float64x2_t Sleef_ceild2(float64x2_t);
IMPORT CONST float64x2_t Sleef_roundd2(float64x2_t);
IMPORT CONST float64x2_t Sleef_rintd2(float64x2_t);
IMPORT CONST float64x2_t Sleef_nextafterd2(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_frfrexpd2(float64x2_t);
IMPORT CONST int32x2_t Sleef_expfrexpd2(float64x2_t);
IMPORT CONST float64x2_t Sleef_fmodd2(float64x2_t, float64x2_t);
IMPORT CONST Sleef_float64x2_t_2 Sleef_modfd2(float64x2_t);
IMPORT CONST float64x2_t Sleef_lgammad2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_tgammad2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_erfd2_u10(float64x2_t);
IMPORT CONST float64x2_t Sleef_erfcd2_u15(float64x2_t);
IMPORT CONST int Sleef_getIntd2(int);
IMPORT CONST void *Sleef_getPtrd2(int);

#ifndef Sleef_float32x4_t_2_DEFINED
typedef STRUCT_KEYWORD___ARM_NEON {
  float32x4_t x, y;
} Sleef_float32x4_t_2;
#define Sleef_float32x4_t_2_DEFINED
#endif

IMPORT CONST float32x4_t Sleef_sinf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_cosf4_u35(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincosf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_acosf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_atan2f4_u35(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_logf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_cbrtf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_sinf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_cosf4_u10(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincosf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_acosf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_atan2f4_u10(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_logf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_cbrtf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_expf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_powf4_u10(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_sinhf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_coshf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanhf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinhf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_acoshf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanhf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_exp2f4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_exp10f4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_expm1f4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_log10f4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_log2f4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_log1pf4_u10(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincospif4_u05(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincospif4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_sinpif4_u05(float32x4_t);
IMPORT CONST float32x4_t Sleef_cospif4_u05(float32x4_t);
IMPORT CONST float32x4_t Sleef_fmaf4(float32x4_t, float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4_u05(float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_hypotf4_u05(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_hypotf4_u35(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fabsf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_copysignf4(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fmaxf4(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fminf4(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fdimf4(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_truncf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_floorf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_ceilf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_roundf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_rintf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_nextafterf4(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_frfrexpf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_fmodf4(float32x4_t, float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_modff4(float32x4_t);
IMPORT CONST float32x4_t Sleef_lgammaf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_tgammaf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_erff4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_erfcf4_u15(float32x4_t);
IMPORT CONST int Sleef_getIntf4(int);
IMPORT CONST void *Sleef_getPtrf4(int);
#endif
#ifdef __ARM_NEON
#define STRUCT_KEYWORD___ARM_NEON struct

#ifndef Sleef_float64x2_t_2_DEFINED
typedef STRUCT_KEYWORD___ARM_NEON {
  float64x2_t x, y;
} Sleef_float64x2_t_2;
#define Sleef_float64x2_t_2_DEFINED
#endif

IMPORT CONST float64x2_t Sleef_sind2_u35advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_cosd2_u35advsimd(float64x2_t);
IMPORT CONST Sleef_float64x2_t_2 Sleef_sincosd2_u35advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_tand2_u35advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_asind2_u35advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_acosd2_u35advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_atand2_u35advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_atan2d2_u35advsimd(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_logd2_u35advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_cbrtd2_u35advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_sind2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_cosd2_u10advsimd(float64x2_t);
IMPORT CONST Sleef_float64x2_t_2 Sleef_sincosd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_tand2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_asind2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_acosd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_atand2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_atan2d2_u10advsimd(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_logd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_cbrtd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_expd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_powd2_u10advsimd(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_sinhd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_coshd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_tanhd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_asinhd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_acoshd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_atanhd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_exp2d2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_exp10d2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_expm1d2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_log10d2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_log2d2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_log1pd2_u10advsimd(float64x2_t);
IMPORT CONST Sleef_float64x2_t_2 Sleef_sincospid2_u05advsimd(float64x2_t);
IMPORT CONST Sleef_float64x2_t_2 Sleef_sincospid2_u35advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_sinpid2_u05advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_cospid2_u05advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_ldexpd2_advsimd(float64x2_t, int32x2_t);
IMPORT CONST int32x2_t Sleef_ilogbd2_advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_fmad2_advsimd(float64x2_t, float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_sqrtd2_advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_sqrtd2_u05advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_sqrtd2_u35advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_hypotd2_u05advsimd(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_hypotd2_u35advsimd(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_fabsd2_advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_copysignd2_advsimd(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_fmaxd2_advsimd(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_fmind2_advsimd(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_fdimd2_advsimd(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_truncd2_advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_floord2_advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_ceild2_advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_roundd2_advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_rintd2_advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_nextafterd2_advsimd(float64x2_t, float64x2_t);
IMPORT CONST float64x2_t Sleef_frfrexpd2_advsimd(float64x2_t);
IMPORT CONST int32x2_t Sleef_expfrexpd2_advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_fmodd2_advsimd(float64x2_t, float64x2_t);
IMPORT CONST Sleef_float64x2_t_2 Sleef_modfd2_advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_lgammad2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_tgammad2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_erfd2_u10advsimd(float64x2_t);
IMPORT CONST float64x2_t Sleef_erfcd2_u15advsimd(float64x2_t);
IMPORT CONST int Sleef_getIntd2_advsimd(int);
IMPORT CONST void *Sleef_getPtrd2_advsimd(int);

#ifndef Sleef_float32x4_t_2_DEFINED
typedef STRUCT_KEYWORD___ARM_NEON {
  float32x4_t x, y;
} Sleef_float32x4_t_2;
#define Sleef_float32x4_t_2_DEFINED
#endif

IMPORT CONST float32x4_t Sleef_sinf4_u35advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_cosf4_u35advsimd(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincosf4_u35advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanf4_u35advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinf4_u35advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_acosf4_u35advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanf4_u35advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_atan2f4_u35advsimd(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_logf4_u35advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_cbrtf4_u35advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_sinf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_cosf4_u10advsimd(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincosf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_acosf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_atan2f4_u10advsimd(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_logf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_cbrtf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_expf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_powf4_u10advsimd(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_sinhf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_coshf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanhf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinhf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_acoshf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanhf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_exp2f4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_exp10f4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_expm1f4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_log10f4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_log2f4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_log1pf4_u10advsimd(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincospif4_u05advsimd(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincospif4_u35advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_sinpif4_u05advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_cospif4_u05advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_fmaf4_advsimd(float32x4_t, float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4_advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4_u05advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4_u35advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_hypotf4_u05advsimd(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_hypotf4_u35advsimd(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fabsf4_advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_copysignf4_advsimd(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fmaxf4_advsimd(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fminf4_advsimd(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fdimf4_advsimd(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_truncf4_advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_floorf4_advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_ceilf4_advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_roundf4_advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_rintf4_advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_nextafterf4_advsimd(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_frfrexpf4_advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_fmodf4_advsimd(float32x4_t, float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_modff4_advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_lgammaf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_tgammaf4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_erff4_u10advsimd(float32x4_t);
IMPORT CONST float32x4_t Sleef_erfcf4_u15advsimd(float32x4_t);
IMPORT CONST int Sleef_getIntf4_advsimd(int);
IMPORT CONST void *Sleef_getPtrf4_advsimd(int);
#endif
#ifdef __ARM_FEATURE_SVE
#define STRUCT_KEYWORD___ARM_FEATURE_SVE __sizeless_struct

#ifndef Sleef_svfloat64_t_2_DEFINED
typedef STRUCT_KEYWORD___ARM_FEATURE_SVE {
  svfloat64_t x, y;
} Sleef_svfloat64_t_2;
#define Sleef_svfloat64_t_2_DEFINED
#endif

IMPORT CONST svfloat64_t Sleef_sindx_u35sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_cosdx_u35sve(svfloat64_t);
IMPORT CONST Sleef_svfloat64_t_2 Sleef_sincosdx_u35sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_tandx_u35sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_asindx_u35sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_acosdx_u35sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_atandx_u35sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_atan2dx_u35sve(svfloat64_t, svfloat64_t);
IMPORT CONST svfloat64_t Sleef_logdx_u35sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_cbrtdx_u35sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_sindx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_cosdx_u10sve(svfloat64_t);
IMPORT CONST Sleef_svfloat64_t_2 Sleef_sincosdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_tandx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_asindx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_acosdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_atandx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_atan2dx_u10sve(svfloat64_t, svfloat64_t);
IMPORT CONST svfloat64_t Sleef_logdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_cbrtdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_expdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_powdx_u10sve(svfloat64_t, svfloat64_t);
IMPORT CONST svfloat64_t Sleef_sinhdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_coshdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_tanhdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_asinhdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_acoshdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_atanhdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_exp2dx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_exp10dx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_expm1dx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_log10dx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_log2dx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_log1pdx_u10sve(svfloat64_t);
IMPORT CONST Sleef_svfloat64_t_2 Sleef_sincospidx_u05sve(svfloat64_t);
IMPORT CONST Sleef_svfloat64_t_2 Sleef_sincospidx_u35sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_sinpidx_u05sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_cospidx_u05sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_ldexpdx_sve(svfloat64_t, svint32_t);
IMPORT CONST svint32_t Sleef_ilogbdx_sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_fmadx_sve(svfloat64_t, svfloat64_t, svfloat64_t);
IMPORT CONST svfloat64_t Sleef_sqrtdx_sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_sqrtdx_u05sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_sqrtdx_u35sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_hypotdx_u05sve(svfloat64_t, svfloat64_t);
IMPORT CONST svfloat64_t Sleef_hypotdx_u35sve(svfloat64_t, svfloat64_t);
IMPORT CONST svfloat64_t Sleef_fabsdx_sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_copysigndx_sve(svfloat64_t, svfloat64_t);
IMPORT CONST svfloat64_t Sleef_fmaxdx_sve(svfloat64_t, svfloat64_t);
IMPORT CONST svfloat64_t Sleef_fmindx_sve(svfloat64_t, svfloat64_t);
IMPORT CONST svfloat64_t Sleef_fdimdx_sve(svfloat64_t, svfloat64_t);
IMPORT CONST svfloat64_t Sleef_truncdx_sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_floordx_sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_ceildx_sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_rounddx_sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_rintdx_sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_nextafterdx_sve(svfloat64_t, svfloat64_t);
IMPORT CONST svfloat64_t Sleef_frfrexpdx_sve(svfloat64_t);
IMPORT CONST svint32_t Sleef_expfrexpdx_sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_fmoddx_sve(svfloat64_t, svfloat64_t);
IMPORT CONST Sleef_svfloat64_t_2 Sleef_modfdx_sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_lgammadx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_tgammadx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_erfdx_u10sve(svfloat64_t);
IMPORT CONST svfloat64_t Sleef_erfcdx_u15sve(svfloat64_t);
IMPORT CONST int Sleef_getIntdx_sve(int);
IMPORT CONST void *Sleef_getPtrdx_sve(int);

#ifndef Sleef_svfloat32_t_2_DEFINED
typedef STRUCT_KEYWORD___ARM_FEATURE_SVE {
  svfloat32_t x, y;
} Sleef_svfloat32_t_2;
#define Sleef_svfloat32_t_2_DEFINED
#endif

IMPORT CONST svfloat32_t Sleef_sinfx_u35sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_cosfx_u35sve(svfloat32_t);
IMPORT CONST Sleef_svfloat32_t_2 Sleef_sincosfx_u35sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_tanfx_u35sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_asinfx_u35sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_acosfx_u35sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_atanfx_u35sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_atan2fx_u35sve(svfloat32_t, svfloat32_t);
IMPORT CONST svfloat32_t Sleef_logfx_u35sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_cbrtfx_u35sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_sinfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_cosfx_u10sve(svfloat32_t);
IMPORT CONST Sleef_svfloat32_t_2 Sleef_sincosfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_tanfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_asinfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_acosfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_atanfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_atan2fx_u10sve(svfloat32_t, svfloat32_t);
IMPORT CONST svfloat32_t Sleef_logfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_cbrtfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_expfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_powfx_u10sve(svfloat32_t, svfloat32_t);
IMPORT CONST svfloat32_t Sleef_sinhfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_coshfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_tanhfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_asinhfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_acoshfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_atanhfx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_exp2fx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_exp10fx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_expm1fx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_log10fx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_log2fx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_log1pfx_u10sve(svfloat32_t);
IMPORT CONST Sleef_svfloat32_t_2 Sleef_sincospifx_u05sve(svfloat32_t);
IMPORT CONST Sleef_svfloat32_t_2 Sleef_sincospifx_u35sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_sinpifx_u05sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_cospifx_u05sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_fmafx_sve(svfloat32_t, svfloat32_t, svfloat32_t);
IMPORT CONST svfloat32_t Sleef_sqrtfx_sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_sqrtfx_u05sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_sqrtfx_u35sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_hypotfx_u05sve(svfloat32_t, svfloat32_t);
IMPORT CONST svfloat32_t Sleef_hypotfx_u35sve(svfloat32_t, svfloat32_t);
IMPORT CONST svfloat32_t Sleef_fabsfx_sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_copysignfx_sve(svfloat32_t, svfloat32_t);
IMPORT CONST svfloat32_t Sleef_fmaxfx_sve(svfloat32_t, svfloat32_t);
IMPORT CONST svfloat32_t Sleef_fminfx_sve(svfloat32_t, svfloat32_t);
IMPORT CONST svfloat32_t Sleef_fdimfx_sve(svfloat32_t, svfloat32_t);
IMPORT CONST svfloat32_t Sleef_truncfx_sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_floorfx_sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_ceilfx_sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_roundfx_sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_rintfx_sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_nextafterfx_sve(svfloat32_t, svfloat32_t);
IMPORT CONST svfloat32_t Sleef_frfrexpfx_sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_fmodfx_sve(svfloat32_t, svfloat32_t);
IMPORT CONST Sleef_svfloat32_t_2 Sleef_modffx_sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_lgammafx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_tgammafx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_erffx_u10sve(svfloat32_t);
IMPORT CONST svfloat32_t Sleef_erfcfx_u15sve(svfloat32_t);
IMPORT CONST int Sleef_getIntfx_sve(int);
IMPORT CONST void *Sleef_getPtrfx_sve(int);
#endif
#ifdef __cplusplus
}
#endif

#undef IMPORT
#endif // #ifndef __SLEEF_H__
