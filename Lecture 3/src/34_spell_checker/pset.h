#pragma once

#include <iostream>
#include <fstream>
#include <set>
#include "traits.h"
using namespace std;

template<typename T, typename P=persistence_traits<T>>
class pset {
private:
  typedef P persister;
  string filename;
  set<T> s;
  void readvector() {
    ifstream ifs(filename);
    for(;;) {
      T x;
        persister::read(ifs, x);
      if(!ifs.good()) {
        break;
      }
      s.insert(x);
    }
  };
  void writevector() {
    ofstream ofs(filename);
    for (const T &elem : s) {
      persister::write(ofs, elem);
    }
  };
public:
  pset(string fname) : filename(fname) { readvector(); }
  ~pset() { writevector(); }
  void insert(const T &el) { s.insert(el); }
  void erase(const T &el) { s.erase(el); }
  int size() { return s.size(); }
  int in(const T &el) { return s.count(el); }
  T &operator[] (int i) { return s[i]; }
};
