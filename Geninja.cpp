#include <iostream>
#include "Geninja.h"

using namespace std;
Geninja::Geninja(int H, int S, int E) {
    Health = H;
    Speed = S;
    Element = E;
  }
  int Geninja::attack(void) {
    srand(time(NULL));
    int attack = 1;
    cout << "Genninja strikes you for" << attack << " damage" << endl;
    return attack;
  }
  int Geninja::specialAttack(void) {
    srand(time(NULL));
    int specialDamage = 2;
    cout << "Genninja use special attack " << specialDamage << " damage "
         << endl;
    Health = Health - 5;
    return specialDamage;
  }

  int Geninja::enemyAction() {
    srand(time(NULL));
    int action = 1 + (rand() % 3);
    if (action == 1) {
      return attack();
    }

    if (action == 2) {
      return specialAttack();
    }
    return 0;
  };
