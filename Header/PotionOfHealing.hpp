//
//  PotionOfHealing.hpp
//
//
//  Created by Matthieu Jolo on 21/12/2017.
//
//

#ifndef PotionOfHealing_hpp
#define PotionOfHealing_hpp

#include <iostream>
#include "Object.hpp"
#include "Character.hpp"

using namespace std;

class PotionOfHealing: public Object {
public:
    PotionOfHealing();
    void affiche(ostream&  s);
    bool use(Character *character);
    bool remove(Character *character);
      void setPosition(Position p);
    Position getPosition();
      type_object getType();
      void setNumSalle(int num);
       int getNumSalle();
       bool getVisibility();
       void setVisibility(bool v);
      void setType(type_object t);
      int getValueObject();
    virtual ~PotionOfHealing();

private:
    Character *character;
    Position pos;
    const int life_point = 10;
      bool visibility;
        int numSalle;
    type_object type;
};

#endif /* PotionOfHealing_hpp */
