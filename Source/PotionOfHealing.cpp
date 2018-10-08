//
//  PotionOfHealing.cpp
//
//
//  Created by Matthieu Jolo on 21/12/2017.
//
//

#include "../Header/PotionOfHealing.hpp"


using namespace std;

PotionOfHealing::PotionOfHealing():  life_point(10){
    type =potionH;
    visibility =true;
}

  void PotionOfHealing::affiche(ostream&  s){
  //  s << "\033[1;32mP\033[0m\n";
  if(visibility){
     s << (char)this->getType();
  }else{
     s << (char)stfloor;
  }
 };

 int PotionOfHealing::getValueObject(){
   return life_point;

 }

  type_object  PotionOfHealing::getType(){
    return type;
  }

bool PotionOfHealing::use(Character *character) {
    cout << "Fonction use " <<character->getNom() <<endl;
    character->setLifeBar(character->getLifeBar()+life_point);
    return true;
};


bool PotionOfHealing::remove(Character *character) {
  cout << "Fonction remove" << endl;
  return true;
};

      void PotionOfHealing::setPosition(Position p){
          pos=p;
      };

      Position PotionOfHealing::getPosition(){
        return pos;
      }


            bool PotionOfHealing::getVisibility(){
              return visibility;
            }
            void PotionOfHealing::setVisibility(bool v){
              visibility = v;

            }

             void PotionOfHealing::setNumSalle(int num){
              numSalle = num;

            }
              int PotionOfHealing::getNumSalle(){
                return numSalle;
                }



 PotionOfHealing::~PotionOfHealing(){
  std::cout << "/* destructeur potion healing */" << '\n';
};
