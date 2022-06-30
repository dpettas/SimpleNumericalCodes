#include <iostream>
#include <functional>
#include <cmath>

using unary_t = std::function<double(double)>;


double bisection(double a, double b, unary_t fuuc);


int main (int argc, char *argv[])
{
 
  bisection(-10, 10, [](double x){return x - 0.1;});
  return 0;
}

double bisection(double a, double b, unary_t func)
{

  while(std::abs(func(a)*func(b)) > 1e-5 )
  {

    double c = (a+b)/2.0;

    if( func(a) * func(c) < 0) b = c;
    if( func(c) * func(b) < 0) a = c;
  }


  std::cout << (a+b)/2.0 << std::endl;
  return (a+b)/2.0;
}




