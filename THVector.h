#ifndef TH_VECTOR_INC
#define TH_VECTOR_INC

#include "THGeneral.h"
#include "THMath.h"

#define THVector_(NAME) TH_CONCAT_4(TH,Ntype,Vector_,NAME)
#define THPartVector_(NAME) TH_CONCAT_4(TH,Part,Vector_,NAME)

/* We are going to use dynamic dispatch, and want only to generate declarations
 * of the vector functions */
#include "generic/THVector.h"
#include "THGenerateAllTypes.h"

#endif // TH_VECTOR_INC
