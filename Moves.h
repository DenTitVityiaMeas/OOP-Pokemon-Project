#ifndef MOVES_H
#define MOVES_H
#include <iostream>
using namespace std;
class Moves {
 private:
  string moName;
  string Type;
  int Power;

 public:
  Moves();
  void setMoveName(string mName);
  void setMoveType(string mType);
  void setPower(int power);
  string getMoveName();
  string getType();
  int getPower();
  
};
#endif