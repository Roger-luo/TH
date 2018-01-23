#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/THBlas.c"
#else

#include "THTypeMacros.h"

#ifdef BLAS_F2C
# define ffloat double
#else
# define ffloat float
#endif

// extern blas header only supports float numbers
#if defined(TH_NTYPE_IS_COMPLEX) || defined(TH_NTYPE_IS_REAL)
TH_EXTERNC void TH_BLAS_NAME(swap)(int *n, ntype *x, int *incx, ntype *y, int *incy);
TH_EXTERNC void TH_BLAS_NAME(scal)(int *n, ntype *a, ntype *x, int *incx);
TH_EXTERNC void TH_BLAS_NAME(copy)(int *n, ntype *x, int *incx, ntype *y, int *incy);
TH_EXTERNC void TH_BLAS_NAME(axpy)(int *n, ntype *a, ntype *x, int *incx, ntype *y, int *incy);
TH_EXTERNC void TH_BLAS_NAME(gemv)(char *trans, int *m, int *n, ntype *alpha, ntype *a, int *lda, ntype *x, int *incx, ntype *beta, ntype *y, int *incy);
TH_EXTERNC void TH_BLAS_NAME(gemm)(char *transa, char *transb, int *m, int *n, int *k, ntype *alpha, ntype *a, int *lda, ntype *b, int *ldb, ntype *beta, ntype *c, int *ldc);


// begin dot
/* blas.dot declaration
 * cblas is re-wrapped to fortran form
 * for complex type, dot use dotc rather
 * than complex dot
 */
#ifdef TH_NTYPE_IS_DOUBLE
TH_EXTERNC double TH_BLAS_NAME(dot)(int *n, double *x, int *incx, double *y, int *incy);
#elif defined(TH_NTYPE_IS_COMPLEX)
TH_EXTERNC ntype TH_BLAS_NAME(dotc)(int *n, ntype *x, int *incx, ntype *y, int *incy);
#endif

#ifdef BLAS_USE_CBLAS_DOT
TH_EXTERNC float cblas_sdot(const int n, const float *x, const int incx, const float *y, const int incy);

#ifndef THBlas_C_sdot_
#define THBlas_C_sdot_
inline ffloat sdot_(const int *n, const float *x, const int *incx, const float *y, const int *incy)
{
  return cblas_sdot(*n, x, *incx, y, *incy);
}
#endif // THBlas_C_sdot_

#else
TH_EXTERNC ffloat sdot_(int *n, float *x, int *incx, float *y, int *incy);
#endif

// end dot

// begin ger

/*
 * ger declaration
 * complex will use gerc
 */

#ifdef TH_NTYPE_IS_COMPLEX
TH_EXTERNC void TH_BLAS_NAME(gerc)(int *m, int *n, ntype *alpha, ntype *x, int *incx, ntype *y, int *incy, ntype *a, int *lda);
#else
TH_EXTERNC void TH_BLAS_NAME(ger)(int *m, int *n, ntype *alpha, ntype *x, int *incx, ntype *y, int *incy, ntype *a, int *lda);
#endif

#endif // TH_NTYPE_IS_REAL || TH_NTYPE_IS_COMPLEX

void THBlas_(swap)(int64_t n, ntype *x, int64_t incx, ntype *y, int64_t incy)
{
  if(n == 1)
  {
    incx = 1;
    incy = 1;
  }

#if defined(USE_BLAS) && defined(TH_NTYPE_IS_FPOINT)
  if( (n <= INT_MAX) && (incx <= INT_MAX) && (incy <= INT_MAX) )
  {
    int i_n = (int)n;
    int i_incx = (int)incx;
    int i_incy = (int)incy;

    TH_BLAS_NAME(swap)(&i_n, x, &i_incx, y, &i_incy);
    return;
  }
#endif
  {
    int64_t i;
    for(i = 0; i < n; i++)
    {
      ntype z = x[i*incx];
      x[i*incx] = y[i*incy];
      y[i*incy] = z;
    }
  }
}

void THBlas_(scal)(int64_t n, ntype a, ntype *x, int64_t incx)
{
  if(n == 1)
    incx = 1;

#if defined(USE_BLAS) && defined(TH_NTYPE_IS_FPOINT)
  if( (n <= INT_MAX) && (incx <= INT_MAX) )
  {
    int i_n = (int)n;
    int i_incx = (int)incx;

    TH_BLAS_NAME(scal)(&i_n, &a, x, &i_incx);
    return;
  }
#endif
  {
    int64_t i;
    for(i = 0; i < n; i++) {
      if (a == 0) {
        x[i*incx] = 0;
      } else {
        x[i*incx] *= a;
      }
    }
  }
}

