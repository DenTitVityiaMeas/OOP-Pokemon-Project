#ifndef WATERPOKEMON_H
#define WATERPOKEMON_H
#include <ctime>
#include <iostream>
#include "Moves.h"
#include "Pokemon.h"

using namespace std;

class waterPokemon: public Pokemon  {
public:
  Moves M1,M2,M3,M4;
  waterPokemon();
  };
#endif