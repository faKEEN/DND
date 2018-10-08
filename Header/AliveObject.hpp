//
//  AliveObject.h
//  DND
//
//  Created by Matthieu Jolo on 06/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#ifndef AliveObject_hpp
#define AliveObject_hpp
#include <iostream>
#include "ObjectWorld.hpp"
using namespace std;
class AliveObject: public ObjectWorld {
    virtual type_object getType()=0;
    virtual void affiche(ostream& s)=0;

  //  virtual void attack(ObjectWorld &)=0;

};

#endif /* AliveObject_h */
