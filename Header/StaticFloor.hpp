//
//  StaticFloor.hpp
//  DND
//
//  Created by Matthieu Jolo on 29/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#ifndef StaticFloor_hpp
#define StaticFloor_hpp

#include <stdio.h>
#include "StaticObject.hpp"
#include "Position.hpp"

using namespace std;

class StaticFloor: public StaticObject {
private:

    Position pos;
    type_object type;
      bool visibility;
        int numSalle;
  public:
        StaticFloor(Position p,int numSalle);
              StaticFloor(Position p);
     void affiche(ostream&  s);
     void setPosition(Position p);
     Position getPosition();
      type_object getType();
      void setNumSalle(int num);
       int getNumSalle();
       bool getVisibility();
       void setVisibility(bool v);

    virtual ~StaticFloor();

};

#endif /* StaticFloor_hpp */
