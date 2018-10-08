//
//  PotionOfWeakness.cpp
//
//
//  Created by Matthieu Jolo on 21/12/2017.
//
//

#include "../Header/PotionOfWeakness.hpp"


using namespace std;

PotionOfWeakness::PotionOfWeakness(): weakness_point(-10){
    cout << "Potion de faiblesse crée" << endl;
    type=potionW;
    visibility =true;
}

void PotionOfWeakness::affiche(ostream&  s){
    //  s << "\033[1;30mP\033[0m\n";
    if(visibility){
        s << (char)this->getType();
    }else{
        s << (char)stfloor;
    }

};


type_object PotionOfWeakness::getType(){
    return type;
}

int PotionOfWeakness::getValueObject(){
  return weakness_point;

}
bool PotionOfWeakness::use(Character *character) {
    cout << "Potion de faiblesse utilisée" << endl;
    character->setStrength(character->getStrength()+weakness_point);
    return true;
};


bool PotionOfWeakness::remove(Character *character) {
    cout << "Fonction remove" << endl;
    return true;
};


void PotionOfWeakness::setPosition(Position p){
    pos=p;
};

Position PotionOfWeakness::getPosition(){
    return pos;
}

bool PotionOfWeakness::getVisibility(){
    return visibility;
}
void PotionOfWeakness::setVisibility(bool v){
    visibility = v;

}

void PotionOfWeakness::setNumSalle(int num){
    numSalle = num;

}
int PotionOfWeakness::getNumSalle(){
    return numSalle;
}


PotionOfWeakness::~PotionOfWeakness(){
    cout << "Potion de faiblesse detruite" << endl;
};
