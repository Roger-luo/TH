#ifndef TH_AVX_H
#define TH_AVX_H

#include <stddef.h>
#include "General.h"

void THDoubleVector_copy_AVX(double *y, const double *x, const ptrdiff_t n);
void THDoubleVector_fill_AVX(double *x, const double c, const ptrdiff_t n);
void THDoubleVector_cdiv_AVX(double *z, const double *x, const double *y, const ptrdiff_t n);
void THDoubleVector_divs_AVX(double *y, const double *x, const double c, const ptrdiff_t n);
void THDoubleVector_cmul_AVX(double *z, const double *x, const double *y, const ptrdiff_t n);
void THDoubleVector_muls_AVX(double *y, const double *x, const double c, const ptrdiff_t n);
void THDoubleVector_cadd_AVX(double *z, const double *x, const double *y, const double c, const ptrdiff_t n);
void THDoubleVector_adds_AVX(double *y, const double *x, const double c, const ptrdiff_t n);
void THFloatVector_copy_AVX(float *y, const float *x, const ptrdiff_t n);
void THFloatVector_fill_AVX(float *x, const float c, const ptrdiff_t n);
void THFloatVector_cdiv_AVX(float *z, const float *x, const float *y, const ptrdiff_t n);
void THFloatVector_divs_AVX(float *y, const float *x, const float c, const ptrdiff_t n);
void THFloatVector_cmul_AVX(float *z, const float *x, const float *y, const ptrdiff_t n);
void THFloatVector_muls_AVX(float *y, const float *x, const float c, const ptrdiff_t n);
void THFloatVector_cadd_AVX(float *z, const float *x, const float *y, const float c, const ptrdiff_t n);
void THFloatVector_adds_AVX(float *y, const float *x, const float c, const ptrdiff_t n);

// complex

void THZDoubleVector_copy_AVX(double _Complex *y, const double _Complex *x, const ptrdiff_t n);
void THZDoubleVector_fill_AVX(double _Complex *z, const double _Complex c, const ptrdiff_t n);
void THZDoubleVector_adds_AVX(double _Complex *y, const double _Complex *x, const double _Complex c, const ptrdiff_t n);

void THZFloatVector_copy_AVX(float _Complex *y, const float _Complex *x, const ptrdiff_t n);
void THZFloatVector_fill_AVX(float _Complex *z, const float _Complex c, const ptrdiff_t n);
void THZFloatVector_adds_AVX(float _Complex *y, const float _Complex *x, const float _Complex c, const ptrdiff_t n);

#endif
