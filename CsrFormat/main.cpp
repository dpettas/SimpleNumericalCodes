#include <iostream>
#include <cstdlib>


void showCSR(int _n, int _nnz, double* _values, int* _ia, int* _ja)
{

  double mat [_n] [_n];

  for (int i = 0; i < _n; ++i)
  {
    for (int j = 0; j < _n; ++j)
    {
      mat[i][j] = 0.0;
    }
  }


  for (int irow = 0; irow < _n; ++irow)
  {

    for (int col = _ia[irow]; col < _ia[irow+1]; ++col)
    {
      mat[irow][ _ja[col]] = _values[col];
    }
  }

  for (int i = 0; i < _n; ++i)
  {
    for (int j = 0; j < _n; ++j)
    {
      std::cout << mat[i][j] << "  ";
    }
    std::cout << std::endl;
  }


}









int main (int argc, char *argv[])
{
  double values [] = {1,-1,-3,-2,5,4,6,4,-4,2,7,8,-5};
  int    ja []     = {0,1,3,0,1,2,3,4,0,2,3,1,4};
  int    ia []     = {0,3,5,8,11,13};

  int nnz = sizeof(values)/sizeof(double);
  int n   = sizeof(ia)/sizeof(int) - 1;


  showCSR(n,nnz,values,ia,ja);




  
  return 0;
}
