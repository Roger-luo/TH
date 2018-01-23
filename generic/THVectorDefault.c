#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/THVectorDefault.c"
#else

#include "THTypeMacros.h"

void THVector_(copy_DEFAULT)(ntype *x, const ntype *y, const ptrdiff_t n) {
  ptrdiff_t i = 0;

  for(; i <n-4; i+=4)
  {
    x[i] = y[i];
    x[i+1] = y[i+1];
    x[i+2] = y[i+2];
    x[i+3] = y[i+3];
  }

  for(; i < n; i++)
    x[i] = y[i];
}

void THVector_(fill_DEFAULT)(ntype *x, const ntype c, const ptrdiff_t n) {
  ptrdiff_t i = 0;

  for(; i <n-4; i+=4)
  {
    x[i] = c;
    x[i+1] = c;
    x[i+2] = c;
    x[i+3] = c;
  }

  for(; i < n; i++)
    x[i] = c;
}

void THVector_(cadd_DEFAULT)(ntype *z, const ntype *x, const ntype *y, const ntype c, const ptrdiff_t n)
{
  ptrdiff_t i = 0;

  for(; i<n-4; i+=4)
  {
    z[i] = x[i] + c * y[i];
    z[i+1] = x[i+1] + c * y[i+1];
    z[i+2] = x[i+2] + c * y[i+2];
    z[i+3] = x[i+3] + c * y[i+3];
  }

  for(; i<n; i++)
    z[i] = x[i] + c * y[i];
}

void THVector_(adds_DEFAULT)(ntype *y, const ntype *x, const ntype c, const ptrdiff_t n)
{
  ptrdiff_t i = 0;

  for(; i<n-4; i+=4)
  {
    y[i] = x[i] + c;
    y[i+1] = x[i+1] + c;
    y[i+2] = x[i+2] + c;
    y[i+3] = x[i+3] + c;
  }

  for(; i<n; i++)
    y[i] = x[i] + c;
}

void THVector_(cmul_DEFAULT)(ntype *z, const ntype *x, const ntype *y, const ptrdiff_t n)
{
  ptrdiff_t i = 0;

  for(; i <n-4; i+=4)
  {
    z[i] = x[i] * y[i];
    z[i+1] = x[i+1] * y[i+1];
    z[i+2] = x[i+2] * y[i+2];
    z[i+3] = x[i+3] * y[i+3];
  }

  for(; i < n; i++)
    z[i] = x[i] * y[i];
}

void THVector_(muls_DEFAULT)(ntype *y, const ntype *x, const ntype c, const ptrdiff_t n)
{
  ptrdiff_t i = 0;

  for(; i <n-4; i+=4)
  {
    y[i] = x[i] * c;
    y[i+1] = x[i+1] * c;
    y[i+2] = x[i+2] * c;
    y[i+3] = x[i+3] * c;
  }

  for(; i < n; i++)
    y[i] = x[i] * c;
}

void THVector_(cdiv_DEFAULT)(ntype *z, const ntype *x, const ntype *y, const ptrdiff_t n)
{
  ptrdiff_t i = 0;

  for(; i<n-4; i+=4)
  {
    z[i] = x[i] / y[i];
    z[i+1] = x[i+1] / y[i+1];
    z[i+2] = x[i+2] / y[i+2];
    z[i+3] = x[i+3] / y[i+3];
  }

  for(; i < n; i++)
    z[i] = x[i] / y[i];
}

void THVector_(divs_DEFAULT)(ntype *y, const ntype *x, const ntype c, const ptrdiff_t n)
{
  ptrdiff_t i = 0;

  for(; i<n-4; i+=4)
  {
    y[i] = x[i] / c;
    y[i+1] = x[i+1] / c;
    y[i+2] = x[i+2] / c;
    y[i+3] = x[i+3] / c;
  }

  for(; i < n; i++)
    y[i] = x[i] / c;
}

#define VECTOR_IMPLEMENT_FUNCTION(NAME, CFUNC)  \
  void THVector_(NAME)(ntype *y, const ntype *x, const ptrdiff_t n) \
  { \
    ptrdiff_t i = 0;  \
    for(; i<n-4; i+=4)  \
    { \
      y[i] = CFUNC(x[i]); \
      y[i+1] = CFUNC(x[i+1]); \
      y[i+2] = CFUNC(x[i+2]); \
      y[i+3] = CFUNC(x[i+3]); \
    } \
    for(; i < n; i++) \
      y[i] = CFUNC(x[i]); \
  } \

#define VECTOR_IMPLEMENT_FUNCTION_PART(NAME, CFUNC)  \
  void THVector_(NAME)(part *y, const ntype *x, const ptrdiff_t n) \
  { \
    ptrdiff_t i = 0;  \
    for(; i<n-4; i+=4)  \
    { \
      y[i] = CFUNC(x[i]); \
      y[i+1] = CFUNC(x[i+1]); \
      y[i+2] = CFUNC(x[i+2]); \
      y[i+3] = CFUNC(x[i+3]); \
    } \
    for(; i < n; i++) \
      y[i] = CFUNC(x[i]); \
  } \

