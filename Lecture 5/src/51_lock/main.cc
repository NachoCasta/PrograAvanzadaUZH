#include <iostream>
#include <complex>
using namespace std;

#include "rpn.h"
#include "fraction.h"

int main(int argc, char *argv[])
{
  RPN<int> rpn("tmp/rpn.txt");
  rpn.main_loop();
  return 0;
}
