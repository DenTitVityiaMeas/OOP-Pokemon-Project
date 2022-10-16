#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <windows.h>
#include "Pokemon.h"
#include "Moves.h"
#include "Function.h"
Pokemon::Pokemon():M1(),M2(),M3(),M4(){
    Health = 0;
    Element = 2;
    Speed = 0;    
    M1.setMoveName("Normal attack");
    M1.setMoveType("Normal");
    M1.setPower(1);

    M2.setMoveName("Element attack");
    M2.setMoveType("Element");
    M2.setPower(2);

    M3.setMoveName("Unique attack");
    M3.setMoveType("Unique");
    M3.setPower(3);

    M4.setMoveName("Defense");
    M4.setMoveType("Defense");
    M4.setPower(4);
}
Pokemon::Pokemon(int Health1,int Element1,int Speed1,string Name1,int Armor1){
    this->Health = Health1;
    this->Element = Element1;
    this->Speed = Speed1;
    this->Name = Name1;
    this->Armor = Armor1;
} 
void Pokemon::takeDamage(int D) { Health = Health + Armor - D; }
int Pokemon::getHealth() { return Health; }
int Pokemon::getSpeed() { return Speed; }
int Pokemon::getElement() { return Element; }
string Pokemon::getName(){return Name;}
void Pokemon::setArmor(int Armor1){Armor=Armor1;};
int Pokemon::getArmor(){return Armor;};





