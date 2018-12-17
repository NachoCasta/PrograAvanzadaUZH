#include <iostream>
#include <ctime>
#include <list>
#include "player.h"
#include "playerfactory.h"
using namespace std;

list<makeType*> playerfactory::make_funs;

void playerfactory::add(makeType *m) {
  cout << "before error" << endl;
  make_funs.push_back(m);
  cout << "after error" << endl;
}

player *playerfactory::make(const char *args) {
  for (makeType *make_fun : make_funs) {
    player *s = make_fun(args);
    if (s) return s;
    cout << "Make function not found." << endl;
  }
  return NULL;
}
