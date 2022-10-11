#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <unistd.h>
#include <windows.h>
#include "Pokemon.h"
#include "Function.h"
Pokemon::Pokemon(){
    Health = 0;
    Element = 1;
    Speed = 0;    
}
Pokemon::Pokemon(int Health1,int Element1,int Speed1){
    this->Health = Health1;
    this->Element = Element1;
    this->Speed = Speed1;
}

void Pokemon::takeDamage(int D) { Health = Health - D; }
int Pokemon::getHealth(void) { return Health; }
int Pokemon::getSpeed(void) { return Speed; }
int Pokemon::getElement(void) { return Element; }







