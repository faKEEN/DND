


#include "../Header/StaticDoor.hpp"




StaticDoor::StaticDoor(Position p,int num){
  pos= p;
  type= porte;
  visibility =true;
  numSalle =num;
  
}



StaticDoor::StaticDoor(Position p){
  pos= p;
  type= porte;
  visibility =true;

}

void StaticDoor::affiche(ostream &s) {
  //  s << "\033[1;42m \033[0m";
  s << "\033[1;42m"<<(char)this->getType()<<"\033[0m";
    //  s << (char)this->getType();
}

type_object  StaticDoor::getType(){
   return type;
 }


 void StaticDoor::setPosition(Position p){

 }
 Position StaticDoor::getPosition(){
   return pos;
 }
 bool StaticDoor::getVisibility(){
   return visibility;
 }
 void StaticDoor::setVisibility(bool v){
   visibility = v;

 }

  void StaticDoor::setNumSalle(int num){
   numSalle = num;

 }
   int StaticDoor::getNumSalle(){
     return numSalle;
     }
StaticDoor::~StaticDoor(){

}
