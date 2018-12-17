#include <iostream>
using namespace std;
#include "human_player.h"
#include "computer_player.h"
#include "playerfactory.h"
#include "playfield.h"
#include "game.h"

int main(int argc, char *argv[])
{
  cout << "1" << endl;
  player* p1 = playerfactory::make("H(1)");
  cout << "2" << endl;
  player* p2 = playerfactory::make("C(2)");
  cout << "3" << endl;
  game<my_playfield> g(p1, p2);
  g.play_game();

  return 0;
}
