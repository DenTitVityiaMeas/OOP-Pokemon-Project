#ifndef GRASSPOKEMON_H
#define GRASSPOKEMON_H
#include <ctime>
#include <iostream>
#include "Moves.h"
#include "Pokemon.h"
using namespace std;
class grassPokemon: public Pokemon  {
public:
  Moves M1,M2,M3,M4;
  grassPokemon();
  };
#endif