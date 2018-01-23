#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/THVector.h"
#else

TH_API void THVector_(fill)(ntype *x, const ntype c, const ptrdiff_t n);
TH_API void THVector_(cadd)(ntype *z, const ntype *x, const ntype *y, const ntype c, const ptrdiff_t n);
TH_API void THVector_(adds)(ntype *y, const ntype *x, const ntype c, const ptrdiff_t n);
TH_API void THVector_(cmul)(ntype *z, const ntype *x, const ntype *y, const ptrdiff_t n);
TH_API void THVector_(muls)(ntype *y, const ntype *x, const ntype c, const ptrdiff_t n);
TH_API void THVector_(cdiv)(ntype *z, const ntype *x, const ntype *y, const ptrdiff_t n);
TH_API void THVector_(divs)(ntype *y, const ntype *x, const ntype c, const ptrdiff_t n);
TH_API void THVector_(copy)(ntype *y, const ntype *x, const ptrdiff_t n);

#if defined(TH_NTYPE_IS_SHORT) || defined(TH_NTYPE_IS_INT) || defined(TH_NTYPE_IS_LONG)
TH_API void THVector_(abs)(ntype *y, const ntype *x, const ptrdiff_t n);
#endif

/* floating point only now */
#if defined(TH_NTYPE_IS_REAL) || defined(TH_NTYPE_IS_COMPLEX)

TH_API void THVector_(log)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(log1p)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(sigmoid)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(exp)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(cos)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(acos)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(cosh)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(sin)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(asin)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(sinh)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(tan)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(atan)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(tanh)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(pow)(ntype *y, const ntype *x, const ntype c, const ptrdiff_t n);
TH_API void THVector_(sqrt)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(rsqrt)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(cinv)(ntype *y, const ntype *x, const ptrdiff_t n);

// real only
#if defined(TH_NTYPE_IS_REAL)
TH_API void THVector_(lgamma)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(ceil)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(floor)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(round)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(erf)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(erfinv)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(abs)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(trunc)(ntype *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(frac)(ntype *y, const ntype *x, const ptrdiff_t n);
#endif // real only part

#if defined(TH_NTYPE_IS_COMPLEX)
TH_API void THVector_(abs)(part *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(real)(part *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(imag)(part *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(arg)(part *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(proj)(part *y, const ntype *x, const ptrdiff_t n);
TH_API void THVector_(conj)(ntype *y, const ntype *x, const ptrdiff_t n);
#endif // complex only part

#endif /* floating point only part */

#ifndef TH_NTYPE_IS_BYTE
TH_API void THVector_(neg)(ntype *y, const ntype *x, const ptrdiff_t n);
#endif

/* Initialize the dispatch pointers */
TH_API void THVector_(vectorDispatchInit)(void);

#endif
