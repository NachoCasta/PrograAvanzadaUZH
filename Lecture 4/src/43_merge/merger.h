#pragma once

#include "traits.h"

template<typename T, typename C1, typename C2, typename T1=merger_traits<C1, T>, typename T2=merger_traits<C2, T>>
C1 my_merge(const C1 &c1, const C2 &c2) {
  T1 merger1;
  T2 merger2;
  int size = merger1.size(c1) + merger2.size(c2);
  C1 container = merger1.new_handler(size);
  for (const T &e : c1){
    merger1.add(container, e);
  }
  for (const T &e : c2){
    merger1.add(container, e);
  }
  return container;
}
