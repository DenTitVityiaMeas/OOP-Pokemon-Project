 #include <iostream>
 #include <ctime>
 #include "Moves.h"
 using namespace std;

Moves::Moves(){
    moName = "None";
    Type = "Normal";
    Power = 10;
};
void Moves::setMoveName(string mName){moName=mName;};
string Moves::getMoveName(){return moName;};
string Moves::getType(){return Type;}; 
int Moves::getPower(){return Power;};
void Moves::setMoveType(string mType){Type=mType;};
void Moves::setPower(int power){Power=power;};