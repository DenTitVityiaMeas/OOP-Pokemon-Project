#ifndef FUNCTION_H
#define FUNCTION_H
#include <windows.h>

#include <iostream>

#include "Pokemon.h"
#include "firePokemon.h"
#include "grassPokemon.h"
#include "waterPokemon.h"

using namespace std;
void titleScreen();
void story();
void PokemonCreation();
void chooseCharizard();
void gameOver();
void winMessage(string P);
void enemyEncounter(string P);
void lineBreak();
void showHealth(int health);
void showSpeed(int speed);
void showElement(int element);
void showStats(int PH, int PS, int PE, int EH, int ES, int EE, string PN,
               string EN);
void welcomeScreen();
void battleF(int shot, int round, firePokemon& C, Pokemon& S, int option,
             string trainerName);
void battleW(int shot, int round, waterPokemon& C, Pokemon& S, int option,
             string trainerName);
void battleG(int shot, int round, grassPokemon& C, Pokemon& S, int option,
             string trainerName);
#endif