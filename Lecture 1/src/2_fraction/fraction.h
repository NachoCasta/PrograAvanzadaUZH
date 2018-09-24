#pragma once

#include <iostream>
using namespace std;

class Fraction {
private:
  int num, den;
  int gcd(int a, int b);
  void simplify();
public:
  Fraction(int n=0, int d=1);
  Fraction operator+ (Fraction other);
  Fraction operator- (Fraction other);
  Fraction operator* (Fraction other);
  Fraction operator/ (Fraction other);
  friend ostream& operator<<(ostream& os, Fraction& f);
  friend istream& operator>>(istream& is, Fraction& f);
  int get_num();
  int get_den();
};
