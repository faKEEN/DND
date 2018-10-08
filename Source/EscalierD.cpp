


#include "../Header/EscalierD.hpp"




EscalierD::EscalierD(Position p,int num){
      pos= p;
      type= levelDown;
      visibility =true;
        numSalle=num;
      //  std::cout << "contruceur escalier" <<numSalle<< '\n';

}
 void EscalierD::affiche(ostream&  s){
      s <<(char) this->getType();
 }

 void EscalierD::setPosition(Position p){
     pos= p;
 }
 Position EscalierD::getPosition(){
   return pos;
 }


type_object EscalierD::getType(){
    return type;
  }
  bool EscalierD::getVisibility(){
    return visibility;
  }
  void EscalierD::setVisibility(bool v){
    visibility = v;

  }

   void EscalierD::setNumSalle(int num){
    numSalle = num;

  }
    int EscalierD::getNumSalle(){
      return numSalle;
      }
EscalierD::~EscalierD(){

}
