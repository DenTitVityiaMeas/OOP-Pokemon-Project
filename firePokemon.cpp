#include "firePokemon.h"

#include <iostream>

#include "Moves.h"
using namespace std;
// create a class of firePokemon with different moves
firePokemon::firePokemon() : M1(), M2(), M3(), M4() {
  Health = 1;
  Element = 2;
  Speed = 7;
    
  M1.setMoveName("Bite");
  M1.setMoveType("Normal");
  M1.setPower(1);

  M2.setMoveName("Fire Spray");
  M2.setMoveType("Element");
  M2.setPower(2);

  M3.setMoveName("Fire Burst");
  M3.setMoveType("Unique");
  M3.setPower(3);

  M4.setMoveName("Guard Up");
  M4.setMoveType("Defense");
  M4.setPower(4);
}