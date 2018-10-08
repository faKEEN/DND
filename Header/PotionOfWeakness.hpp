//
//  PotionOfWeakness.hpp
//  DND
//
//  Created by Matthieu Jolo on 28/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#ifndef PotionOfWeakness_h
#define PotionOfWeakness_h
#include <iostream>
#include "Object.hpp"
#include "Character.hpp"

class PotionOfWeakness: public Object {
public:
    PotionOfWeakness();
    type_object getType();
    void affiche(ostream&  s);
    bool use(Character *character);
    bool remove(Character *character);
    void setPosition(Position p);
    Position getPosition();
    void setNumSalle(int num);
    int getNumSalle();
    bool getVisibility();
    void setVisibility(bool v);
    int getValueObject();
    virtual ~PotionOfWeakness() ;
private:
    Position pos;
    type_object type;
    Character *character;
    bool visibility;
    int numSalle;
    const int weakness_point = 5;
};


#endif /* PotionOfWeakness_h */
