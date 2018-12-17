#pragma once

#include <iostream>
#include <string>
using namespace std;

class playfield {
public:
  // the size of the field
  const static int width=7;
  const static int height=6;
  // these elements are used to indicate whether a given position
  // in the playing field is taken by a given player
  const static int none=0;
  const static int player1=1;
  const static int player2=2;
protected:
  // the internal representation of the field
  char rep[playfield::width][playfield::height];
public:
  // return the stone (none/player1/player2) at the position(x,y)
  // 0 <= x <= width
  // 0 <= y <= height
  // stoneat(0,0) ................ top left
  // stoneat(width-1,height-1) ... bottom right
  // if we insert a stone in a new game in column i,
  // it lands at (i,height-1)
  // implementation may be changed, interface not
  int stoneat(int x, int y) const {
    char player = rep[x][y];
    if (player == 1) {
      return player1;
    }
    else if (player == 0) {
      return none;
    }
    else {
      return player2;
    }
  }

  int current_player = 1;
  string chars = " xo";

  playfield() {
    empty();
  }

  void empty() {
    for (int i=0; i < height; i++) {
      for (int j=0; j < width; j++) {
        rep[j][i] = none;
      }
    }
  }

  void print() {
    for (int i=0; i < height; i++) {
      cout << "|";
      for (int j=0; j < width; j++) {
        char player = rep[j][i];
        if (player == -1) {
          player = 2;
        }
        cout << " " << chars[player] << " " << "|";
      }
      cout << endl << "+";
      for (int j=0; j < width; j++) {
        cout << "---" << "+";
      }
      cout << endl;
    }
    cout << endl;
  }

  void put(int col) {
    int row = height-1;
    for (int i=0; i < height; i++) {
      if (rep[col][i] != none) {
        row = i-1;
        break;
      }
    }
    rep[col][row] = current_player;
    current_player *= -1;
  }

  bool check_win() {
    return check_vertical() || check_horizontal() || check_diagonal();
  }

  bool check_horizontal() {
    for (int x=0; x < width-3; x++) {
      for (int y=0; y < height; y++) {
        int counter = 0;
        for (int i=0; i < 4; i++) {
          counter += rep[x+i][y];
        }
        if (counter == 4 || counter == -4) {
          return true;
        }
      }
    }
    return false;
  }

  bool check_vertical() {
    for (int x=0; x < width; x++) {
      for (int y=0; y < height-3; y++) {
        int counter = 0;
        for (int i=0; i < 4; i++) {
          counter += rep[x][y+i];
        }
        if (counter == 4 || counter == -4) {
          return true;
        }
      }
    }
    return false;
  }

  bool check_diagonal() {
    for (int x=0; x < width-3; x++) {
      for (int y=0; y < height-3; y++) {
        int counter = 0;
        for (int i=0; i < 4; i++) {
          counter += rep[x+i][y+i];
        }
        if (counter == 4 || counter == -4) {
          return true;
        }
      }
    }
    for (int x=3; x < width; x++) {
      for (int y=0; y < height-3; y++) {
        int counter = 0;
        for (int i=0; i < 4; i++) {
          counter += rep[x-i][y+i];
        }
        if (counter == 4 || counter == -4) {
          return true;
        }
      }
    }
    return false;
  }

  bool check_full() {
    for (int x=0; x < width; x++) {
      for (int y=0; y < height-3; y++) {
        if (rep[x][y] == none) {
          return false;
        }
      }
    }
    return true;
  }

};
