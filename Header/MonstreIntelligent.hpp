#ifndef MonstreIntelligent_hpp
#define MonstreIntelligent_hpp


#include <iostream>
#include "Monstre.hpp"
#include "Character.hpp"
#include "Object.hpp"
#include "Position.hpp"
#include "MoveState.hpp"
#include "ObjectWorld.hpp"
using namespace std;


class MonstreIntelligent: public Monstre {
private:
  int qi; // Resistance aux attaques


public:

MonstreIntelligent(Position p,ObjectWorld *obj,int level);
  void affiche(ostream& s);

  void attack(Character * c );
  void setQi(int q);
  int getQi();

 Position staticMove();
   Position followMove(char cmd);
 Position HasardMove();
 Position teleportMove();

    virtual ~MonstreIntelligent();

};


#endif
