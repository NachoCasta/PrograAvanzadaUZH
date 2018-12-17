#pragma once

#include <iostream>
#include <ctime>
#include "playfield.h"
using namespace std;

class player {
public:
  virtual int play(const playfield &field) = 0;
  virtual ~player() {}
};
