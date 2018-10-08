


#include "../Header/Porte.hpp"




Porte::Porte(Position p,int num){
      pos= p;
      type= porte;

      this->numSalle=num;
      visibility =true;
}



Porte::Porte(Position p){
      pos= p;
      type= porte;
      numSalle = 0;
      visibility =true;
}

 void Porte::affiche(ostream&  s){
      s << "\033[1;42m"<<(char)this->getType()<<"\033[0m";
 }

 void Porte::setPosition(Position p){
     pos= p;
 }
 Position Porte::getPosition(){
   return pos;
 }
void Porte::setNumSalle(int num){
  numSalle = num;
}
int Porte::getNumSalle(){
  return numSalle;
}
bool Porte::getVisibility(){
  return visibility;
}
void Porte::setVisibility(bool v){
  visibility = v;

}



type_object Porte::getType(){
    return type;
  }

Porte::~Porte(){

}