void THBlas_(copy)(int64_t n, ntype *x, int64_t incx, ntype *y, int64_t incy)
{
  if(n == 1)
  {
    incx = 1;
    incy = 1;
  }

#if defined(USE_BLAS) && defined(TH_NTYPE_IS_FPOINT)
  if( (n <= INT_MAX) && (incx <= INT_MAX) && (incy <= INT_MAX) )
  {
    int i_n = (int)n;
    int i_incx = (int)incx;
    int i_incy = (int)incy;

    TH_BLAS_NAME(copy)(&i_n, x, &i_incx, y, &i_incy);
    return;
  }
#endif
  {
    int64_t i;
    for(i = 0; i < n; i++)
      y[i*incy] = x[i*incx];
  }
}

void THBlas_(axpy)(int64_t n, ntype a, ntype *x, int64_t incx, ntype *y, int64_t incy)
{
  if(n == 1)
  {
    incx = 1;
    incy = 1;
  }

#if defined(USE_BLAS) && defined(TH_NTYPE_IS_FPOINT)
  if( (n <= INT_MAX) && (incx <= INT_MAX) && (incy <= INT_MAX) )
  {
    int i_n = (int)n;
    int i_incx = (int)incx;
    int i_incy = (int)incy;

    TH_BLAS_NAME(axpy)(&i_n, &a, x, &i_incx, y, &i_incy);
    return;
  }
#endif
  {
    int64_t i;
    for(i = 0; i < n; i++)
      y[i*incy] += a*x[i*incx];
  }
}

ntype THBlas_(dot)(int64_t n, ntype *x, int64_t incx, ntype *y, int64_t incy)
{
  if(n == 1)
  {
    incx = 1;
    incy = 1;
  }

#if defined(USE_BLAS) && defined(TH_NTYPE_IS_FPOINT)
  if( (n <= INT_MAX) && (incx <= INT_MAX) && (incy <= INT_MAX) )
  {
    int i_n = (int)n;
    int i_incx = (int)incx;
    int i_incy = (int)incy;

#if defined(TH_NTYPE_IS_REAL)
    return (ntype) TH_BLAS_NAME(dot)(&i_n, x, &i_incx, y, &i_incy);
#else
    return (ntype) TH_BLAS_NAME(dotc)(&i_n, x, &i_incx, y, &i_incy);
#endif
  }
#endif
  {
    int64_t i;
    ntype sum = 0;
    for(i = 0; i < n; i++)
    sum += x[i*incx]*y[i*incy];
    return sum;
  }
}

void THBlas_(gemv)(char trans, int64_t m, int64_t n, ntype alpha, ntype *a, int64_t lda, ntype *x, int64_t incx, ntype beta, ntype *y, int64_t incy)
{
  if(n == 1)
    lda = m;

#if defined(USE_BLAS) && defined(TH_NTYPE_IS_FPOINT)
  if( (m <= INT_MAX) && (n <= INT_MAX) &&
      (lda >= THMax(1, m)) && (lda <= INT_MAX) &&
      (incx > 0) && (incx <= INT_MAX) &&
      (incy > 0) && (incy <= INT_MAX) )
  {
    int i_m = (int)m;
    int i_n = (int)n;
    int i_lda = (int)lda;
    int i_incx = (int)incx;
    int i_incy = (int)incy;

    TH_BLAS_NAME(gemv)(&trans, &i_m, &i_n, &alpha, a, &i_lda, x, &i_incx, &beta, y, &i_incy);
    return;
  }
#endif
  {
    int64_t i, j;

    if( (trans == 'T') || (trans == 't') )
    {
      for(i = 0; i < n; i++)
      {
        ntype sum = 0;
        ntype *row_ = a+lda*i;
        for(j = 0; j < m; j++)
          sum += x[j*incx]*row_[j];
	if (beta == 0)
	  y[i*incy] = alpha*sum;
	else
	  y[i*incy] = beta*y[i*incy] + alpha*sum;
      }
    }
    else
    {
      if(beta != 1)
        THBlas_(scal)(m, beta, y, incy);

      for(j = 0; j < n; j++)
      {
        ntype *column_ = a+lda*j;
        ntype z = alpha*x[j*incx];
        for(i = 0; i < m; i++)
          y[i*incy] += z*column_[i];
      }
    }
  }
}

