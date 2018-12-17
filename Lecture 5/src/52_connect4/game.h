#pragma once

#include <iostream>
#include <string>
#include "player.h"
#include "playfield.h"
using namespace std;

template<typename PF>
class game {
private:
  PF pf;
  player* player1;
  player* player2;
public:
  game(player* player1, player* player2): player1(player1), player2(player2) {}
  void play_game() {
    pf.empty();
    int col;
    string actual;
    pf.print();
    while (!pf.check_win() && !pf.check_full()) {
      if (pf.current_player == 1) {
        actual = "1";
      }
      else {
        actual = "2";
      }
      cout << "It's player " << actual << "'s turn." << endl << endl;
      if (pf.current_player == 1) {
        col = player1 -> play(pf);
      }
      else {
        col = player2 -> play(pf);
      }
      cout << endl;
      pf.put(col);
      pf.print();
    }
    if (pf.check_full()) {
      cout << "Tie!" << endl;
    }
    else {
      cout << "Player " << actual << " wins." << endl;
    }
  }
};
