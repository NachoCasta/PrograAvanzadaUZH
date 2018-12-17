#include "fraction.h"

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int Fraction::gcd(int a, int b) {
  if (a == 0) {
    return 1;
  }
  if (a < 0) {
    a *= -1;
  }
  while (a != b) {
    if (a > b)
      a -= b;
    else
      b -= a;
  }
  return a;
}

void Fraction::simplify() {
  int g = gcd(num, den);
  num = num / g;
  den = den / g;
}

Fraction::Fraction(int n, int d): num(n), den(d) {
  simplify();
}

Fraction Fraction::operator+ (Fraction other){
  Fraction f(num * other.den + other.num * den, abs(den * other.den));
  return f;
}

Fraction Fraction::operator- (Fraction other){
  Fraction f(num * other.den - other.num * den, abs(den * other.den));
  return f;
}

Fraction Fraction::operator* (Fraction other){
  Fraction f(num * other.num, den * other.den);
  return f;
}

Fraction Fraction::operator/ (Fraction other){
  Fraction f(num * other.den, other.num * den);
  return f;
}


ostream& operator<<(ostream& os, Fraction& f) {
  os << f.num << '/' << f.den;
  return os;
}

istream& operator>>(istream& is, Fraction& f) {
  char slash;

  is >> f.num >> slash >> f.den;
  f.simplify();

  return is;
}

int Fraction::get_num() {
  return num;
}

int Fraction::get_den() {
  return den;
}
