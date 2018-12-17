#include <iostream>
using namespace std;

#include "playfield.h"
#include "player.h"
#include "game.h"

int main(int argc, char *argv[])
{
  game<player, player, playfield> g;
  g.play_game();

  return 0;
}
