#include <iostream>
#include <vector>
#include <set>
#include "merger.h"
using namespace std;


int main(int argc, char *argv[])
{
  vector<int> c1;
  set<int> c2;

  c1.push_back(1);
  c1.push_back(1);
  c1.push_back(2);
  c1.push_back(5);

  c2.insert(10);
  c2.insert(12);
  c2.insert(11);

  vector<int> c3 = my_merge<int, vector<int>, set<int>>(c1, c2);

  for (const auto &s : c3){
    cout << s << endl;
  }

  return 0;
}
