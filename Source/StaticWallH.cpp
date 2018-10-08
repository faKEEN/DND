


#include "../Header/StaticWallH.hpp"

StaticWallH::StaticWallH(Position p){
  pos= p;
  type=wallH;
  visibility =true;

}
StaticWallH::StaticWallH(Position p,int num){
  pos= p;
  type=wallH;
  visibility =true;
  numSalle=num;

}
void StaticWallH::affiche(ostream&  s){
  s << (char)this->getType();

}

type_object StaticWallH::getType(){

    return type;
}


void StaticWallH::setPosition(Position p){

}
Position StaticWallH::getPosition(){
  return pos;
}

bool StaticWallH::getVisibility(){
  return visibility;
}
void StaticWallH::setVisibility(bool v){
  visibility = v;

}

 void StaticWallH::setNumSalle(int num){
  numSalle = num;

}
  int StaticWallH::getNumSalle(){
    return numSalle;
    }

StaticWallH::~StaticWallH(){

}
