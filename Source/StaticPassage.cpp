


#include "../Header/StaticPassage.hpp"




StaticPassage::StaticPassage(Position p){
  pos= p;
  type = marcheCouloir;
  visibility =true;
}

StaticPassage::StaticPassage(Position p,int num){
  pos= p;
  type = marcheCouloir;
  visibility =true;
  numSalle=num;
}
 void StaticPassage::affiche(ostream&  s){
  s << (char)this->getType();
 }


 type_object  StaticPassage::getType(){
   return type;
 }


 void StaticPassage::setPosition(Position p){

 }
 Position StaticPassage::getPosition(){
   return pos;
 }


  bool StaticPassage::getVisibility(){
    return visibility;
  }
  void StaticPassage::setVisibility(bool v){
    visibility = v;

  }

   void StaticPassage::setNumSalle(int num){
    numSalle = num;

  }
    int StaticPassage::getNumSalle(){
      return numSalle;
      }
StaticPassage::~StaticPassage(){

}
