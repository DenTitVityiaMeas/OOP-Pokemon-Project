#include "Function.h"

#include <windows.h>

#include <iostream>

#include "BattleSystem.h"
#include "Pokemon.h"
#include "Pokemonlist.h"
using namespace std;
void titleScreen() { cout << "Title screen!" << endl; }
void story() {
  cout << "You are walking around then a pokemon show up(Geninja)!" << endl;
}
void PokemonCreation() {
  cout << "Choose a pokemon: " << endl;
  cout << "1. Charizard" << endl;
  cout << "2. Blastoise" << endl;
  cout << "3. Bulbasaur" << endl;
  cout << "Your choice: ";
}
void gameOver() { cout << "game over" << endl; }
void winMessage(string P) { cout << P << " wins!" << endl; }
void enemyEncounter(string P) {
  cout << "Encounter " << P << endl;
  cout << "*******************************************************************"
       << endl;
}
void lineBreak() {
  cout << "*******************************************************************"
       << endl;
}

// This function print out the stats of pokemon
void showHealth(int health) {
  int hearts = health;
  cout << "Health [";
  for (int i = 0; i < hearts; i++) {
    cout << "o ";
  }
  cout << "]: " << health;
}

void showSpeed(int speed) {
  cout << "Speed  [";
  for (int i = 0; i < speed; i++) {
    cout << "o ";
  }
  cout << "]: " << speed;
}

void showElement(int element) {
  if (element == 1) {
    cout << "Element: Water";
  } else if (element == 2) {
    cout << "Element: Fire";
  } else if (element == 3) {
    cout << "Element: Grass";
  }
}

void showStats(int PH, int PS, int PE, int EH, int ES, int EE, string PN,
               string EN) {
  cout << "Your Pokemon: " << PN << endl;
  showHealth(PH);
  cout << endl;
  showSpeed(PS);
  cout << endl;
  showElement(PE);
  cout << endl;
  cout << "*******************************************************************"
       << endl;
  cout << "Wild Pokemon: " << EN << endl;
  showHealth(EH);
  cout << endl;
  showSpeed(ES);
  cout << endl;
  showElement(EE);
  cout << endl;
  cout << "*******************************************************************";
  cout << endl;
}

