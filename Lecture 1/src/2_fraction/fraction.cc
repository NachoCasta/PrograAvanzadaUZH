// Importo el archivo arraylist.h
#include "fraction.h"

Fraction::Fraction(int n, int d): num(n), den(d) { }

int Fraction::getNum() {
  return num;
}

int Fraction::getDen() {
  return den;
}
