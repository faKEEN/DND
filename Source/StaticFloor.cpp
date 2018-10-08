


#include "../Header/StaticFloor.hpp"




StaticFloor::StaticFloor(Position p,int num){
  pos= p;
  type=stfloor;
  visibility =true;
  numSalle =num;
}
StaticFloor::StaticFloor(Position p){
  pos= p;
  type=stfloor;
  visibility =true;

}
 void StaticFloor::affiche(ostream&  s){
  s << (char)this->getType();
 }


type_object StaticFloor::getType(){
   return type;

 }


 void StaticFloor::setPosition(Position p){

 }
 Position StaticFloor::getPosition(){
   return pos;
 }
 bool StaticFloor::getVisibility(){
   return visibility;
 }
 void StaticFloor::setVisibility(bool v){
   visibility = v;

 }

  void StaticFloor::setNumSalle(int num){
   numSalle = num;

 }
   int StaticFloor::getNumSalle(){
     return numSalle;
     }

StaticFloor::~StaticFloor(){
std::cout << "/*floor destructor */" << '\n';
}
