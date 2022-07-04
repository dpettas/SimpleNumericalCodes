#include <iostream>
#include <functional>
#include <cmath>
#include <limits>
#include <algorithm>


double golderratiosearch(double a, double b, std::function<double(double)> f )
{

  double phi = (std::sqrt(5) + 1.0)/2.0;


  int iter = 0;
  double c; 
  double d;
  while (true)
  {
    ++iter;
    std::cout << iter << " [" << a << "," << b << "]\n";

      
    c = a + (b-a)/phi;
    d = b - (b-a)/phi;

    if (  f(c) > f(d))
      b = d;
    else 
      a = c;

    if ( std::abs(b-a) < 1.e-7) return (b-a)/2.0;
    if ( iter == 1000) return std::numeric_limits<double>::quiet_NaN();
  }

  return std::numeric_limits<double>::quiet_NaN();
}





int main (int argc, char *argv[])
{

  std::cout << golderratiosearch(1,5, [] (double x) {return std::pow(x-2.0, 2);} );
  
  return 0;
}
