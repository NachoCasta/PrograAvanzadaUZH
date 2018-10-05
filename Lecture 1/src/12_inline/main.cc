#include <iostream>
using namespace std;


unsigned long long factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return factorial(n - 1) * n;
}

//__attribute__((always_inline))
inline unsigned long long inline_factorial(int n){
  if (n == 0) {
    return 1;
  }
  return inline_factorial(n - 1) * n;
}

int foo() {
  static int svar;
  svar++;
  return svar;
}

__attribute__((always_inline)) int inline_foo() {
  static int svar;
  svar++;
  return svar;
}

int main(int argc, char *argv[])
{
  /*
  unsigned long long n;
  cout << "Number: ";
  cin >> n;
  cout << factorial(n) << endl;
  cout << inline_factorial(n) << endl;
  */
  cout << foo() << endl;
  cout << foo() << endl;
  cout << foo() << endl;
  cout << inline_foo() << endl;
  cout << inline_foo() << endl;
  cout << inline_foo() << endl;
  cout << foo() << endl;
  cout << foo() << endl;
  cout << inline_foo() << endl;
  cout << inline_foo() << endl;
  return 0;
}
