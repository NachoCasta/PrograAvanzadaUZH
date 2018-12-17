#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include "traits.h"
using namespace std;

template<typename T, typename P=persistence_traits<T>>
class pvector {
private:
  typedef P persister;
  string filename;
  vector<T> v;
  void readvector() {
    ifstream ifs(filename);
    for(;;) {
      T x;
      persister::read(ifs, x);
      if(!ifs.good()) {
        break;
      }
      v.push_back(x);
    }
  };
  void writevector() {
    ofstream ofs(filename);
    for (const T &elem : v) {
      persister::write(ofs, elem);
    }
  };
public:
  pvector(string fname) : filename(fname) { readvector(); }
  ~pvector() { writevector(); }
  void push_back(const T &el) { v.push_back(el); }
  void pop_back() { v.pop_back(); }
  int size() { return v.size(); }
  T &operator[] (int i) { return v[i]; }
};

void foo(pvector<int> pv);
