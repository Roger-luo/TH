#ifndef TH_GENERIC_FILE
#error "You must define TH_GENERIC_FILE before including THGenerateZDoubleType.h"
#endif

#define TH_NTYPE_IS_COMPLEX
#define TH_NTYPE_IS_FPOINT
#define part double
#define Part Double

#define ntype double _Complex
#define accntype double _Complex
#define TH_CONVERT_NTYPE_TO_ACCNTYPE(_val) (accntype)(_val)
#define TH_CONVERT_ACCNTYPE_TO_NTYPE(_val) (ntype)(_val)
#define Ntype ZDouble
#define THInf DBL_MAX
#define TH_NTYPE_IS_ZDOUBLE
#line 1 TH_GENERIC_FILE
#include TH_GENERIC_FILE
#undef accntype
#undef ntype
#undef Ntype
#undef THInf
#undef TH_NTYPE_IS_ZDOUBLE
#undef TH_CONVERT_NTYPE_TO_ACCNTYPE
#undef TH_CONVERT_ACCNTYPE_TO_NTYPE

#undef part
#undef Part
#undef TH_NTYPE_IS_COMPLEX
#undef TH_NTYPE_IS_FPOINT

#ifndef THGenerateManyTypes
#undef TH_GENERIC_FILE
#endif
