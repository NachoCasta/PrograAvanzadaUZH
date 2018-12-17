#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace template_meta {
  template<int a, int b>
  struct gcd {
    static const int res = gcd<b, a % b>::res;
  };
  template<int a>
  struct gcd<a, 0> {
    static const int res = a;
  };

  template<int N>
  struct fib {
    static const int res = fib<N-1>::res + fib<N-2>::res;
  };
  template<>
  struct fib<1> {
    static const int res = 1;
  };
  template<>
  struct fib<0> {
    static const int res = 0;
  };
}

namespace constexpr_meta {
  constexpr int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
  }

  constexpr int fib(int n) {
    return n > 1 ? fib(n-1) + fib(n-2): (n == 1 ? 1 : 0);
  };
}

int main(int argc, char *argv[])
{
  cout << "GCD:" << endl;
  cout << template_meta::gcd<1071, 462>::res << endl;
  cout << constexpr_meta::gcd(1071, 462) << endl;

  cout << "Fibonacci:" << endl;
  cout << template_meta::fib<40>::res << endl;
  cout << constexpr_meta::fib(40) << endl;
  return 0;
}
