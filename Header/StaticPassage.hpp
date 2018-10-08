//
//  StaticPassage.hpp
//  DND
//
//  Created by Matthieu Jolo on 02/01/2018.
//  Copyright © 2018 Matthieu Jolo. All rights reserved.
//

#ifndef StaticPassage_hpp
#define StaticPassage_hpp

#include <stdio.h>
#include "StaticObject.hpp"
#include "Position.hpp"
class StaticPassage: public StaticObject {
private:

    Position pos;
    type_object type;
      bool visibility;
        int numSalle;
  public:

        StaticPassage(Position p,int numSalle);
        StaticPassage(Position p);
     void affiche(ostream&  s);
     void setPosition(Position p);
     Position getPosition();
      type_object getType();
      void setNumSalle(int num);
       int getNumSalle();
       bool getVisibility();
       void setVisibility(bool v);
    virtual ~StaticPassage();
};

#endif /* StaticPassage_hpp */
