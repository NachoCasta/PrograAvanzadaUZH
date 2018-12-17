#pragma once

#include <iostream>
#include "traits.h"

template<template <typename> class C1, template <typename> class C2, typename T, typename T1=merger_traits<C1<T>, T>, typename T2=merger_traits<C2<T>, T>>
C1<T> my_merge(const C1<T> &c1, const C2<T> &c2) {
  typedef T1 merger1;
  typedef T2 merger2;
  int size = merger1::size(c1) + merger2::size(c2);
  C1<T> container = merger1::new_handler(size);
  for (const T &e : c1){
    merger1::add(container, e);
  }
  for (const T &e : c2){
    merger1::add(container, e);
  }
  return container;
}
