#include <iostream>
using namespace std;

#include "pvector.h"

int main(int argc, char *argv[])
{
  pvector<int> pvi("tmp/test.txt");
  foo(pvi);

  pvector<string> pvs("tmp/string.txt");
  pvs.push_back("hello");
  pvs.push_back("world");
  pvs.push_back("my name is Ignacio");
  pvs.push_back("------------------");

  return 0;
}
