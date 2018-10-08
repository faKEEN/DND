#ifndef MonstreResistant_hpp
#define MonstreResistant_hpp
#include <iostream>
#include "Monstre.hpp"
#include "Character.hpp"
#include "Object.hpp"
#include "Position.hpp"
#include "MoveState.hpp"
#include "ObjectWorld.hpp"
using namespace std;


class MonstreResistant: public Monstre {
private:
  int armor; // Resistance aux attaques

public:

MonstreResistant(Position p,ObjectWorld *obj,int level);
   void affiche(ostream& s);

  void attack(Character * );
  void setArmor(int arm);
  int getArmor();

   Position staticMove();
   Position followMove(char cmd);
   Position HasardMove();
   Position teleportMove();

  virtual ~MonstreResistant();

};


#endif