#define VECTOR_IMPLEMENT_FUNCTION_VALUE(NAME, CFUNC)  \
  void THVector_(NAME)(ntype *y, const ntype *x, const ntype c, const ptrdiff_t n) \
  { \
    ptrdiff_t i = 0;  \
    for(; i<n-4; i+=4)  \
    { \
      y[i] = CFUNC(x[i], c);  \
      y[i+1] = CFUNC(x[i+1], c);  \
      y[i+2] = CFUNC(x[i+2], c);  \
      y[i+3] = CFUNC(x[i+3], c);  \
    } \
    for(; i < n; i++) \
      y[i] = CFUNC(x[i], c);  \
  } \

#if defined(TH_NTYPE_IS_LONG)
VECTOR_IMPLEMENT_FUNCTION(abs,labs)
#endif /* long only part */

#if defined(TH_NTYPE_IS_SHORT) || defined(TH_NTYPE_IS_INT)
VECTOR_IMPLEMENT_FUNCTION(abs,abs)
#endif /* int only part */


/* floating point only now */
#if defined(TH_NTYPE_IS_REAL) || defined(TH_NTYPE_IS_COMPLEX)


VECTOR_IMPLEMENT_FUNCTION(log,TH_MATH_NAME(log))
VECTOR_IMPLEMENT_FUNCTION(exp,TH_MATH_NAME(exp))
VECTOR_IMPLEMENT_FUNCTION(cos,TH_MATH_NAME(cos))
VECTOR_IMPLEMENT_FUNCTION(acos,TH_MATH_NAME(acos))
VECTOR_IMPLEMENT_FUNCTION(cosh,TH_MATH_NAME(cosh))
VECTOR_IMPLEMENT_FUNCTION(sin,TH_MATH_NAME(sin))
VECTOR_IMPLEMENT_FUNCTION(asin,TH_MATH_NAME(asin))
VECTOR_IMPLEMENT_FUNCTION(sinh,TH_MATH_NAME(sinh))
VECTOR_IMPLEMENT_FUNCTION(tan,TH_MATH_NAME(tan))
VECTOR_IMPLEMENT_FUNCTION(atan,TH_MATH_NAME(atan))
VECTOR_IMPLEMENT_FUNCTION(tanh,TH_MATH_NAME(tanh))
VECTOR_IMPLEMENT_FUNCTION_VALUE(pow,TH_MATH_NAME(pow))
VECTOR_IMPLEMENT_FUNCTION(sqrt,TH_MATH_NAME(sqrt))

// additional math functions
VECTOR_IMPLEMENT_FUNCTION(sigmoid,THMath_(sigmoid))
VECTOR_IMPLEMENT_FUNCTION(rsqrt,THMath_(rsqrt))

// real only
#if defined(TH_NTYPE_IS_REAL)
VECTOR_IMPLEMENT_FUNCTION(lgamma,TH_MATH_NAME(lgamma))
VECTOR_IMPLEMENT_FUNCTION(log1p,TH_MATH_NAME(log1p))
VECTOR_IMPLEMENT_FUNCTION(erf,TH_MATH_NAME(erf))
VECTOR_IMPLEMENT_FUNCTION(ceil,TH_MATH_NAME(ceil))
VECTOR_IMPLEMENT_FUNCTION(floor,TH_MATH_NAME(floor))
VECTOR_IMPLEMENT_FUNCTION(round,TH_MATH_NAME(round))
VECTOR_IMPLEMENT_FUNCTION(trunc,TH_MATH_NAME(trunc))
VECTOR_IMPLEMENT_FUNCTION(abs,TH_MATH_NAME(fabs))
VECTOR_IMPLEMENT_FUNCTION(cinv, TH_MATH_NAME(1.0) / )

// addtional math functions
VECTOR_IMPLEMENT_FUNCTION(frac,THMath_(frac))
VECTOR_IMPLEMENT_FUNCTION(erfinv, TH_erfinv)
#endif // real only part

// complex only
#if defined(TH_NTYPE_IS_COMPLEX)
VECTOR_IMPLEMENT_FUNCTION_PART(abs,TH_MATH_NAME(abs))
VECTOR_IMPLEMENT_FUNCTION_PART(real,TH_MATH_NAME(real))
VECTOR_IMPLEMENT_FUNCTION_PART(imag,TH_MATH_NAME(imag))
VECTOR_IMPLEMENT_FUNCTION_PART(arg, TH_MATH_NAME(arg))
VECTOR_IMPLEMENT_FUNCTION_PART(proj,TH_MATH_NAME(proj))
// c conjugate is the only function
// that does not use c as name prefix
VECTOR_IMPLEMENT_FUNCTION(conj, TH_MATH_NAME(onj))
VECTOR_IMPLEMENT_FUNCTION(cinv, 1.0 / )

// addtional math functions
VECTOR_IMPLEMENT_FUNCTION(log1p,THMath_(log1p))
#endif // complex only part

#endif /* floating point only part */

#ifndef TH_NTYPE_IS_BYTE
VECTOR_IMPLEMENT_FUNCTION(neg,-)
#endif

#endif
