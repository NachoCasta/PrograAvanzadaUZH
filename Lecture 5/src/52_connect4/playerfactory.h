#pragma once

#include <iostream>
#include <ctime>
#include <list>
#include "player.h"
using namespace std;

typedef player* makeType(const char *);

class playerfactory {
  static list<makeType*> make_funs;
public:
  static void add(makeType *m);
  static player *make(const char *args);
};

template<class T>
struct playerfactoryhelper {
  playerfactoryhelper(makeType *m=(makeType*)&T::make) {
    playerfactory::add(m);
  }
};
