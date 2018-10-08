//
//  ObjectSword.cpp
//  DND
//
//  Created by Matthieu Jolo on 28/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#include "../Header/ObjectSword.hpp"

using namespace std;

ObjectSword::ObjectSword(Position p): attack(5) {
    pos= p;
  type=armeSword;
  visibility =true;
}
 void ObjectSword::affiche(ostream &os) {
         os<<(char)this->getType();
     }
   int ObjectSword::getValueObject(){
       return attack;

     }

bool ObjectSword::use(Character *character) {
    cout << "Epée utilisé !" << endl;
    character->setStrength(character->getStrength()+ObjectSword::attack);
    return true;
}

bool ObjectSword::remove(Character *character) {
    cout << "Epée retirée !" << endl;
    character->setStrength(character->getStrength()-ObjectSword::attack);
    return true;
}

void ObjectSword::setPosition(Position p){
    pos= p;
}
Position ObjectSword::getPosition(){
  return pos;
}


type_object ObjectSword::getType(){
   return type;
 }


 bool ObjectSword::getVisibility(){
   return visibility;
 }
 void ObjectSword::setVisibility(bool v){
   visibility = v;

 }

  void ObjectSword::setNumSalle(int num){
   numSalle = num;

 }
   int ObjectSword::getNumSalle(){
     return numSalle;
     }


 ObjectSword::~ObjectSword() {
      cout << "Dtor Hache" << endl;
}