void welcomeScreen(void) {
  titleScreen();
  Sleep(3);
  story();
  lineBreak();
  Sleep(3);
  PokemonCreation();
}
// battle functions which gets the stats of pokemon then call actionBoard to
// stimulate the fight also output different message according to the input
void battleG(int shot, int round, grassPokemon& C, Pokemon& S, int option,
             string trainerName) {
  int k = round;
  enemyEncounter(S.getName());
  int hea = C.getHealth();
  while (hea > 0 && S.getHealth() > 0) {
    showStats(hea, C.getSpeed(), C.getElement(), S.getHealth(), S.getSpeed(),
              S.getElement(), C.getName(), S.getName());
    if (C.getSpeed() >= S.getSpeed()) {
      int d = actionBoardG(shot, C, S, option, trainerName);
      while (d == 10) {
        cout << "Please pick a right move!" << endl;
        d = actionBoardG(shot, C, S, option, trainerName);
        break;
      }

      while (d == 9) {
        cout << endl << "THIS SKILL IS NOT AVAILABLE!" << endl;
        d = actionBoardG(shot, C, S, option, trainerName);
        break;
      }
      if (d == 0) {
        S.takeDamage(d);
        cout << endl;
        cout << "EMEMY MOVE BLOCKED! " << endl;
        C.setArmor(1);
        hea = hea + C.getArmor() - enemyAction();
        C.setArmor(0);
      } else {
        S.takeDamage(d);
        cout << "EMEMY MOVE: ";
        hea = hea - enemyAction();
      }
      cout << endl;
      lineBreak();
      cout << "END ROUND: " << k << endl;
      lineBreak();
      if (hea != 0 && S.getHealth() != 0) {
        cout << "START ROUND: " << k + 1 << endl;
      }
    } else {
      int g = 0;
      cout << "Enemy turn!" << endl;
      cout << "EMEMY MOVE: ";
      hea = hea - enemyAction();
      cout << endl;
      int m = actionBoardG(shot, C, S, option, trainerName);
      if (m == 0) {
        S.takeDamage(m);
        cout << "Your Pokemon choose defense";
        C.setArmor(1);
      } else {
        S.takeDamage(m);
      }
      cout << endl;
      lineBreak();
      cout << "END ROUND: " << k << endl;
      lineBreak();
      if (hea != 0 && S.getHealth() != 0) {
        cout << "START ROUND: " << k + 1 << endl;
      }
    }
    if (C.getHealth() >= 0 && S.getHealth() <= 0) {
      winMessage(C.getName());
    } else if (S.getHealth() >= 0 && C.getHealth() <= 0) {
      winMessage(S.getName());
      gameOver();
    };
    break;
  }
}
void battleW(int shot, int round, waterPokemon& C, Pokemon& S, int option,
             string trainerName) {
  int k = round;
  enemyEncounter(S.getName());
  int hea = C.getHealth();
  while (hea > 0 && S.getHealth() > 0) {
    showStats(hea, C.getSpeed(), C.getElement(), S.getHealth(), S.getSpeed(),
              S.getElement(), C.getName(), S.getName());
    if (C.getSpeed() >= S.getSpeed()) {
      int d = actionBoardW(shot, C, S, option, trainerName);
      while (d == 10) {
        cout << "Please pick a right move!" << endl;
        d = actionBoardW(shot, C, S, option, trainerName);
        break;
      }
      while (d == 9) {
        cout << endl << "THIS SKILL IS NOT AVAILABLE!" << endl;
        d = actionBoardW(shot, C, S, option, trainerName);
        break;
      }
      if (d == 0) {
        S.takeDamage(d);
        cout << endl;
        cout << "EMEMY MOVE BLOCKED! " << endl;
        C.setArmor(1);
        hea = hea + C.getArmor() - enemyAction();
        C.setArmor(0);
      } else {
        S.takeDamage(d);
        cout << "EMEMY MOVE: ";
        hea = hea - enemyAction();
      };
      cout << endl;
      lineBreak();
      cout << "END ROUND: " << k << endl;
      lineBreak();
      if (hea != 0 && S.getHealth() != 0) {
        cout << "START ROUND: " << k + 1 << endl;
      }
    } else {
      int g = 0;
      cout << "Enemy turn!" << endl;
      cout << "EMEMY MOVE: ";
      hea = hea - enemyAction();
      cout << endl;
      int m = actionBoardW(shot, C, S, option, trainerName);
      if (m == 0) {
        S.takeDamage(m);
        cout << "Your Pokemon choose defense";
        C.setArmor(1);
      } else {
        S.takeDamage(m);
      }
      cout << endl;
      lineBreak();
      cout << "END ROUND: " << k << endl;
      lineBreak();
      if (hea != 0 && S.getHealth() != 0) {
        cout << "START ROUND: " << k + 1 << endl;
      }
    }

    if (C.getHealth() >= 0 && S.getHealth() <= 0) {
      winMessage(C.getName());
    } else if (S.getHealth() >= 0 && C.getHealth() <= 0) {
      winMessage(S.getName());
      gameOver();
    };
    break;
  }
}
void battleF(int shot, int round, firePokemon& C, Pokemon& S, int option,
             string trainerName) {
  int hea = C.getHealth();
  int k = round;
  enemyEncounter(S.getName());
  // int hea= C.getHealth();
  while (hea > 0 && S.getHealth() > 0) {
    showStats(hea, C.getSpeed(), C.getElement(), S.getHealth(), S.getSpeed(),
              S.getElement(), C.getName(), S.getName());
    if (C.getSpeed() >= S.getSpeed()) {
      int d = actionBoardF(shot, C, S, option, trainerName);
      while (d == 10) {
        cout << "Please pick a right move!" << endl;
        d = actionBoardF(shot, C, S, option, trainerName);
        break;
      }
      while (d == 9) {
        cout << endl << "THIS SKILL IS NOT AVAILABLE!" << endl;
        d = actionBoardF(shot, C, S, option, trainerName);
        break;
      }
      if (d == 0) {
        S.takeDamage(d);
        cout << endl;
        cout << "EMEMY MOVE BLOCKED! " << endl;
        C.setArmor(1);
        hea = hea + C.getArmor() - enemyAction();
        C.setArmor(0);
      } else {
        S.takeDamage(d);
        cout << "EMEMY MOVE: ";
        hea = hea - enemyAction();
      };
      cout << endl;
      lineBreak();
      cout << "END ROUND: " << k << endl;
      lineBreak();
      if (hea != 0 && S.getHealth() != 0) {
        cout << "START ROUND: " << k + 1 << endl;
      }
    } else {
      int g = 0;
      cout << "Enemy turn!" << endl;
      cout << "EMEMY MOVE: ";
      hea = hea - enemyAction();
      cout << endl;
      int m = actionBoardF(shot, C, S, option, trainerName);
      if (m == 0) {
        S.takeDamage(m);
        cout << "Your Pokemon choose defense";
        C.setArmor(1);
      } else {
        S.takeDamage(m);
      }
      cout << endl;
      lineBreak();
      cout << "END ROUND: " << k << endl;
      lineBreak();
      if (hea != 0 && S.getHealth() != 0) {
        cout << "START ROUND: " << k + 1 << endl;
      };
    }

    if (hea >= 0 && S.getHealth() <= 0) {
      winMessage(C.getName());
    } else if (S.getHealth() >= 0 && hea <= 0) {
      winMessage(S.getName());
      gameOver();
    };
    break;
  }
}
