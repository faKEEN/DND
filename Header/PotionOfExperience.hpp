//
//  PotionOfExperience.hpp
//
//
//  Created by Matthieu Jolo on 26/12/2017.
//
//


#ifndef PotionOfExperience_hpp
#define PotionOfExperience_hpp

#include <stdio.h>
#include "Object.hpp"
#include "Character.hpp"

using namespace std;


class PotionOfExperience: public Object {

public:
    PotionOfExperience();
    type_object getType();
    void affiche(ostream&  s);
    bool use(Character *character);
    bool remove(Character *character);
    void setPosition(Position p);
    Position pos;
    Position getPosition();
    void setNumSalle(int num);
    int getNumSalle();
    bool getVisibility();
    void setVisibility(bool v);
    int getValueObject();
    virtual ~PotionOfExperience();

private:
    Character *character;
    const int exp_point = 10;
    type_object type;
    bool visibility;
    int numSalle;

};



#endif /* PotionOfExperience_hpp */
