
#include "../Header/StaticWallV.hpp"


StaticWallV::StaticWallV(Position p,int num){
  pos= p;
  type = wallV;
  visibility = true;
  numSalle=num;

}
StaticWallV::StaticWallV(Position p){
  pos= p;
  type = wallV;
  visibility = true;

}
void StaticWallV::affiche(ostream&  s){
  s << (char)this->getType();
}

  type_object StaticWallV::getType(){
    return type;
  }

void StaticWallV::setPosition(Position p){

}
Position StaticWallV::getPosition(){
  return pos;
}


bool StaticWallV::getVisibility(){
  return visibility;
}
void StaticWallV::setVisibility(bool v){
  visibility = v;

}

 void StaticWallV::setNumSalle(int num){
  numSalle = num;

}
  int StaticWallV::getNumSalle(){
    return numSalle;
    }

 StaticWallV::~StaticWallV(){

}
