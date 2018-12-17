#include <iostream>
#include <complex>
#include <vector>
using namespace std;

template<typename T>
class Stack {
private:
  int sp;
  T* buf;
public:
  Stack(): sp(256) {
    buf = new T[256];
  }
  virtual void push(T i) {
    buf[--sp] = i;
  }
  virtual int pop() {
    return buf[sp++];
  }
  virtual int empty() { return sp == 256; }
  void setBuf(T* newbuf) { buf = newbuf; }
  T* getBuf() { return buf; }
  void deleteBuf() { delete [] buf; }
  int getSp() { return sp; }
  void setSp(int newValue) { sp = newValue; }
};

template<typename T>
class UnlimitedStack : public Stack<T> {
private:
  int size;
  void changeSize(int newsize) {
    int *newbuf = new T[newsize];
    copy( Stack<T>::getBuf(), Stack<T>::getBuf()+size, newbuf+size );
    Stack<T>::deleteBuf();
    Stack<T>::setBuf(newbuf);
    Stack<T>::setSp(Stack<T>::getSp() + size);
    size = newsize;
  }
public:
  UnlimitedStack(): size(256) {
    Stack<T>();
  }
  void push(T i) {
    Stack<T>::push(i);
    if (Stack<T>::getSp() == 0) {
      changeSize(size*2);
    }
  }
  int empty() { return Stack<T>::getSp() == size; }
};

void bad_print(Stack<int> s) {
  while (!s.empty()) {
    cout << s.pop() << endl;
  }
}

void good_print(Stack<int>* s) {
  while (!s->empty()) {
    cout << s->pop() << endl;
  }
}

int main(int argc, char *argv[])
{
  UnlimitedStack<int> us;
  int i = 0;
  for (; i < 300; i++) {
    us.push(i);
  }
  good_print(&us);
  //bad_print(us);
  return 0;
}