void THBlas_(ger)(int64_t m, int64_t n, ntype alpha, ntype *x, int64_t incx, ntype *y, int64_t incy, ntype *a, int64_t lda)
{
  if(n == 1)
    lda = m;

#if defined(USE_BLAS) && defined(TH_NTYPE_IS_FPOINT)
  if( (m <= INT_MAX) && (n <= INT_MAX) &&
      (lda >= THMax(1, m)) && (lda <= INT_MAX) &&
      (incx > 0) && (incx <= INT_MAX) &&
      (incy > 0) && (incy <= INT_MAX) )
  {
    int i_m = (int)m;
    int i_n = (int)n;
    int i_lda = (int)lda;
    int i_incx = (int)incx;
    int i_incy = (int)incy;

#if defined(TH_NTYPE_IS_REAL)
    TH_BLAS_NAME(ger)(&i_m, &i_n, &alpha, x, &i_incx, y, &i_incy, a, &i_lda);
#else
    TH_BLAS_NAME(gerc)(&i_m, &i_n, &alpha, x, &i_incx, y, &i_incy, a, &i_lda);
#endif
    return;
  }
#endif
  {
    int64_t i, j;
    for(j = 0; j < n; j++)
    {
      ntype *column_ = a+j*lda;
      ntype z = alpha*y[j*incy];
      for(i = 0; i < m; i++)
        column_[i] += z*x[i*incx] ;
    }
  }
}

void THBlas_(gemm)(char transa, char transb, int64_t m, int64_t n, int64_t k, ntype alpha, ntype *a, int64_t lda, ntype *b, int64_t ldb, ntype beta, ntype *c, int64_t ldc)
{
  int transa_ = ((transa == 't') || (transa == 'T'));
  int transb_ = ((transb == 't') || (transb == 'T'));

  if(n == 1)
    ldc = m;

  if(transa_)
  {
    if(m == 1)
      lda = k;
  }
  else
  {
    if(k == 1)
      lda = m;
  }

  if(transb_)
  {
    if(k == 1)
      ldb = n;
  }
  else
  {
    if(n == 1)
      ldb = k;
  }

#if defined(USE_BLAS) && defined(TH_NTYPE_IS_FPOINT)
  if( (m <= INT_MAX) && (n <= INT_MAX) && (k <= INT_MAX) &&
      (lda >= THMax(1, (transa_ ? k : m))) && (lda <= INT_MAX) &&
      (ldb >= THMax(1, (transb_ ? n : k))) && (ldb <= INT_MAX) &&
      (ldc >= THMax(1, m)) && (ldc <= INT_MAX) )
  {
    int i_m = (int)m;
    int i_n = (int)n;
    int i_k = (int)k;
    int i_lda = (int)lda;
    int i_ldb = (int)ldb;
    int i_ldc = (int)ldc;

    TH_BLAS_NAME(gemm)(&transa, &transb, &i_m, &i_n, &i_k, &alpha, a, &i_lda, b, &i_ldb, &beta, c, &i_ldc);
    return;
  }
#endif
  {
    int64_t i, j, l;
    if(!transa_ && !transb_)
    {
      ntype *a_ = a;
      for(i = 0; i < m; i++)
      {
        ntype *b_ = b;
        for(j = 0; j < n; j++)
        {
          ntype sum = 0;
          for(l = 0; l < k; l++)
            sum += a_[l*lda]*b_[l];
          b_ += ldb;
	  if (beta == 0)
	    c[j*ldc+i] = alpha*sum;
	  else
	    c[j*ldc+i] = beta*c[j*ldc+i]+alpha*sum;
        }
        a_++;
      }
    }
    else if(transa_ && !transb_)
    {
      ntype *a_ = a;
      for(i = 0; i < m; i++)
      {
        ntype *b_ = b;
        for(j = 0; j < n; j++)
        {
          ntype sum = 0;
          for(l = 0; l < k; l++)
            sum += a_[l]*b_[l];
          b_ += ldb;
	  if (beta == 0)
	    c[j*ldc+i] = alpha*sum;
	  else
	    c[j*ldc+i] = beta*c[j*ldc+i]+alpha*sum;
        }
        a_ += lda;
      }
    }
    else if(!transa_ && transb_)
    {
      ntype *a_ = a;
      for(i = 0; i < m; i++)
      {
        ntype *b_ = b;
        for(j = 0; j < n; j++)
        {
          ntype sum = 0;
          for(l = 0; l < k; l++)
            sum += a_[l*lda]*b_[l*ldb];
          b_++;
	  if (beta == 0)
	    c[j*ldc+i] = alpha*sum;
	  else
	    c[j*ldc+i] = beta*c[j*ldc+i]+alpha*sum;
        }
        a_++;
      }
    }
    else
    {
      ntype *a_ = a;
      for(i = 0; i < m; i++)
      {
        ntype *b_ = b;
        for(j = 0; j < n; j++)
        {
          ntype sum = 0;
          for(l = 0; l < k; l++)
            sum += a_[l]*b_[l*ldb];
          b_++;
	  if (beta == 0)
	    c[j*ldc+i] = alpha*sum;
	  else
	    c[j*ldc+i] = beta*c[j*ldc+i]+alpha*sum;
        }
        a_ += lda;
      }
    }
  }
}

#endif
