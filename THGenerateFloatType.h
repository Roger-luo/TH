#ifndef TH_GENERIC_FILE
#error "You must define TH_GENERIC_FILE before including THGenerateFloatType.h"
#endif

#define TH_NTYPE_IS_REAL
#define TH_NTYPE_IS_FPOINT

#define ntype float
#define accntype double
#define TH_CONVERT_NTYPE_TO_ACCNTYPE(_val) (accntype)(_val)
#define TH_CONVERT_ACCNTYPE_TO_NTYPE(_val) (ntype)(_val)
#define Ntype Float
#define THInf FLT_MAX
#define TH_NTYPE_IS_FLOAT
#define TH_NTYPE_IS_REAL
#line 1 TH_GENERIC_FILE
#include TH_GENERIC_FILE
#undef accntype
#undef ntype
#undef Ntype
#undef THInf
#undef TH_NTYPE_IS_REAL
#undef TH_NTYPE_IS_FLOAT
#undef TH_CONVERT_NTYPE_TO_ACCNTYPE
#undef TH_CONVERT_ACCNTYPE_TO_NTYPE

#undef TH_NTYPE_IS_REAL
#undef TH_NTYPE_IS_FPOINT

#ifndef THGenerateManyTypes
#undef TH_GENERIC_FILE
#endif
