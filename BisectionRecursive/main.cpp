#include <iostream>
#include <functional>
#include <limits>
#include <cmath>

using unary_t = std::function<double(double)>;


double bisectionRecursive(double a, double b, unary_t func, double eps = 1e-8);



int main (int argc, char *argv[])
{

  
  std::cout << bisectionRecursive(-1.0, 3.0, [](double x) { return x - 1.413;}) << std::endl;


  return 0;
}




double bisectionRecursive(double a, double b, unary_t func, double eps)
{
  std::cout << a << " " << b << std::endl;

  double c = (a+b)/2;
  double res;

  if (std::abs(func(a)) < eps)
    return a;

  if (std::abs(func(b)) < eps)
    return b;


  if ( std::abs( func(a) * func(b) ) < eps)
    return c;

  if (func(a) * func(c) < 0.0)
  {
    res = bisectionRecursive(a,c, func);
  }
  else 
  {
    res = bisectionRecursive(c,b, func);
  }


  return res;
}
