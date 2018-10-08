//
//  ObjectWorld.h
//  DND
//
//  Created by Matthieu Jolo on 06/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#ifndef ObjectWorld_hpp
#define ObjectWorld_hpp
#include <iostream>
#include <random>
#include <cstdlib>
#include "TypeObject.hpp"
#include "Position.hpp"
using namespace std;

class ObjectWorld {
    virtual void affiche(ostream& s)=0;
    friend ostream& operator <<(ostream &o,  ObjectWorld& obj){
        obj.affiche(o);
        return o;
    };
public:
    virtual type_object getType()=0;
    virtual Position getPosition()=0;
    virtual void setNumSalle(int num)=0;
    virtual int getNumSalle()=0;
    virtual bool getVisibility()=0;
    virtual void setVisibility(bool v)=0;

    virtual void setPosition(Position p)=0;

    virtual ~ObjectWorld(){
        std::cout << "/* obj world destructor */" << '\n';
    }
};

#endif /* ObjectWorld_h */
