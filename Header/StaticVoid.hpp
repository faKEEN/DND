#ifndef  StaticVoid_hpp
#define  StaticVoid_hpp

#include "StaticObject.hpp"
#include "Monstre.hpp"
#include <vector>
#include "Position.hpp"
#include <iostream>

class StaticVoid: public StaticObject {
private:
  Position pos;
    bool visibility;
      int numSalle;

type_object type;
public:
  StaticVoid(Position p,int numSalle);
    StaticVoid(Position p);
   void affiche(ostream&  s);
   void setPosition(Position p);
   Position getPosition();
  type_object getType();
  void setNumSalle(int num);
   int getNumSalle();

   bool getVisibility();
   void setVisibility(bool v);

   virtual ~StaticVoid();


};

#endif
