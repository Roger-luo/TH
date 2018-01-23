#if defined(__AVX__)
#ifndef _MSC_VER
#include <x86intrin.h>
#else
#include <intrin.h>
#endif

#include "AVX.h"

void THDoubleVector_copy_AVX(double *y, const double *x, const ptrdiff_t n) {
  ptrdiff_t i;
  ptrdiff_t off;
  for (i=0; i<=((n)-8); i+=8) {
    _mm256_storeu_pd(y+i, _mm256_loadu_pd(x+i));
    _mm256_storeu_pd(y+i+4, _mm256_loadu_pd(x+i+4));
  }
  off = (n) - ((n)%8);
  for (i=0; i<((n)%8); i++) {
    y[off+i] = x[off+i];
  }
}

void THDoubleVector_fill_AVX(double *x, const double c, const ptrdiff_t n) {
  ptrdiff_t i;
  ptrdiff_t off;
  __m256d YMM0 = _mm256_set_pd(c, c, c, c);
  for (i=0; i<=((n)-16); i+=16) {
    _mm256_storeu_pd((x)+i  , YMM0);
    _mm256_storeu_pd((x)+i+4, YMM0);
    _mm256_storeu_pd((x)+i+8, YMM0);
    _mm256_storeu_pd((x)+i+12, YMM0);
  }
  off = (n) - ((n)%16);
  for (i=0; i<((n)%16); i++) {
    x[off+i] = c;
  }
}

void THDoubleVector_cdiv_AVX(double *z, const double *x, const double *y, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256d YMM0, YMM1, YMM2, YMM3;
  for (i=0; i<=((n)-8); i+=8) {
    YMM0 = _mm256_loadu_pd(x+i);
    YMM1 = _mm256_loadu_pd(x+i+4);
    YMM2 = _mm256_loadu_pd(y+i);
    YMM3 = _mm256_loadu_pd(y+i+4);
    YMM2 = _mm256_div_pd(YMM0, YMM2);
    YMM3 = _mm256_div_pd(YMM1, YMM3);
    _mm256_storeu_pd(z+i, YMM2);
    _mm256_storeu_pd(z+i+4, YMM3);
  }
  for (; i<(n); i++) {
    z[i] = x[i] / y[i];
  }
}

void THDoubleVector_divs_AVX(double *y, const double *x, const double c, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256d YMM15 = _mm256_set_pd(c, c, c, c);
  __m256d YMM0, YMM1;
  for (i=0; i<=((n)-8); i+=8) {
    YMM0 = _mm256_loadu_pd(x+i);
    YMM1 = _mm256_loadu_pd(x+i+4);
    YMM0 = _mm256_div_pd(YMM0, YMM15);
    YMM1 = _mm256_div_pd(YMM1, YMM15);
    _mm256_storeu_pd(y+i, YMM0);
    _mm256_storeu_pd(y+i+4, YMM1);
  }
  for (; i<(n); i++) {
    y[i] = x[i] / c;
  }
}

void THDoubleVector_cmul_AVX(double *z, const double *x, const double *y, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256d YMM0, YMM1, YMM2, YMM3;
  for (i=0; i<=((n)-8); i+=8) {
    YMM0 = _mm256_loadu_pd(x+i);
    YMM1 = _mm256_loadu_pd(x+i+4);
    YMM2 = _mm256_loadu_pd(y+i);
    YMM3 = _mm256_loadu_pd(y+i+4);
    YMM2 = _mm256_mul_pd(YMM0, YMM2);
    YMM3 = _mm256_mul_pd(YMM1, YMM3);
    _mm256_storeu_pd(z+i, YMM2);
    _mm256_storeu_pd(z+i+4, YMM3);
  }
  for (; i<n; i++) {
    z[i] = x[i] * y[i];
  }
}

void THDoubleVector_muls_AVX(double *y, const double *x, const double c, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256d YMM15 = _mm256_set_pd(c, c, c, c);
  __m256d YMM0, YMM1;
  for (i=0; i<=((n)-8); i+=8) {
    YMM0 = _mm256_loadu_pd(x+i);
    YMM1 = _mm256_loadu_pd(x+i+4);
    YMM0 = _mm256_mul_pd(YMM0, YMM15);
    YMM1 = _mm256_mul_pd(YMM1, YMM15);
    _mm256_storeu_pd(y+i, YMM0);
    _mm256_storeu_pd(y+i+4, YMM1);
  }
  for (; i<n; i++) {
    y[i] = x[i] * c;
  }
}

