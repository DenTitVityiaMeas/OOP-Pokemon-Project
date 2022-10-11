#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
using namespace std;

class Pokemon {
 protected:
  int Health;
  int Element;
  int Speed;

 public:
  Pokemon();
  Pokemon(int Health, int Element, int Speed);
  void takeDamage(int D);
  int getHealth(void);
  int getSpeed(void);
  int getElement(void);
 
};
#endif