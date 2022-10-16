#include "grassPokemon.h"
#include <iostream>
#include "Moves.h"
using namespace std;
grassPokemon::grassPokemon() : M1(), M2(), M3(), M4() {
  M1.setMoveName("Charge");
  M1.setMoveType("Normal");
  M1.setPower(1);

  M2.setMoveName("Bullet Seed");
  M2.setMoveType("Element");
  M2.setPower(2);

  M3.setMoveName("Leaf Storm");
  M3.setMoveType("Unique");
  M3.setPower(3);

  M4.setMoveName("Guard Up");
  M4.setMoveType("Defense");
  M4.setPower(4);
}