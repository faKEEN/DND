
#include <iostream>
#include <vector>
#include "../Header/MonstrePuissant.hpp"
#include "../Header/Jeu.hpp"
#include "../Header/ObjectWorld.hpp"
#include "../Header/ObjectAxe.hpp"
using namespace std;


MonstrePuissant::MonstrePuissant(Position p,ObjectWorld *obj,int level):Monstre(p,obj),powerbonus(20){
    type = monstreP;
    this->obj = new ObjectAxe;
  int range = 4 - 1 + 1; // max -min+1
  int num = rand() % range + 1; // entre 1 et 3
  switch (num) {

    case 1: this->setTypeMove(hasard);break;
    case 2 : this->setTypeMove(hasard);break;

    case 3: this->setTypeMove(follow);break;
    case 4 : this->setTypeMove(teleport);break;

    default:
    //statique
      break;

  };

this->powerbonus= level *this->powerbonus;
//this->setStrength(this->getStrength() + powerbonus);
this->setStrength(this->getStrength() + 2);
this->setLifeBar(this->getLifeBar() + powerbonus);
};

void MonstrePuissant::affiche(ostream& s){
  if(visibility == true){
      char c = (char)this->getType();
      string str ="";
      str.push_back(c);
      switch(getTypeMove()) {
          case hasard:{
              s << "\033[1;35m"+str+"\033[0m";
              break;
          }
          case follow: {
              s << "\033[1;34m"+str+"\033[0m";
          }
          case teleport: {
              s << "\033[1;36m"+str+"\033[0m";
          }default:
              break;
      }
  }else{
     s << (char)stfloor;
  }


};


void MonstrePuissant::attack(Character *c ){
    int degatFinal = this->getStrength()*this->getDegat();
  c->setLifeBar(-degatFinal);
}

void MonstrePuissant::setpowerbonus(int pwb){

}
int MonstrePuissant::getpowerbonus(){
  return powerbonus;
}


Position MonstrePuissant::staticMove(){ // regarde si le joeur est à cote de lui et attaque sinon reste
  Character *c = Character::getInstance();
  Position p = this->getPosition();
  Position g = this->pasMonstre(p,GAUCHE);
  Position d = this->pasMonstre(p,DROITE);
  Position h= this->pasMonstre(p,HAUT);
  Position b = this->pasMonstre(p,BAS);

  if(g.equals(c->getPosition())){
    return g;
    //  jeu::joueMonstre(this,g);
  }else if(d.equals(c->getPosition())){
  //  jeu::joueMonstre(this,d);
  return d;
  }else if (h.equals(c->getPosition())){
    return h;

    //jeu::joueMonstre(this,h);
  }else if(b.equals(c->getPosition())){
    //  jeu::joueMonstre(this,b);
      return b;
  }else{
  //  std::cout << "je ne fais rien " << '\n';
    return this->getPosition();
  }

}
Position MonstrePuissant::followMove(char cmd){


  Position p = this->getPosition();
  //  std::cout << "x" <<p.getX() << " y "<<p.getY()<< '\n';
  Position g = this->pasMonstre(p,GAUCHE);
    //std::cout << "xg" <<g.getX() << " y "<<g.getY()<< '\n';
  Position d = this->pasMonstre(p,DROITE);
    //std::cout << "xd" <<d.getX() << " y "<<d.getY()<< '\n';
  Position h= this->pasMonstre(p,HAUT);
    //std::cout << "xh" <<h.getX() << " y "<<h.getY()<< '\n';
  Position b = this->pasMonstre(p,BAS);
    //std::cout << "xb" <<b.getX() << " y "<<b.getY()<< '\n';
  switch(cmd){
    case GAUCHE:
    return g;
    break;
    case DROITE:
      return d;
      break;
    case HAUT:
      return h; break;
    case BAS:
      return b;
    break;
    default :
        std::cout << "defaultttt move" << '\n';
      return p;


  }


}
Position MonstrePuissant::HasardMove(){
  Position p = this->getPosition();
  Position dest;

  int range = 4 - 1 + 1; // max -min+1 ,jamais statik cq smart monster
  int num = rand() % range + 1; // entre 1 et 3
  switch (num) {


    case 1 :
    { dest = this->pasMonstre(p,GAUCHE);}
      //  jeu::joueMonstre(this,g);}
              break;

    case 2:
    {
    dest = this->pasMonstre(p,DROITE);
           }
              break;
    case 3 :
    {dest= this->pasMonstre(p,HAUT);
        }
      break;
    case 4:
    { dest = this->pasMonstre(p,BAS);
        }
        break;
    default:

  {  dest=p;}
    //statique
      break;

  };
  return dest;

}

Position MonstrePuissant::teleportMove(){
  std::cout << "teleporte puissant" << '\n';
// un monstre qui se teleporte = se deplace au hasard mais peut passer à travers les murs
Position move = HasardMove();
return move;

}

 MonstrePuissant::~MonstrePuissant(){
  /// std::cout << "/* monstre puissant destructeur */" << '\n';
}
