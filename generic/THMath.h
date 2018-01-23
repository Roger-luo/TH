#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/THMath.h"
#else

#include "THTypeMacros.h"

static inline ntype THMath_(sigmoid)(ntype value) {
    return 1.0 / (1.0 + TH_MATH_NAME(exp)(-value));
}

static inline ntype THMath_(rsqrt)(ntype x) {
    return 1.0 / TH_MATH_NAME(sqrt)(x);
}

static inline ntype THMath_(lerp)(ntype a, ntype b, ntype weight) {
    return a + weight * (b-a);
}

// real type only
#ifdef TH_NTYPE_IS_REAL

static inline ntype THMath_(frac)(ntype x) {
    return x - TH_MATH_NAME(trunc)(x);
}

#endif

// complex type only
#ifdef TH_NTYPE_IS_COMPLEX

static inline ntype THMath_(log1p)(ntype x) {
    return TH_MATH_NAME(log)(1 + x);
}

#endif

#endif