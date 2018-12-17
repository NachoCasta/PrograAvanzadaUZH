#include <iostream>
using namespace std;

void c_swap(int *x, int *y) {
  int z=*x;
  *x=*y;
  *y=z;
}

void swap(int &a, int &b) {
  int c=a;
  a=b;
  b=c;
}


int main(int argc, char *argv[])
{
  return 0;
}
