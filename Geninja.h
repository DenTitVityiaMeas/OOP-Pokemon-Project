#ifndef GENINJA_H
#define GENINJA_H
#include <ctime>
#include <iostream>

#include "Pokemon.h"
using namespace std;

class Geninja : public Pokemon {
 public:
  Geninja(int H, int S, int E);
  int attack();
  int specialAttack();
  int enemyAction();

};
#endif