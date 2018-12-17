#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void lock(string fn, string mode) { // fn being the file name
  cout << "Locking file with fn = " << fn << " in mode " << mode << endl;
}

void unlock(string fn) {
  cout << "Unlocking file with fn = " << fn << endl;
}

class FileLocker {
private:
  string fn;
public:
  FileLocker(string fn, string mode) : fn(fn) {
    lock(fn, mode);
  }
  ~FileLocker() {
    unlock(fn);
  }
};
