#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/THStorageCopy.c"
#else

void THStorage_(rawCopy)(THStorage *storage, ntype *src)
{
  ptrdiff_t i;
  for(i = 0; i < storage->size; i++)
    storage->data[i] = src[i];
}

void THStorage_(copy)(THStorage *storage, THStorage *src)
{
  THArgCheck(storage->size == src->size, 2, "size mismatch");
  THStorage_(rawCopy)(storage, src->data);
}

#define IMPLEMENT_THStorage_COPY(TYPENAMESRC) \
void THStorage_(copy##TYPENAMESRC)(THStorage *storage, TH##TYPENAMESRC##Storage *src) \
{ \
  ptrdiff_t i;                                                        \
  for(i = 0; i < storage->size; i++)                                  \
    storage->data[i] = (ntype)src->data[i];                            \
}

#define IMPLEMENT_THStorage_COPY_FROM_HALF(TYPENAMESRC)		\
void THStorage_(copy##TYPENAMESRC)(THStorage *storage, TH##TYPENAMESRC##Storage *src) \
{ \
  THArgCheck(storage->size == src->size, 2, "size mismatch"); \
  ptrdiff_t i;								\
  for(i = 0; i < storage->size; i++)					\
    storage->data[i] = (ntype)TH_half2float(src->data[i]);		\
}

#define IMPLEMENT_THStorage_COPY_TO_HALF(TYPENAMESRC)		\
void THStorage_(copy##TYPENAMESRC)(THStorage *storage, TH##TYPENAMESRC##Storage *src) \
{ \
  THArgCheck(storage->size == src->size, 2, "size mismatch"); \
  ptrdiff_t i;								\
  for(i = 0; i < storage->size; i++)					\
    storage->data[i] = TH_float2half((float)(src->data[i]));		\
}

#define IMPLEMENT_THStorage_COPY_TO_FROM_HALF(TYPENAMESRC)		\
void THStorage_(copy##TYPENAMESRC)(THStorage *storage, TH##TYPENAMESRC##Storage *src) \
{ \
  THArgCheck(storage->size == src->size, 2, "size mismatch"); \
  ptrdiff_t i;								\
  for(i = 0; i < storage->size; i++)					\
    storage->data[i] = src->data[i];		\
}

/* direct copy from a complex type will only copy its real part
 * which is based on C's complex number type cast behaviour;
 */

#ifndef TH_NTYPE_IS_HALF
IMPLEMENT_THStorage_COPY(Byte)
IMPLEMENT_THStorage_COPY(Char)
IMPLEMENT_THStorage_COPY(Short)
IMPLEMENT_THStorage_COPY(Int)
IMPLEMENT_THStorage_COPY(Long)
IMPLEMENT_THStorage_COPY(Float)
IMPLEMENT_THStorage_COPY(Double)
IMPLEMENT_THStorage_COPY(ZFloat)
IMPLEMENT_THStorage_COPY(ZDouble)
IMPLEMENT_THStorage_COPY_FROM_HALF(Half)
#else
/* only allow pass-through for Half */
IMPLEMENT_THStorage_COPY_TO_FROM_HALF(Half)
IMPLEMENT_THStorage_COPY_TO_HALF(Byte)
IMPLEMENT_THStorage_COPY_TO_HALF(Char)
IMPLEMENT_THStorage_COPY_TO_HALF(Short)
IMPLEMENT_THStorage_COPY_TO_HALF(Int)
IMPLEMENT_THStorage_COPY_TO_HALF(Long)
IMPLEMENT_THStorage_COPY_TO_HALF(Float)
IMPLEMENT_THStorage_COPY_TO_HALF(Double)
IMPLEMENT_THStorage_COPY_TO_HALF(ZFloat)
IMPLEMENT_THStorage_COPY_TO_HALF(ZDouble)
#endif

#endif
