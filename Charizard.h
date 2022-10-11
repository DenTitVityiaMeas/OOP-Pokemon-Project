#ifndef CHARIZARD_H
#define CHARIZARD_H
#include <ctime>
#include <iostream>

#include "Pokemon.h"
using namespace std;

class Charizard : public Pokemon {
 public:
  Charizard(int H, int S, int E);
  int attack();
  int elementAttack();
  int charizardAction();
};
#endif