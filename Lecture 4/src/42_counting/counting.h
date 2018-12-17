#pragma once

#include <iostream>
using namespace std;

template<typename T>
class counting_iterator : public std::iterator<std::forward_iterator_tag, T> {
private:
  T itr;
public:
  counting_iterator(T n): itr(n) {};
  counting_iterator& operator++ () { // Pre-increment
      ++itr;
      return *this;
  }

  counting_iterator operator++ (int) { // Post-increment
      T tmp = itr;
      itr++;
      return tmp;
  }

  bool operator == (const counting_iterator<T>& rhs) const {
      return itr == rhs.itr;
  }
  bool operator != (const counting_iterator<T>& rhs) const {
      return itr != rhs.itr;
  }
  T& operator* () {
      return itr;
  }

  T& operator-> () const {
      return itr;
  }
};

template<typename T>
counting_iterator<T> counter(const T &t) {
  return counting_iterator<T>(t);
}
