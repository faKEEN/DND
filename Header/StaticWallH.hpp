//
//  StaticWallH.hpp
//  DND
//
//  Created by Matthieu Jolo on 29/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#ifndef StaticWallH_hpp
#define StaticWallH_hpp

#include <stdio.h>
#include "StaticObject.hpp"
#include "Position.hpp"

class StaticWallH: public StaticObject {



public:
    StaticWallH(Position p,int numSalle);
        StaticWallH(Position p);
    type_object getType();
    virtual void affiche(ostream &os);
    void setPosition(Position p);
    Position getPosition();
    void setNumSalle(int num);
     int getNumSalle();

     bool getVisibility();
     void setVisibility(bool v);
    virtual ~StaticWallH();
private:
    Position pos;
      bool visibility;
      type_object type;
        int numSalle;
};

#endif /* StaticWallH_hpp */
