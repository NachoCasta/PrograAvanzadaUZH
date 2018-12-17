#pragma once

#include <vector>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;

template<typename C, typename T>
struct merger_traits {
  int size(const C &c) { }
  C new_handler(int size) { }
  void add(C &c, T &element) { }
};

template<typename T>
struct merger_traits<vector<T>, T> {
  int size(const vector<T> &c) {
    return c.size();
  }

  vector<T> new_handler(int size) {
    vector<T> container;
    container.reserve(size);
    return container;
  }

  void add(vector<T> &c, T &element) {
    c.push_back(element);
  }
};

template<typename T>
struct merger_traits<set<T>, T> {
  int size(const set<T> &c) {
    return c.size();
  }

  vector<T> new_handler(int size) {
    set<T> container;
    return container;
  }

  void add(set<T> &c, T &element) {
    c.insert(element);
  }
};
