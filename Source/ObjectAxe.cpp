//
//  ObjectAxe.cpp
//  DND
//
//  Created by Matthieu Jolo on 28/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#include "../Header/ObjectAxe.hpp"


using namespace std;

ObjectAxe::ObjectAxe(Position p): attack(15) {
    pos= p;
  type=armeGun;
  visibility =true;
}


ObjectAxe::ObjectAxe(): attack(15) {
    type=armeGun;
    visibility =true;
}
 void ObjectAxe::affiche(ostream &s){
    s << "\033[1;36mW\033[0m\n";
}

int ObjectAxe::getValueObject(){
  return attack;

}
bool ObjectAxe::use(Character *character) {
    cout << "Epée utilisé !" << endl;
    character->setStrength(character->getStrength()+ObjectAxe::attack);
    return true;
}

bool ObjectAxe::remove(Character *character) {
    cout << "Epée retirée !" << endl;
    character->setStrength(character->getStrength()-ObjectAxe::attack);
    return true;
}

void ObjectAxe::setPosition(Position p){
    pos= p;
}
Position ObjectAxe::getPosition(){
  return pos;
}


type_object ObjectAxe::getType(){
   return type;
 }

 bool ObjectAxe::getVisibility(){
   return visibility;
 }
 void ObjectAxe::setVisibility(bool v){
   visibility = v;

 }

  void ObjectAxe::setNumSalle(int num){
   numSalle = num;

 }
   int ObjectAxe::getNumSalle(){
     return numSalle;
     }


 ObjectAxe::~ObjectAxe() {
    cout << "Destruction de l'épée" << endl;
}
