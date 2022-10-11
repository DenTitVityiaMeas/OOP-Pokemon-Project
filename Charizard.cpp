#include <iostream>
#include "Charizard.h"
using namespace std;
 Charizard::Charizard(int H, int S, int E) {
    Health = H;
    Speed = S;
    Element = E;
  }
  
  int Charizard::attack() {
    srand(time(NULL));
    int attack = 1;
    cout << "You attacked for " << attack << " damage " << endl;
    return attack;
  }
  int Charizard::elementAttack(void) {
    srand(time(NULL));
    int elementAttack = 2;
    cout << "You used a special attack that deal" << elementAttack << " damage" << endl;
    return elementAttack;
  }
  int Charizard::charizardAction(void) {
    int option = 0;
    cout << endl;
    cout << "*******************************************" << endl;
    cout << "*     Pick an action:  " << endl;
    cout << "* 1.  Normal attack   " << endl;
    cout << "* 2.  Special attack   " << endl;
    cout << "* 3.  Swap (Not available)    " << endl;
    cout << "Your choice: ";
    cin >> option;
    cout << endl;

    switch (option) {
      case 1:
        return attack();
        break;

      case 2:
        return elementAttack();
        break;
      default:
        cout << "Wrong Input " << endl;
    }
    return 0;
  }
