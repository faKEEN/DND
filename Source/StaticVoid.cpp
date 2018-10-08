


#include "../Header/StaticVoid.hpp"




StaticVoid::StaticVoid(Position p){
  pos= p;
  type= empty;
  visibility =true;
}


StaticVoid::StaticVoid(Position p,int num){
  pos= p;
  type= empty;
  visibility =true;
  numSalle= num;
}


 void StaticVoid::affiche(ostream&  s){
    s << (char)this->getType();

 }


type_object StaticVoid::getType(){
   return type;
 }


 void StaticVoid::setPosition(Position p){

 }
 Position StaticVoid::getPosition(){
   return pos;
 }


 bool StaticVoid::getVisibility(){
   return visibility;
 }
 void StaticVoid::setVisibility(bool v){
   visibility = v;

 }

  void StaticVoid::setNumSalle(int num){
   numSalle = num;

 }
   int StaticVoid::getNumSalle(){
     return numSalle;
     }

StaticVoid::~StaticVoid(){

}
