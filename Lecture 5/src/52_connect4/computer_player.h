#pragma once

#include <iostream>
#include <ctime>
#include "playfield.h"
#include "player.h"
#include "playerfactory.h"
using namespace std;

class computer_player : public player {
private:
  int player_number;
  int enemy;
public:
  // returns the column where the player decides to throw in his
  // stone
  // F is the playfield which may be any playfield implementing
  // the stoneat method, if you expect a different class because
  // you need methods to verify whether the opponent can win,
  // copy the field into the class that you expect.
  computer_player(int pn=-1): player_number(pn) {
    int seed = static_cast<int>(time(0));
    srand(seed);
  }
  static player *make(const char *args);

  int play(const playfield &field) {
    int col, row;
    if (player_number == field.player1) {
      enemy = field.player2;
    }
    else {
      enemy = field.player1;
    }
    for (col=0; col < field.width; col++) {
      row = get_row(col, field);
      if (row == -1) {
        continue;
      }
      if (check_win(col, row, field, player_number)) {
        cout << "gano con " << col << endl;
        return col;
      }
    }
    for (col=0; col < field.width; col++) {
      row = get_row(col, field);
      if (row == -1) {
        continue;
      }
      if (check_win(col, row, field, enemy)) {
        cout << "pierdo con " << col << endl;
        return col;
      }
    }
    cout << "Random" << endl;
    col = rand() % field.width;
    return col;
  }

  int get_row(int col, const playfield &field) {
    if (field.stoneat(col, 0) != field.none) {
      return -1;
    }
    int row = field.height-1;
    for (int i=0; i < field.height; i++) {
      if (field.stoneat(col, i) != field.none) {
        row = i-1;
        break;
      }
    }
    return row;
  }

  bool check_empty(const playfield &field) {
    for (int i=0; i < field.height; i++) {
      for (int j=0; j < field.width; j++) {
        if (field.stoneat(j, i) != field.none) {
          return false;
        }
      }
    }
    return true;
  }

  bool check_win(int x, int y, const playfield &field, int pn) {
    return check_horizontal(x, y, field, pn) || check_vertical(x, y, field, pn) || check_diagonal(x, y, field, pn);
  }

  bool check_horizontal(int x, int y, const playfield &field, int pn) {
    int X = x;
    int stone;
    for (x=max(X-3, 0); x < min(X+1, field.width-3); x++) {
      bool win = true;
      for (int i=0; i < 4; i++) {
        if (x+i == X) {
          stone = pn;
        }
        else {
          stone = field.stoneat(x+i, y);
        }
        if (stone != pn) {
          win = false;
        }
      }
      if (win) {
        //cout << "Horizontal" << endl;
        return true;
      }
    }
    return false;
  }

  bool check_vertical(int x, int y, const playfield &field, int pn) {
    int Y = y;
    int stone;
    for (y=max(Y-3, 0); y < min(Y+1, field.height-3); y++) {
      bool win = true;
      for (int i=0; i < 4; i++) {
        if (y+i == Y) {
          stone = pn;
        }
        else {
          stone = field.stoneat(x, y+i);
        }
        if (stone != pn) {
          win = false;
        }
      }
      if (win) {
        //cout << "Vertical" << endl;
        return true;
      }
    }
    return false;
  }

  bool check_diagonal(int x, int y, const playfield &field, int pn) {
    int X = x;
    int Y = y;
    int stone;
    for (x=max(X-3, 0); x < min(X+1, field.width-3); x++) {
      for (y=max(Y-3, 0); y < min(Y+1, field.height-3); y++) {
        bool win = true;
        for (int i=0; i < 4; i++) {
          if (x+i == X && y+i == Y) {
            stone = pn;
          }
          else {
            stone = field.stoneat(x+i, y+i);
          }
          if (stone != pn) {
            win = false;
          }
        }
        if (win) {
          //cout << "Diagonal 1" << endl;
          return true;
        }
      }
    }
    for (x=max(X-3, 3); x < min(X+1, field.width-0); x++) {
      for (y=max(Y-3, 0); y < min(Y+1, field.height-3); y++) {
        bool win = true;
        for (int i=0; i < 4; i++) {
          if (x+i == X && y+i == Y) {
            stone = pn;
          }
          else {
            stone = field.stoneat(x-i, y+i);
          }
          if (stone != pn) {
            win = false;
          }
        }
        if (win) {
          //cout << "Diagonal 2" << endl;
          return true;
        }
      }
    }
    return false;
  }
};
