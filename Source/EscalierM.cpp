


#include "../Header/EscalierM.hpp"




EscalierM::EscalierM(Position p,int num){
      pos= p;
      type= levelUP;
      visibility =true;
      numSalle= num;
  
}
 void EscalierM::affiche(ostream&  s){
      s << (char)this->getType();
 }

 void EscalierM::setPosition(Position p){
     pos= p;
 }
 Position EscalierM::getPosition(){
   return pos;
 }


type_object EscalierM::getType(){
    return type;
  }

  bool EscalierM::getVisibility(){
    return visibility;
  }
  void EscalierM::setVisibility(bool v){
    visibility = v;

  }

   void EscalierM::setNumSalle(int num){
    numSalle = num;

  }
    int EscalierM::getNumSalle(){
      return numSalle;
      }

EscalierM::~EscalierM(){

}
