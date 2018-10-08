

#include "../Header/Couloir.hpp"




Couloir::Couloir(){


}
 void Couloir::affiche(ostream&  s){

  for (int i =0; i <(int) passages.size();i++) {

          s << *(passages[i]);
      }
 }
void Couloir::addMonstreObserver(Monstre *){

}
  void Couloir::removeMonstreObserver(Monstre * p){

  }
  void Couloir::notifyMonstreObservers(){

  }


  void Couloir::setNumCouloir(int num){
    numCouLoir=num;
  }
   int Couloir::getNumCouloir(){
     return numCouLoir;
   }
   bool Couloir::getVisibility(){
     return visibility;
   }
   void Couloir::setVisibility(bool v){

     visibility=v;

   }

 Couloir::~Couloir(){

}
