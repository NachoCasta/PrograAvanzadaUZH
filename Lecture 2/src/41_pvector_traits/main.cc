#include <iostream>
using namespace std;

#include "pvector.h"
#include "pset.h"

int main(int argc, char *argv[])
{
  pvector<int> pvi("tmp/test.txt");
  foo(pvi);

  pvector<string> pvs("tmp/string.txt");
  pvs.push_back("hello");
  pvs.push_back("world");
  pvs.push_back("my name is Ignacio");
  pvs.push_back("------------------");

  pset<int> ps("tmp/set_int.txt");
  ps.erase(4);
  return 0;
}
