#pragma once

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
class dumb_pointer {
private:
  T* data;
public:
  dumb_pointer(T* value): data(value) { }
  ~dumb_pointer() {
    delete data;
  }

  T& operator* () {
    return *data;
  }

  T* operator-> () {
    return data;
  }
};

class ReferenceCounter
{
private:
  int counter;
public:
  void addref() {
    counter++;
  }

  int release() {
    return --counter;
  }

  int get_counter() {
    return counter;
  }
};

template<typename T>
class smart_pointer {
private:
  T* data;
  ReferenceCounter* rc;
public:
  smart_pointer(T* value): data(value), rc(0) {
    rc = new ReferenceCounter();
    rc -> addref();
  }
  smart_pointer(const smart_pointer<T>& sp) : data(sp.data), rc(sp.rc) {
      rc -> addref();
  }
  ~smart_pointer() {
    if(rc -> release() == 0)
      {
        delete data;
        delete rc;
      }
  }

  smart_pointer<T>& operator = (const smart_pointer<T>& sp) {
    if (this != &sp) {
      if(rc -> release() == 0)
      {
          delete data;
          delete rc;
      }
      data = sp.data;
      rc = sp.rc;
      rc -> addref();
    }
    return *this;
  }


  T& operator* () {
    return *data;
  }

  T* operator-> () {
    return data;
  }

  int counter() {
    return rc -> get_counter();
  }
};

class Object {
public:
  int i;
  Object(int n): i(n) {}
  friend ostream& operator<<(ostream& os, Object& o) {
    os << "Object " << o.i;
    return os;
  }
  string method1() {
    return "method1 of object number " + to_string(i) + "; ";
  }
  string method2() {
    return "method2 of object number " + to_string(i) + "; ";
  }
  string method3() {
    return "method3 of object number " + to_string(i) + "; ";
  }
};
