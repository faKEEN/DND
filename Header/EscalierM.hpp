#ifndef EscalierM_hpp
#define EscalierM_hpp

#include "StaticObject.hpp"
#include "Monstre.hpp"
#include <vector>
#include "Position.hpp"
#include <iostream>

class EscalierM: public StaticObject {
  Position pos;
  type_object type;
    bool visibility;
      int numSalle;
public:
    EscalierM(Position p,int numSalle);
    type_object getType();
    void affiche(ostream&  s);
    void setPosition(Position p);
    Position getPosition();
    void setNumSalle(int num);
     int getNumSalle();
     bool getVisibility();
     void setVisibility(bool v);
   virtual ~EscalierM();



};

#endif
