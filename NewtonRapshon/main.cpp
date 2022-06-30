#include <iostream>
#include <iomanip>
#include <functional>
#include <cmath>


using unary_t = std::function<double(double)>;

double NewtonRapshon(double init, unary_t func);




int main (int argc, char *argv[])
{


  std::cout << NewtonRapshon(-0.0, [](double x){return x*x - 0.01;}) << std::endl;
  
  return 0;
}



double NewtonRapshon(double init, unary_t func)
{
  auto der = [&func] (double x) { return (func(x+1e-6) - func(x))/1e-6; };

  double x  = init; 
  double dx = 1.0;


  while (std::abs(dx) > 1e-8)
  {

    dx = func(x)/der(x);
    x -= dx;
    std::cout << dx << std::endl;
  }

  

  return x;

}
