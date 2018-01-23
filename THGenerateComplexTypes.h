#ifndef TH_GENERIC_FILE
#error "You must define TH_GENERIC_FILE before including THGenerateComplexTypes.h"
#endif

#ifndef THGenerateManyTypes
#define THFloatLocalGenerateManyTypes
#define THGenerateManyTypes
#endif

#include "THGenerateZFloatType.h"
#include "THGenerateZDoubleType.h"

#ifdef THFloatLocalGenerateManyTypes
#undef THFloatLocalGenerateManyTypes
#undef THGenerateManyTypes
#undef TH_GENERIC_FILE
#endif
