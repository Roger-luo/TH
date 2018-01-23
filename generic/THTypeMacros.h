#ifdef TH_TYPE_NAME
#undef TH_TYPE_NAME
#endif

#ifdef TH_BLAS_NAME
#undef TH_BLAS_NAME
#endif

#ifdef TH_MATH_NAME
#undef TH_MATH_NAME
#endif

#ifdef THMath_
#undef THMath_
#endif

#ifdef TH_LAPACK_NAME
#undef TH_LAPACK_NAME
#endif

#ifdef TH_ABS
#undef TH_ABS
#endif

#ifdef TH_MULC
#undef TH_MULC
#endif

#define TH_TYPE_NAME(NAME) #NAME

#if   defined(TH_NTYPE_IS_DOUBLE)
#define TH_BLAS_NAME(NAME) d##NAME##_
#define TH_MATH_NAME(NAME) NAME
#define THMath_(NAME) TH_##NAME
#define TH_ABS(Z) fabs(Z)
#define TH_MULC(Z, C) ((Z) * (C))
#elif defined(TH_NTYPE_IS_FLOAT)
#define TH_BLAS_NAME(NAME) s##NAME##_
#define TH_MATH_NAME(NAME) NAME##f
#define THMath_(NAME) TH_##NAME##f
#define TH_ABS(Z) fabsf(Z)
#define TH_MULC(Z, C) ((Z) * (C))
#elif defined(TH_NTYPE_IS_ZDOUBLE)
#define TH_BLAS_NAME(NAME) z##NAME##_
#define TH_MATH_NAME(NAME) c##NAME
#define THMath_(NAME) TH_c##NAME
#define TH_ABS(Z) cabs(Z)
#define TH_MULC(Z, C) ((Z) * conj(C))
#elif defined(TH_NTYPE_IS_ZFLOAT)
#define TH_BLAS_NAME(NAME) c##NAME##_
#define TH_MATH_NAME(NAME) c##NAME##f
#define THMath_(NAME) TH_c##NAME##f
#define TH_ABS(Z) cabsf(Z)
#define TH_MULC(Z, C) ((Z) * conjf(C))
// Int types
#else
#define TH_BLAS_NAME(NAME)
#define TH_MATH_NAME(NAME)
#define THMath_(NAME)
#define TH_ABS(Z)
#endif

#define TH_LAPACK_NAME(NAME) TH_BLAS_NAME(NAME)
