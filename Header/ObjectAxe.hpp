//
//  ObjectAxe.hpp
//  DND
//
//  Created by Matthieu Jolo on 28/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#ifndef ObjectAxe_hpp
#define ObjectAxe_hpp

#include <stdio.h>
#include "Object.hpp"
#include "Character.hpp"

class ObjectAxe: public Object {
public:

    ObjectAxe(Position pos);
    ObjectAxe();
    virtual int getValueObject();
    bool use(Character *);
    bool remove(Character *);
    void affiche(ostream&  s);
    void setPosition(Position p);
    Position getPosition();
    type_object getType();
    void setNumSalle(int num);
    int getNumSalle();
    bool getVisibility();
    void setVisibility(bool v);
    virtual ~ObjectAxe() ;

private:
    const int attack;
    Position pos;
    type_object type;
    bool visibility;
    int numSalle;



};
#endif /* ObjectAxe_hpp */
