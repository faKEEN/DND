#ifndef Porte_hpp
#define Porte_hpp

#include "StaticObject.hpp"
#include "Monstre.hpp"
#include <vector>
#include "Position.hpp"
#include <iostream>

class Porte: public StaticObject {
private:

  Position pos;
  type_object type;
  int numSalle;
    bool visibility;
public:
    Porte(Position p,int numSalle);
        Porte(Position p);
    type_object getType();
    void affiche(ostream&  s);
    void setPosition(Position p);
    Position getPosition();
    void setNumSalle(int num);
    int getNumSalle();
    bool getVisibility();
    void setVisibility(bool v);
   virtual ~Porte();


};

#endif
