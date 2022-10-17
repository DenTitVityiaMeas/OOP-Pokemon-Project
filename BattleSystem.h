#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H
#include <iostream>

#include "Pokemon.h"
#include "firePokemon.h"
#include "grassPokemon.h"
#include "stdInclude.h"
#include "waterPokemon.h"
using namespace std;
void BattleField(string trainerName);
int pokemonMove(Pokemon& C, Pokemon& S, string Type, int Power);
int actionBoardF(int shot, firePokemon& C, Pokemon& S, int option,
                 string trainName);
int actionBoardW(int shot, waterPokemon& C, Pokemon& S, int option,
                 string trainName);
int actionBoardG(int shot, grassPokemon& C, Pokemon& S, int option,
                 string trainName);
int enemyAction();

#endif