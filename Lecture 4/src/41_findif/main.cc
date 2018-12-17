#include <iostream>
#include <chrono>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

#include "pvector.h"

int main(int argc, char *argv[])
{
  pvector<int> v("tmp/iterator.txt");
  vector<int>::iterator b=v.begin(), e=v.end();

  auto start = std::chrono::high_resolution_clock::now();

  cout << "Found: " << *find_if(b, e, bind2nd(greater<int>(), 4000000)) << endl;

  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "Elapsed time: " << elapsed.count() << " s\n";

  return 0;
}
