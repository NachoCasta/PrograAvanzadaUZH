#include <iostream>
#include <ctime>
#include "playfield.h"
#include "computer_player.h"
#include "playerfactory.h"
using namespace std;

player *computer_player::make(const char *args) {
    if (args[0] == 'C' && args[1] == 'P') {
      computer_player *p = new computer_player((int)args[3]);
      cout << "Computer player created!" << endl;
      return p;
    }
    return NULL;
}

static playerfactoryhelper<computer_player> register_computer_player;
