
#include <iostream>
#include <vector>
#include "../Header/Monstre.hpp"
#include "../Header/Object.hpp"
#include "../Header/Jeu.hpp"
using namespace std;


Monstre::Monstre(Position p,ObjectWorld *o){
    int range = 4 - 1 + 1; // max -min+1 ,jamais statik cq smart monster
    int num = rand() % range + 1;
    pos=p;
    this->obj=o;
    lifeBar =10;

    strength = 1;
    t_move = statique;
    morpho = mince;
    degat =2;
    visibility =false;
    if(num==1){
        morpho = gros;
    }else{
        morpho = mince;
    }
    isAlive =true;

    std::cout << "/* num */" <<num<< '\n';


};


void Monstre::setPosition(Position p){
    pos=p;
};

Position Monstre::getPosition(){
    return pos;
}
ObjectWorld * Monstre::getObject(){
    return obj;
}


void Monstre::setObject(ObjectWorld *o){
    obj=o;

}
void Monstre::setLifeBar(int l){
    lifeBar=lifeBar+l;
    //std::cout << "lifeBar " <<lifeBar<< '\n';
};
void Monstre::setStrength(int l){
    strength = l;
};
void Monstre::setType(type_object t){
    type=t;
};
type_object Monstre::getType(){
    return type;
}
int Monstre::getStrength(){
    return strength;
}
int Monstre::getLifeBar(){
    return lifeBar;
};

int Monstre::getDegat() {
    return this->degat;
}


void Monstre::setTypeMove(type_move m){
    t_move=m;
};


type_move Monstre::getTypeMove(){
    return t_move;

};



int Monstre::getNumSalle(){
    return numSalle;
}


void Monstre::setIsAlive(bool vie){
    isAlive = vie;
}
bool Monstre::getIsAlive(){
    return isAlive;
}
Monstre::~Monstre(){
    std::cout << "/* monstre detructeur */" << '\n';
};



void Monstre::setMove(type_move m,type_morpho mor ){
    t_move= m;
    morpho = mor;
}

type_morpho Monstre::getTypeMorpho(){
    return morpho;
}
void Monstre::setTypeMorpho(type_morpho m){
    morpho=m;
}


bool Monstre::getVisibility(){
    return visibility;
}
void Monstre::setVisibility(bool v){
    visibility= v ;
}


void Monstre::setNumSalle(int num){
    numSalle = num;

}

void Monstre::setTransitionMove(type_move t){
    transition =t;
}
type_move Monstre::getTransitionMove(){
    return transition;
}

Position Monstre::pasMonstre(Position pos_depart,char cmd){

    Position pos_res = pos_depart; /*postion à retourner */
    switch(cmd){

      case HAUT:

      pos_res.setX(pos_depart.getX()-1);/* on monte d'1 getX() */
      pos_res.setY(pos_depart.getY());

      break;

      case BAS:

      pos_res.setX(pos_depart.getX()+1);/* on decend d'1 getX() */
      pos_res.setY(pos_depart.getY());


      break;

      case GAUCHE:

      pos_res.setX(pos_depart.getX());
      pos_res.setY(pos_depart.getY()-1);/* on recule d'1 getY() */

      break;

      case DROITE:

      pos_res.setX(pos_depart.getX());
      pos_res.setY(pos_depart.getY()+1);/* on avance d'1 getY() */


      break;

      default:
      //  printf("cette commande n'est pas une commande directionnelle\n");
      // autre chose à completer
      break;
    }
    return pos_res;

}
