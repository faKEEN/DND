//
//  PotionOfExperience.cpp
//
//
//  Created by Matthieu Jolo on 21/12/2017.
//
//

#include "../Header/PotionOfExperience.hpp"
#include "../Header/Character.hpp"

using namespace std;

PotionOfExperience::PotionOfExperience(): exp_point(10){
    type =potionE;
    visibility =true;
}

void PotionOfExperience::affiche(ostream &s) {
    //  os << "\033[1;34mP\033[0m\n";
    if(visibility){
        s << (char)this->getType();
    }else{
        s << (char)stfloor;
    }

}
int PotionOfExperience::getValueObject(){
  return exp_point;

}

type_object PotionOfExperience::getType(){
    return type;
}

bool PotionOfExperience::use(Character *character) {
    cout << "Fonction use " <<character->getNom() <<endl;
    character->setExpr(character->getExpr()+exp_point);
    return true;
};


bool PotionOfExperience::remove(Character *character) {
    cout << "Fonction remove" << endl;
    return true;
};


void PotionOfExperience::setPosition(Position p){
    pos=p;
};

Position PotionOfExperience::getPosition(){
    return pos;
}

bool PotionOfExperience::getVisibility(){
    return visibility;
}
void PotionOfExperience::setVisibility(bool v){
    visibility = v;

}

void PotionOfExperience::setNumSalle(int num){
    numSalle = num;

}
int PotionOfExperience::getNumSalle(){
    return numSalle;
}


PotionOfExperience::~PotionOfExperience(){
    cout << "Potion d'experience detruite" << endl;
};
