#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H
#include <iostream>

#include "Pokemon.h"
#include "firePokemon.h"
#include "grassPokemon.h"
#include "waterPokemon.h"
using namespace std;
int pokemonMove(Pokemon& C, Pokemon& S, string Type, int Power);
int actionBoardF(int t, firePokemon& C, Pokemon& S);
int actionBoardW(int t, waterPokemon& C, Pokemon& S);
int actionBoardG(int t, grassPokemon& C, Pokemon& S);
int enemyAction();

#endif