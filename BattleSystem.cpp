#include "BattleSystem.h"

#include <string.h>

#include <ctime>
#include <iostream>

#include "Pokemonlist.h"

// Set the skill available to 1 which mean the third skill is ready to use
// Call the actionBoard that vary from fire,grass and water pokemon
// Actionboard function will create the options for user to pick from
int skillAvailable = 1;
int actionBoardG(int t, grassPokemon& C, Pokemon& S) {
  int option = 0;
  cout << endl;
  cout << "*******************************************************************"
       << endl;
  cout << "* Pick a Move:  " << endl;
  cout << "* 1. " << C.M1.getMoveName() << endl;
  cout << "* 2. " << C.M2.getMoveName() << endl;
  if (skillAvailable == 1) {
    cout << "* 3. " << C.M3.getMoveName() << endl;
  } else if (skillAvailable == 0) {
    cout << "* 3. This skill is already used!" << endl;
  };
  cout << "* 4. " << C.M4.getMoveName() << endl;
  cout << "Your choice: ";
  cin >> option;
  switch (option) {
    case 1:
      cout << "You use: " << C.M1.getMoveName() << endl;
      return pokemonMove(C, S, C.M1.getType(), C.M1.getPower());
      break;
    case 2:
      cout << "You use: " << C.M2.getMoveName() << endl;
      return pokemonMove(C, S, C.M2.getType(), C.M2.getPower());
      break;
    case 3:
      cout << "You use: " << C.M3.getMoveName() << endl;
      if (skillAvailable == 0) {
        cout << "**************************************************************"
                "*****";
        return 9;
      };
      skillAvailable = 0;
      return pokemonMove(C, S, C.M3.getType(), C.M3.getPower());
      break;
    case 4:
      cout << "You use: " << C.M4.getMoveName() << endl;
      return pokemonMove(C, S, C.M4.getType(), C.M4.getPower());
      break;
    default:
      cout << "****************************************************************"
              "***"
           << endl;
      cout << "WRONG INPUT! " << endl;
      return 10;
      break;
  }
  return 0;
}
int actionBoardW(int t, waterPokemon& C, Pokemon& S) {
  int option = 0;

  cout << endl;
  cout << "*******************************************************************"
       << endl;
  cout << "* Pick a Move:  " << endl;
  cout << "* 1. " << C.M1.getMoveName() << endl;
  cout << "* 2. " << C.M2.getMoveName() << endl;
  if (skillAvailable == 1) {
    cout << "* 3. " << C.M3.getMoveName() << endl;
  } else if (skillAvailable == 0) {
    cout << "* 3. This skill is already used!" << endl;
  };
  cout << "* 4. " << C.M4.getMoveName() << endl;
  cout << "Your choice: ";
  cin >> option;
  switch (option) {
    case 1:
      cout << "You use: " << C.M1.getMoveName() << endl;
      return pokemonMove(C, S, C.M1.getType(), C.M1.getPower());
      break;
    case 2:
      cout << "You use: " << C.M2.getMoveName() << endl;
      return pokemonMove(C, S, C.M2.getType(), C.M2.getPower());
      break;
    case 3:
      cout << "You use: " << C.M3.getMoveName() << endl;
      if (skillAvailable == 0) {
        cout << "**************************************************************"
                "*****";
        return 9;
      };
      skillAvailable = 0;
      return pokemonMove(C, S, C.M3.getType(), C.M3.getPower());
      break;
    case 4:
      cout << "You use: " << C.M4.getMoveName() << endl;
      return pokemonMove(C, S, C.M4.getType(), C.M4.getPower());
      break;
    default:
      cout << "****************************************************************"
              "***"
           << endl;
      cout << "WRONG INPUT! " << endl;
      return 10;
      break;
  }
  return 0;
}
int actionBoardF(int t, firePokemon& C, Pokemon& S) {
  int option = 0;
  cout << endl;
  cout << "*******************************************************************"
       << endl;
  cout << "* Pick a Move:  " << endl;
  cout << "* 1. " << C.M1.getMoveName() << endl;
  cout << "* 2. " << C.M2.getMoveName() << endl;
  if (skillAvailable == 1) {
    cout << "* 3. " << C.M3.getMoveName() << endl;
  } else if (skillAvailable == 0) {
    cout << "* 3. This skill is already used!" << endl;
  };
  cout << "* 4. " << C.M4.getMoveName() << endl;
  cout << "Your choice: ";
  cin >> option;
  if (option == 1) {
    cout << "You use: " << C.M1.getMoveName() << endl;
    return pokemonMove(C, S, C.M1.getType(), C.M1.getPower());
  } else if (option == 2) {
    cout << "You use: " << C.M2.getMoveName() << endl;
    int dmg = pokemonMove(C, S, C.M2.getType(), C.M2.getPower());
    return dmg;
  } else if (option == 3) {
    cout << "You use: " << C.M3.getMoveName() << endl;
    if (skillAvailable == 0) {
      cout << "**************************************************************"
              "*****";
      return 9;
    };
    skillAvailable = 0;
    return pokemonMove(C, S, C.M3.getType(), C.M3.getPower());
  } else if (option == 4) {
    cout << "You use: " << C.M4.getMoveName() << endl;
    return pokemonMove(C, S, C.M4.getType(), C.M4.getPower());
  } else {
    cout << "****************************************************************"
            "***"
         << endl;
    cout << "WRONG INPUT! " << endl;
    return 10;
  }
  return 0;
}
// Function pokeMove calculate the damage based on class and elements
// pokemMove is called inside actionBoard
// different types create different damage
int pokemonMove(Pokemon& C, Pokemon& S, string Type, int Power) {
  int damage = 1;
  if (Type.compare("Normal") == 0) {
    return 1;
  };
  if (Type.compare("Defense") == 0) {
    return 0;
  };
  if (Type.compare("Unique") == 0) {
    return C.M3.getPower();
  };
  if ((Type.compare("Element") == 0)) {
    if (C.getElement() == 1) {
      if (S.getElement() == 2) {
        cout << "Not effective" << endl;
        return C.M2.getPower() - damage;
      } else if (S.getElement() == 3) {
        cout << "Super effective" << endl;
        return C.M2.getPower() + damage;
      }
      return C.M2.getPower();
    }
    if (C.getElement() == 2) {
      if (S.getElement() == 1) {
        cout << "Not effective" << endl;
        return C.M2.getPower() - damage;
      } else if (S.getElement() == 3) {
        cout << "Super effective" << endl;
        return C.M2.getPower() + damage;
      }
      return C.M2.getPower();
    }
    if (C.getElement() == 3) {
      if (S.getElement() == 1) {
        cout << "Not effective" << endl;
        return C.M2.getPower() - damage;
      } else if (S.getElement() == 2) {
        cout << "Super effective" << endl;
        return C.M2.getPower() + damage;
      };
      return C.M2.getPower();
    }
  }
  return 0;
}

int enemyAction() {
  cout << "Normal Strike for 1 damage";
  return 1;
};
