// Importo el archivo arraylist.h
#include "pvector.h"

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

void foo(pvector<int> pv) {
  pv.push_back(17);
  if(pv.size()>0) {
    for (int i = 0; i < pv.size(); i++) {
      cout << pv[i] << endl;
    }
  }
}
