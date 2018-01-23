#ifndef TH_AVX2_H
#define TH_AVX2_H

#include <stddef.h>
#include "General.h"

void THDoubleVector_cadd_AVX2(double *z, const double *x, const double *y, const double c, const ptrdiff_t n);
void THFloatVector_cadd_AVX2(float *z, const float *x, const float *y, const float c, const ptrdiff_t n);

void THZDoubleVector_cdiv_AVX2(double _Complex *z, const double _Complex *x, const double _Complex *y, const ptrdiff_t n);
void THZDoubleVector_divs_AVX2(double _Complex *y, const double _Complex *x, const double _Complex c, const ptrdiff_t n);
void THZDoubleVector_cmul_AVX2(double _Complex *z, const double _Complex *x, const double _Complex *y, const ptrdiff_t n);
void THZDoubleVector_muls_AVX2(double _Complex *y, const double _Complex *x, const double _Complex c, const ptrdiff_t n);
void THZDoubleVector_cadd_AVX2(double _Complex *z, const double _Complex *x, const double _Complex *y, const double _Complex c, const ptrdiff_t n);

void THZFloatVector_cdiv_AVX2(float _Complex *z, const float _Complex *x, const float _Complex *y, const ptrdiff_t n);
void THZFloatVector_divs_AVX2(float _Complex *y, const float _Complex *x, const float _Complex c, const ptrdiff_t n);
void THZFloatVector_cmul_AVX2(float _Complex *z, const float _Complex *x, const float _Complex *y, const ptrdiff_t n);
void THZFloatVector_muls_AVX2(float _Complex *y, const float _Complex *x, const float _Complex c, const ptrdiff_t n);
void THZFloatVector_cadd_AVX2(float _Complex *z, const float _Complex *x, const float _Complex *y, const float _Complex c, const ptrdiff_t n);

#endif
