#pragma once

#include <iostream>
#include <ctime>
using namespace std;

template<typename F>
class human_player {
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
  int play(const F &field) {
    cout << "Column: ";
    int move;
    cin >> move;
    return move - 1;
  }
};

template<typename F>
class computer_player {
private:
  int player_number;
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

  int play(const F &field) {
    int col, row;
    for (col=0; col < field.width; col++) {
      row = get_row(col, field);
      if (row == -1) {
        continue;
      }
      if (row >= field.height)
      if (check_win(col, row, field)) {
        return col;
      }
    }
    cout << "Random" << endl;
    col = rand() % field.width;
    return col;
  }

  int get_row(int col, const F &field) {
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

  bool check_empty(const F &field) {
    for (int i=0; i < field.height; i++) {
      for (int j=0; j < field.width; j++) {
        if (field.stoneat(j, i) != field.none) {
          return false;
        }
      }
    }
    return true;
  }

  bool check_win(int x, int y, const F &field) {
    return check_horizontal(x, y, field) || check_vertical(x, y, field) || check_diagonal(x, y, field);
  }

  bool check_horizontal(int x, int y, const F &field) {
    int X = x;
    int Y = y;
    int stone;
    for (x=max(X-3, 0); x < min(X+1, field.width-3); x++) {
      for (; y < field.height; y++) {
        bool win = true;
        for (int i=0; i < 4; i++) {
          if (x+i == X && y == Y) {
            stone = player_number;
          }
          else {
            stone = field.stoneat(x+i, y);
          }
          if (stone != player_number) {
            win = false;
          }
        }
        if (win) {
          return true;
        }
      }
    }
    return false;
  }

  bool check_vertical(int x, int y, const F &field) {
    int X = x;
    int Y = y;
    int stone;
    for (; x < field.width; x++) {
      for (y=max(Y-3, 0); y < min(Y+1, field.height-3); y++) {
        bool win = true;
        for (int i=1; i < 4; i++) {
          if (x == X && y+i == Y) {
            stone = player_number;
          }
          else {
            stone = field.stoneat(x, y+i);
          }
          if (stone != player_number) {
            win = false;
          }
        }
        if (win) {
          return true;
        }
      }
    }
    return false;
  }

  bool check_diagonal(int x, int y, const F &field) {
    int X = x;
    int Y = y;
    int stone;
    for (x=max(X-3, 0); x < min(X+1, field.width-3); x++) {
      for (y=max(Y-3, 0); y < min(Y+1, field.height-3); y++) {
        bool win = true;
        for (int i=1; i < 4; i++) {
          if (x+i == X && y+i == Y) {
            stone = player_number;
          }
          else {
            stone = field.stoneat(x+i, y+i);
          }
          if (stone != player_number) {
            win = false;
          }
        }
        if (win) {
          return true;
        }
      }
    }
    for (x=max(X-3, 3); x < min(X+1, field.width-0); x++) {
      for (y=max(Y-3, 0); y < min(Y+1, field.height-3); y++) {
        bool win = true;
        for (int i=1; i < 4; i++) {
          if (x+i == X && y+i == Y) {
            stone = player_number;
          }
          else {
            stone = field.stoneat(x-i, y+i);
          }
          if (stone != player_number) {
            win = false;
          }
        }
        if (win) {
          return true;
        }
      }
    }
    return false;
  }


};
