#ifndef  StaticWallV_hpp
#define  StaticWallV_hpp

#include "StaticObject.hpp"
#include "Monstre.hpp"
#include <vector>
#include "Position.hpp"
#include <iostream>

class StaticWallV: public StaticObject {
private:
  Position pos;
  type_object type;
    bool visibility;
      int numSalle;
public:

   void affiche(ostream&  s);
   StaticWallV(Position p,int numSalle);
   StaticWallV(Position p);
    type_object getType();
   void setPosition(Position p);
   Position getPosition();
   void setNumSalle(int num);
    int getNumSalle();

    bool getVisibility();
    void setVisibility(bool v);
   virtual ~StaticWallV();

};


#endif
