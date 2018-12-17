#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "counting.h"

template<typename T>
struct print {
  void operator()(T elem) const {
      cout << elem << endl;
  }
};

void foo() {
  cout << "create vector with ints from [0..10)" << endl;
  vector<int> v(counter(0), counter(10));
  for (auto &elem : v) {
    cout << elem << endl;
  }
  cout << "print ints from [10..20)" << endl;
  for_each(counter(10), counter(20), print<int>());
}

int main(int argc, char *argv[])
{
  foo();
  return 0;
}