void THDoubleVector_cadd_AVX(double *z, const double *x, const double *y, const double c, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256d YMM15 = _mm256_set_pd(c, c, c, c);
  __m256d YMM0, YMM1, YMM2, YMM3;
  for (i=0; i<=((n)-4); i+=4) {
    YMM0 = _mm256_loadu_pd(y+i);
    YMM1 = _mm256_loadu_pd(x+i);
    YMM2 = _mm256_mul_pd(YMM0, YMM15);
    YMM3 = _mm256_add_pd(YMM1, YMM2);
    _mm256_storeu_pd(z+i, YMM3);
  }
  for (; i<(n); i++) {
    z[i] = x[i] + y[i] * c;
  }
}

void THDoubleVector_adds_AVX(double *y, const double *x, const double c, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256d YMM15 = _mm256_set_pd(c, c, c, c);
  __m256d YMM0, YMM1;
  for (i=0; i<=((n)-8); i+=8) {
    YMM0 = _mm256_loadu_pd(x+i);
    YMM1 = _mm256_loadu_pd(x+i+4);
    YMM0 = _mm256_add_pd(YMM0, YMM15);
    YMM1 = _mm256_add_pd(YMM1, YMM15);
    _mm256_storeu_pd(y+i, YMM0);
    _mm256_storeu_pd(y+i+4, YMM1);
  }
  for (; i<(n); i++) {
    y[i] = x[i] + c;
  }
}

void THFloatVector_copy_AVX(float *y, const float *x, const ptrdiff_t n) {
  ptrdiff_t i;
  ptrdiff_t off;
  for (i=0; i<=((n)-16); i+=16) {
    _mm256_storeu_ps(y+i, _mm256_loadu_ps(x+i));
    _mm256_storeu_ps(y+i+8, _mm256_loadu_ps(x+i+8));
  }
  off = (n) - ((n)%16);
  for (i=0; i<((n)%16); i++) {
    y[off+i] = x[off+i];
  }
}

void THFloatVector_fill_AVX(float *x, const float c, const ptrdiff_t n) {
  ptrdiff_t i;
  ptrdiff_t off;
  __m256 YMM0 = _mm256_set_ps(c, c, c, c, c, c, c, c);
  for (i=0; i<=((n)-32); i+=32) {
    _mm256_storeu_ps((x)+i  , YMM0);
    _mm256_storeu_ps((x)+i+8, YMM0);
    _mm256_storeu_ps((x)+i+16, YMM0);
    _mm256_storeu_ps((x)+i+24, YMM0);
  }
  off = (n) - ((n)%32);
  for (i=0; i<((n)%32); i++) {
    x[off+i] = c;
  }
}

void THFloatVector_cdiv_AVX(float *z, const float *x, const float *y, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256 YMM0, YMM1, YMM2, YMM3;
  for (i=0; i<=((n)-16); i+=16) {
    YMM0 = _mm256_loadu_ps(x+i);
    YMM1 = _mm256_loadu_ps(x+i+8);
    YMM2 = _mm256_loadu_ps(y+i);
    YMM3 = _mm256_loadu_ps(y+i+8);
    YMM2 = _mm256_div_ps(YMM0, YMM2);
    YMM3 = _mm256_div_ps(YMM1, YMM3);
    _mm256_storeu_ps(z+i, YMM2);
    _mm256_storeu_ps(z+i+8, YMM3);
  }
  for (; i<(n); i++) {
    z[i] = x[i] / y[i];
  }
}

void THFloatVector_divs_AVX(float *y, const float *x, const float c, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256 YMM15 = _mm256_set_ps(c, c, c, c, c, c, c, c);
  __m256 YMM0, YMM1;
  for (i=0; i<=((n)-16); i+=16) {
    YMM0 = _mm256_loadu_ps(x+i);
    YMM1 = _mm256_loadu_ps(x+i+8);
    YMM0 = _mm256_div_ps(YMM0, YMM15);
    YMM1 = _mm256_div_ps(YMM1, YMM15);
    _mm256_storeu_ps(y+i, YMM0);
    _mm256_storeu_ps(y+i+8, YMM1);
  }
  for (; i<(n); i++) {
    y[i] = x[i] / c;
  }
}

