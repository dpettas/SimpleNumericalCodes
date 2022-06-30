#include <cstdio>

extern "C" void dgetrf_ (int* M, int* N, double* A, int* lda, int* ipiv, int* info );
extern "C" void dgetrs_ (char* trans, int* n, int* nrhs, double* A, int* lda, int* ipiv, double* b, int* ldb, int* info);
extern "C" void hello_ (void);



int main (int argc, char *argv[])
{

  int n = 3; 
  double* A  = new double [n*n];
  double* B  = new double [n];
  int*  ipiv = new int[n];
  int*  info = new int;

  for (int i = 0; i < n*n; ++i)
  {
    A[i] = 0.0;
  }


  hello_();

  A[0*n+0] = 1.0; A[0*n+1] = 2.0; A[0*n + 2] = -1.0;
  A[1*n+0] = 2.0; A[1*n+1] = 2.0; A[1*n + 2] =  2.0;
  A[2*n+0] = 1.0; A[2*n+1] =-1.0; A[2*n + 2] =  2.0;

  B[0] = 2.0;
  B[1] = 12.0;
  B[2] = 5.0;
  

  int nrhs = 1;
  char trans = 'T';

  dgetrf_ (&n, &n, A, &n, ipiv, info);
  dgetrs_(&trans, &n, &nrhs, A, &n, ipiv, B, &n, info );

  printf("%f\n", B[0]);
  printf("%f\n", B[1]);
  printf("%f\n", B[2]);




  
  return 0;
}
