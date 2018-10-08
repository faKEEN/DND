//
//  ObjectSword.h
//  DND
//
//  Created by Matthieu Jolo on 28/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#ifndef ObjectSword_h
#define ObjectSword_h

#include "Object.hpp"
#include "Character.hpp"


class ObjectSword: public Object {
public:

    ObjectSword(Position pos);
        type_object getType();


     bool use(Character *);
int getValueObject();
bool remove(Character *character);
   void affiche(ostream&  s);
   void setPosition(Position p);
   Position getPosition();
   void setNumSalle(int num);
    int getNumSalle();
   bool getVisibility();
   void setVisibility(bool v);
virtual ~ObjectSword() ;

private:
    const int attack;
    Position  pos;
    type_object type;
      bool visibility;
        int numSalle;
};

#endif /* ObjectSword_h */
