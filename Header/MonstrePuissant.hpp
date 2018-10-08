#ifndef MonstrePuissant_hpp
#define MonstrePuissant_hpp


#include <iostream>
#include "Monstre.hpp"
#include "Character.hpp"
#include "Object.hpp"
#include "Position.hpp"
#include "MoveState.hpp"
#include "ObjectWorld.hpp"
using namespace std;


class MonstrePuissant: public Monstre {
private:
  int powerbonus; // Resistance aux attaques



public:

MonstrePuissant(Position p,ObjectWorld *obj,int level);
  void affiche(ostream& s);

  void attack(Character * c );
  void setpowerbonus(int pwb);
  int getpowerbonus();

   Position staticMove();
   Position followMove(char cmd);
   Position HasardMove();
   Position teleportMove();

    virtual ~MonstrePuissant();

};


#endif