void THFloatVector_cmul_AVX(float *z, const float *x, const float *y, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256 YMM0, YMM1, YMM2, YMM3;
  for (i=0; i<=((n)-16); i+=16) {
    YMM0 = _mm256_loadu_ps(x+i);
    YMM1 = _mm256_loadu_ps(x+i+8);
    YMM2 = _mm256_loadu_ps(y+i);
    YMM3 = _mm256_loadu_ps(y+i+8);
    YMM2 = _mm256_mul_ps(YMM0, YMM2);
    YMM3 = _mm256_mul_ps(YMM1, YMM3);
    _mm256_storeu_ps(z+i, YMM2);
    _mm256_storeu_ps(z+i+8, YMM3);
  }
  for (; i<n; i++) {
    z[i] = x[i] * y[i];
  }
}

void THFloatVector_muls_AVX(float *y, const float *x, const float c, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256 YMM15 = _mm256_set_ps(c, c, c, c, c, c, c, c);
  __m256 YMM0, YMM1;
  for (i=0; i<=((n)-16); i+=16) {
    YMM0 = _mm256_loadu_ps(x+i);
    YMM1 = _mm256_loadu_ps(x+i+8);
    YMM0 = _mm256_mul_ps(YMM0, YMM15);
    YMM1 = _mm256_mul_ps(YMM1, YMM15);
    _mm256_storeu_ps(y+i, YMM0);
    _mm256_storeu_ps(y+i+8, YMM1);
  }
  for (; i<n; i++) {
    y[i] = x[i] * c;
  }
}

void THFloatVector_cadd_AVX(float *z, const float *x, const float *y, const float c, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256 YMM15 = _mm256_set_ps(c, c, c, c, c, c, c, c);
  __m256 YMM0, YMM1, YMM2, YMM3;
  for (i=0; i<=((n)-8); i+=8) {
    YMM0 = _mm256_loadu_ps(y+i);
    YMM1 = _mm256_loadu_ps(x+i);
    YMM2 = _mm256_mul_ps(YMM0, YMM15);
    YMM3 = _mm256_add_ps(YMM1, YMM2);
    _mm256_storeu_ps(z+i, YMM3);
  }
  for (; i<(n); i++) {
    z[i] = x[i] + y[i] * c;
  }
}

void THFloatVector_adds_AVX(float *y, const float *x, const float c, const ptrdiff_t n) {
  ptrdiff_t i;
  __m256 YMM15 = _mm256_set_ps(c, c, c, c, c, c, c, c);
  __m256 YMM0, YMM1;
  for (i=0; i<=((n)-16); i+=16) {
    YMM0 = _mm256_loadu_ps(x+i);
    YMM1 = _mm256_loadu_ps(x+i+8);
    YMM0 = _mm256_add_ps(YMM0, YMM15);
    YMM1 = _mm256_add_ps(YMM1, YMM15);
    _mm256_storeu_ps(y+i, YMM0);
    _mm256_storeu_ps(y+i+8, YMM1);
  }
  for (; i<(n); i++) {
    y[i] = x[i] + c;
  }
}

// complex128

/**
 * complex avx is implemented as a array with
 * twice length of related floating
 * point type array. e.g.
 *
 * double _Complex x[16];
 *
 * is equivalent on size to
 *
 * double x_[32];
 *
 * then we will be able to use simd instrincts.
 */

void THZDoubleVector_copy_AVX(double _Complex *y, const double _Complex *x, const ptrdiff_t n) {
  ptrdiff_t i;
  ptrdiff_t off;

  double *my = (double *)y;
  double *mx = (double *)x;
  ptrdiff_t mn = 2 * n;

  for(i=0;i<=((mn)-8);i+=8) {
    _mm256_storeu_pd(my+i, _mm256_loadu_pd(mx+i));
    _mm256_storeu_pd(my+i+4, _mm256_loadu_pd(mx+i+4));
  }
  off = (mn) - ((mn)%8);
  for(i=0; i<((n)%8); i++) {
    y[off+i] = x[off+i];
  }
}

