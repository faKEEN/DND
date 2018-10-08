//
//  StaticDoor.hpp
//  DND
//
//  Created by Matthieu Jolo on 29/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#ifndef StaticDoor_hpp
#define StaticDoor_hpp

#include <stdio.h>
#include "StaticObject.hpp"
#include "Position.hpp"

class StaticDoor: public StaticObject {
public:
    StaticDoor(Position p,int numSalle);
      StaticDoor(Position p);
      type_object getType();
      void affiche(ostream&  s);
      void setPosition(Position p);
      Position getPosition();
      void setNumSalle(int num);
       int getNumSalle();
       bool getVisibility();
       void setVisibility(bool v);

     virtual ~StaticDoor();
private:

      Position pos;
      type_object type;
        bool visibility;
          int numSalle;
};


#endif /* StaticDoor_hpp */
