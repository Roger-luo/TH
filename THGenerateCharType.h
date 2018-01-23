#ifndef TH_GENERIC_FILE
#error "You must define TH_GENERIC_FILE before including THGenerateCharType.h"
#endif

#define ntype int8_t
#define untype uint8_t
#define accntype int64_t
#define Ntype Char
#define THInf CHAR_MAX
#define TH_CONVERT_NTYPE_TO_ACCNTYPE(_val) (accntype)(_val)
#define TH_CONVERT_ACCNTYPE_TO_NTYPE(_val) (ntype)(_val)
#define TH_NTYPE_IS_CHAR
#line 1 TH_GENERIC_FILE
#include TH_GENERIC_FILE
#undef ntype
#undef untype
#undef accntype
#undef Ntype
#undef THInf
#undef TH_NTYPE_IS_CHAR
#undef TH_CONVERT_NTYPE_TO_ACCNTYPE
#undef TH_CONVERT_ACCNTYPE_TO_NTYPE

#ifndef THGenerateManyTypes
#undef TH_GENERIC_FILE
#endif
