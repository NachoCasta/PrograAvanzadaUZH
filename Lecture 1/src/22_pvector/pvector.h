#pragma once

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
class pvector {
private:
  string filename;
  vector<T> v;
  void readvector() {
    ifstream ifs(filename);
    for(;;) {
      T x;
      ifs >> x;
      if(!ifs.good()) {
        break;
      }
      v.push_back(x);
    }
  };
  void writevector() {
    ofstream ofs(filename);
    for (const T &elem : v) {
      ofs << elem << endl;
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
