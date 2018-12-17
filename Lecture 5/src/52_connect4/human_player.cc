#include <iostream>
#include <ctime>
#include "human_player.h"
#include "playerfactory.h"
using namespace std;

player *human_player::make(const char *args) {
  if (args[0] == 'H' && args[1] == 'P') {
    human_player *p = new human_player((int)args[3]);
    cout << "Human player created!" << endl;
    return p;
  }
  return NULL;
}

static playerfactoryhelper<human_player> register_human_player;
