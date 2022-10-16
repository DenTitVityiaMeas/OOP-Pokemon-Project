#ifndef FIREPOKEMON_H
#define FIREPOKEMON_H
#include <ctime>
#include <iostream>
#include "Moves.h"
#include "Pokemon.h"

using namespace std;

class firePokemon: public Pokemon  {
public:
  Moves M1,M2,M3,M4;
  firePokemon();
  };
#endif
