#include <iostream>
#include "Pokemonlist.h"

using namespace std;
Charizard::Charizard() {
    Health = 10;
    Element = 2;
    Speed = 7;
    Name = "None";
}
void Charizard::setName(string nickname){Name=nickname;};
Blastoise::Blastoise() {
    Health = 10;
    Element = 1;
    Speed = 7;
   
  }
void Blastoise::setName(string nickname){Name=nickname;};
Bulbasaur::Bulbasaur() {
    Health = 10;
    Element = 3;
    Speed = 7;
    
  }
void Bulbasaur::setName(string nickname){Name=nickname;}
