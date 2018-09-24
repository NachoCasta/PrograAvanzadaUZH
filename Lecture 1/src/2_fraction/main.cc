#include <iostream>
using namespace std;

#include "fraction.h"

int main(int argc, char *argv[])
{
  Fraction f(3, 5);
  cout << f.getNum() << endl;
  cout << f.getDen() << endl;
  return 0;
}
