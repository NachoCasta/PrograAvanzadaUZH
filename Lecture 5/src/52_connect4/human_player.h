#pragma once

#include <iostream>
#include <ctime>
#include "playfield.h"
#include "player.h"
#include "playerfactory.h"
using namespace std;

class human_player : public player {
private:
  int player_number;
public:
  human_player(int pn=0): player_number(pn) { }
  // returns the column where the player decides to throw in his
  // stone
  // F is the playfield which may be any playfield implementing
  // the stoneat method, if you expect a different class because
  // you need methods to verify whether the opponent can win,
  // copy the field into the class that you expect.
  int play(const playfield &field) {
    cout << "Column: ";
    int move;
    cin >> move;
    return move - 1;
  }
  static player *make(const char *args);
};
