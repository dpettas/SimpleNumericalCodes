#include <iostream>
#include <unistd.h>
#include <omp.h>

int main (int argc, char *argv[])
{

  omp_set_num_threads(8);
  
  #pragma omp parallel
  {
    usleep(2 * omp_get_thread_num()); // do this to avoid race condition while printing
    std::cout << "Hello World" << std::endl;
  }



  return 0;
}