void THZDoubleVector_fill_AVX(double _Complex *z, const double _Complex c, const ptrdiff_t n) {
  ptrdiff_t i;
  ptrdiff_t off;
  double *x = (double *)z;
  ptrdiff_t len = 2 * n;
  __m256d YMM0 = _mm256_set_pd(
    cimag(c), creal(c), cimag(c), creal(c));
  for(i=0;i<=((len)-16); i+=16) {
    _mm256_storeu_pd((x)+i, YMM0);
    _mm256_storeu_pd((x)+i+4, YMM0);
    _mm256_storeu_pd((x)+i+8, YMM0);
    _mm256_storeu_pd((x)+i+12, YMM0);
  }
  off = (len) - ((len)%16);
  for(i=0; i<((len)&16); i++) {
    x[off+i] = c;
  }
}

void THZDoubleVector_adds_AVX(double _Complex *y, const double _Complex *x, const double _Complex c, const ptrdiff_t n) {
  ptrdiff_t i, off;
  ptrdiff_t len = 2 * n;

  double *mx = (double *)x;
  double *my = (double *)y;
  __m256d YMM15 = COMPLEX128_TO_M256D(creal(c), cimag(c));
  __m256d YMM0, YMM1;
  for(i=0;i<=((len)-8);i+=8) {
    YMM0 = _mm256_loadu_pd(mx+i);
    YMM1 = _mm256_loadu_pd(mx+i+4);
    YMM0 = _mm256_add_pd(YMM0, YMM15);
    YMM1 = _mm256_add_pd(YMM1, YMM15);
    _mm256_storeu_pd(my+i, YMM0);
    _mm256_storeu_pd(my+i+4, YMM1);
  }
  off = (n) - ((n)%4);
  for (i=0; i<((n)%4); i++) {
    y[off+i] = x[off+i] + c;
  }
}

void THZFloatVector_copy_AVX(float _Complex *y, const float _Complex *x, const ptrdiff_t n) {
  ptrdiff_t i;
  ptrdiff_t off;

  float *my = (float *)y;
  float *mx = (float *)x;
  ptrdiff_t mn = 2 * n;

  for (i=0; i<=((mn)-16); i+=16) {
    _mm256_storeu_ps(my+i, _mm256_loadu_ps(mx+i));
    _mm256_storeu_ps(my+i+8, _mm256_loadu_ps(mx+i+8));
  }
  off = (mn) - ((mn)%16);
  for (i=0; i<((mn)%16); i++) {
    y[off+i] = x[off+i];
  }
}

void THZFloatVector_fill_AVX(float _Complex *z, const float _Complex c, const ptrdiff_t n) {
  ptrdiff_t i;
  ptrdiff_t off;
  __m256 YMM0 = _mm256_set_ps(
                  cimag(c), creal(c),
                  cimag(c), creal(c),
                  cimag(c), creal(c),
                  cimag(c), creal(c));
  float *x = (float *)z;
  ptrdiff_t len = 2 * n;

  for (i=0; i<=((len)-32); i+=32) {
    _mm256_storeu_ps((x)+i  , YMM0);
    _mm256_storeu_ps((x)+i+8, YMM0);
    _mm256_storeu_ps((x)+i+16, YMM0);
    _mm256_storeu_ps((x)+i+24, YMM0);
  }
  off = (len) - ((len)%32);
  for (i=0; i<((len)%32); i++) {
    x[off+i] = c;
  }
}

void THZFloatVector_adds_AVX(float _Complex *y, const float _Complex *x, const float _Complex c, const ptrdiff_t n) {
  ptrdiff_t i, off;
  ptrdiff_t len = 2 * n;

  float *mx = (float *)x;
  float *my = (float *)y;
  __m256 YMM15 = COMPLEX64_TO_M256(crealf(c), cimagf(c));
  __m256 YMM0, YMM1;
  for(i=0;i<=((len)-16);i+=16) {
    YMM0 = _mm256_loadu_ps(mx+i);
    YMM1 = _mm256_loadu_ps(mx+i+8);
    YMM0 = _mm256_add_ps(YMM0, YMM15);
    YMM1 = _mm256_add_ps(YMM1, YMM15);
    _mm256_storeu_ps(my+i, YMM0);
    _mm256_storeu_ps(my+i+8, YMM1);
  }
  off = (n) - ((n)%8);
  for (i=0; i<((n)%8); i++) {
    y[off+i] = x[off+i] + c;
  }
}

#endif // defined(__AVX__)
