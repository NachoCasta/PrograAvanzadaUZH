#include <iostream>
#include <complex>
using namespace std;

#include "rpn.h"
#include "fraction.h"

int main(int argc, char *argv[])
{
  RPN<Fraction> rpn("tmp/rpn.txt");
  //RPN<complex<double>> rpn("tmp/complex.txt");
  rpn.main_loop();
  return 0;
}
