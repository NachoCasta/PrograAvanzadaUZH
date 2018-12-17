#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class Fraction {
private:
  int gcd(int a, int b);
  int num, den;
  void simplify();
public:
  Fraction(int n=0, int d=1);
  Fraction operator+ (Fraction other);
  Fraction operator- (Fraction other);
  Fraction operator* (Fraction other);
  Fraction operator/ (Fraction other);
  bool operator< (Fraction other);
  friend ostream& operator<<(ostream& os, Fraction& f);
  friend ofstream& operator<<(ofstream& os, const Fraction& f);
  friend istream& operator>>(istream& is, Fraction& f);
  int get_num();
  int get_den();
};
