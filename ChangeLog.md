# Change Log for Complex Version

generic type name: `ntype`
part complex type name: `part`

type notation:
- `real`: `float`, `double`
- `complex`: `zfloat`, `zdouble`

## generic type generator

- `THGenerateAllTypes.h`
- `THGenerateFloatTypes.h`
- `THGenerateComplexTypes.h`
- `THGenerateIntTypes.h`


- `THGenerateByteType.h`
- `THGenerateCharType.h`
- `THGenerateDoubleType.h`
- `THGenerateFloatType.h`
- `THGenerateZDoubleType.h`
- `THGenerateZFloatType.h`

## Macro List

Float types (has blas support)
`TH_NTYPE_IS_DOUBLE`
`TH_NTYPE_IS_FLOAT`
`TH_NTYPE_IS_ZDOUBLE`
`TH_NTYPE_IS_ZFLOAT`

int types
`TH_NTYPE_IS_BYTE`
`TH_NTYPE_IS_CHAR`
`TH_NTYPE_IS_HALF`
`TH_NTYPE_IS_INT`
`TH_NTYPE_IS_LONG`
`TH_NTYPE_IS_SHORT`

for complex type macro `TH_NTYPE_IS_COMPLEX` is defined. for real type (`float`, `double`), `TH_NTYPE_IS_REAL` is defined.

for floating points type (`float`, `double`, `float _Complex`, `double _Complex`) `TH_NTYPE_IS_FPOINT`

## File not changed

- `THAtomic.h`

---

# Generic Type Generator
- [x] Add `THGenerateZDoubleType.h`
- [x] Add `THGenerateZFloatType.h`
- [x] Add `THGenerateComplexType.h`
- [x] Add `THGenerateRealType.h`
- [x] change `THGenerateFloatType.h` to include: `float`, `double`, `complex64`, `complex128`

# Additional Utilities
## Type Traits

### Type name
`TH_TYPE_NAME` is defined to get type name at compile time.

### BLAS name
`TH_BLAS_NAME` auto add prefix to blas names. The rules is described as following:

- `double`: d##NAME_
- `float`: s##NAME_
- `double _Complex`: z##NAME_
- `float _Complex`: c##NAME_

The name is following Fortran API. `TH_LAPACK_NAME` is equivalent to `TH_BLAS_NAME`.

`TH_MATH_NAME` auto add prefix and suffix for c math functions.

- `double`: NAME
- `float`: NAME##f
- `double _Complex`: c##NAME
- `double _Complex`: c##NAME##f

### Additional Math Name

macro `THMath_(NAME)` is used to generate additional math function names defined in `THMath.h`. Additional math functions use same name rules with c math functions with a prefix `TH_`.

# Wappers
## BLAS

file: generic/THBlas.c

- [x] use `TH_BLAS_NAME` instead of plan declaration
- [x] add complex support

note: for complex type, rather than `dot` and `ger`, we use `dotc` and `gerc` instead.

## LAPACK

file: generic/THLapack.c

- [x] add complex support

note: for complex type, following function is changed

- `syev` -> `heev`
- `orgqr` -> `ungqr`
- `unmqr` -> `ormqr`

## extra math functions

file: THMath.h

- [x] add dependency: `complex.h`
- [x] move declarations to **generic**

## Vectorization

file: generic/THVectorDefault.c

- [x] add default vector functions

### AVX
- [x] copy
- [x] fill

### AVX2
- [x] cdiv
- [x] divs
- [x] cmul
- [x] muls
- [x] cadd
- [x] adds

## LogAdd

*not changed yet*


## Storage

- [x] copy methods

note: direct copy from a complex type will only copy its real part which is based on C's complex number type cast behaviour.

## Tensor

### copy

similar with Storage, direct copy will only copy its real part.

### random

file: `THTensorRandom.c`, `THTensorRandom.h`

- [x] `random`, `complex` is implemented by two real random number as its real and complex part.
- [x] other function will not support complex

### math

file: `THTensorMath.c`, `THTensorMath.h`

#### function support complex types and do not need change:

`fill`, `zero`, `maskedFill`, `maskedCopy`, `maskedSelect`, `nonzero`, `indexSelect`, `indexCopy`, `dataOffset`, `wrapLinearIndex`, `take`, `put`, `indexAdd`, `indexFill`, `gather`, `scatter`, `scatterAdd`, `scatterFill`, `dot`, `sumall`, `prodall`, `add`, `sub`, `add_scaled`, `sub_scaled`, `mul`, `div`, `cadd`, `csub`, `cmul`, `cdiv`, `addcmul`, `addcdiv`, `addmv`, `match`, `addmm`, `addr`, `addbmm`, `baddbmm`, `numel`, `sum`, `prod`, `cumsum`, `cumprod`, `trace`, `cross`, `zeros`, `zerosLike`, `onesLike`, `ones`, `diag`, `eye`, `randperm`, `reshape`, `tril`, `triu`, `cat`, `catArray`, `equal`, `lerp`, `mean`, `meanall`, `linspace`, `rand`

#### function do not support complex:

`minall`, `maxall`, `medianall`, `lshift`, `rshift`, `fmod`, `remainder`, `bitand`, `bitor`, `clamp`, `clshift`, `crshift`, `cfmod`, `cremainder`, `cbitand`, `cbitor`, `cbitxor`, `max`, `min`, `cmax`, `cmin`, `cmaxValue`, `cminValue`, `range`, `arange`, `mode`, `kthvalue`, `median`, `atan2`, `renorm`, `randn`, `histc`, `bhistc`

logical functions:

`<`, `>`, `<=`, `>=`


#### static functions that do not support complex:
`quicksortascend`, `quicksortdescend`, `quickselectnoidx`, `quickselect`


#### function support complex but need modification:

`cpow`, `tpow`, `sign` (z/|z|), `abs`, `pow`, `std`, `var`, `norm`, `normall`, `dist`, `varall`

#### additional functions for complex

`real`, `imag`, `arg`, `proj`, `conj`

### file

file: `THFile`

#### virtual table

- [x] add complex members

#### read and write methods

- [x] scalar
- [x] storage
- [x] raw

### disk file

- [x] read and write methods
- [x] register them in virtual table

### memory file

- [x] read and write methods
- [x] register them in virtual table
