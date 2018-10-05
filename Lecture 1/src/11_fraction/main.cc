#include <iostream>
using namespace std;

#include "fraction.h"

int main(int argc, char *argv[])
{
  if (argc == 1) {
    Fraction f1(3, 5);
    cout << "f1: " << f1 << endl;
    Fraction f2(3, 6);
    cout << "f2: " << f2 << endl;
    Fraction f3(0);
    cout << "f3: ";
    cin >> f3;
    cout << "Tests:" << endl;
    Fraction sum = f1 + f2 + f3;
    Fraction sub = f1 - f2 - f3;
    cout << "f1 + f2 + f3: " << sum << endl;
    cout << "f1 - f2 - f3: " << sub << endl;
    Fraction mul = f1 * f2 * f3;
    Fraction div = f1 / f2 / f3;
    cout << "f1 * f2 * f3: " << mul << endl;
    cout << "f1 / f2 / f3: " << div << endl;
    Fraction mix = ((f1 + f2) / f3) * f2;
    cout << "((f1 + f2) / f3) * f2: " << mix << endl;
  }
  else {
    for (;;) {
      Fraction f1, f2, f3;
      char op;
      cout << "Command: ";
      cin >> f1 >> op >> f2;
      if (op == '+') {
        f3 = f1 + f2;
      }
      else if (op == '-') {
        f3 = f1 - f2;
      }
      else if (op == '*') {
        f3 = f1 * f2;
      }
      else if (op == '/') {
        f3 = f1 / f2;
      }
      cout << "Result: " << f3 << endl;
    }
  }
  return 0;
}
