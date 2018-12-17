#include <iostream>
#include <complex>
#include <vector>
using namespace std;

class Grandfather {
private:
public:
  Grandfather() {
    cout << "Grandfather was born." << endl;
  }
  ~Grandfather() {
    cout << "Grandfather was killed." << endl;
  }
};

class Grandmother {
private:
public:
  Grandmother() {
    cout << "Grandmother was born." << endl;
  }
  ~Grandmother() {
    cout << "Grandmother was killed." << endl;
  }
};

class Father : public Grandfather, Grandmother {
private:
public:
  Father() {
    cout << "  Father was born." << endl;
  }
  ~Father() {
    cout << "  Father was killed." << endl;
  }
};

class Mother : public Grandfather, Grandmother {
private:
public:
  Mother() {
    cout << "  Mother was born." << endl;
  }
  ~Mother() {
    cout << "  Mother was killed." << endl;
  }
};

class Son : public Father, Mother {
private:
public:
  Son() {
    cout << "    Son was born." << endl;
  }
  ~Son() {
    cout << "    Son was killed." << endl;
  }
};

int main(int argc, char *argv[])
{
  Son son;
  return 0;
}
