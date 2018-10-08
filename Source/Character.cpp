#include <iostream>
#include "../Header/Character.hpp"

Character *Character::player=NULL;
int Character::handArme=1;
 int Character::current_arme=0;
 int Character::nbrcoups = 0;
Character::Character():MAX(150), degat(10),lifeBar(100){
    SIZE_BAG=10;
    SIZE_BAG_ARME = 3;
    nom="Luffy";
    isFullBarLife =true;
    isAlive = true;
    type = haut;
    visibility = true;
    numSalle = 0;
    expBar = 0;

}

vector<ObjectWorld*> Character::getBag() {
    return bag;
}

vector<ObjectWorld*> Character::getWeapons() {
    return armes;
}



Character * Character::getInstance() {
    if(player == NULL){
        player = new Character();
        //std::cout << "/* message */" << '\n';
    }
    return player;
}

  int Character::getCurrentArme(){
    return current_arme;
  }

  void Character::setCurrentArme(int i){
      current_arme = i;
  }



type_object Character::getType(){
    return type;
}

void Character::setType(type_object t){
    type=t;
}
bool Character::pickup(ObjectWorld * object) {
  if(SIZE_BAG > (int)bag.size()){
        bag.push_back(object);
        return true;
  }else{
    return false;
  }

}

bool  Character::pickupArm(ObjectWorld *obj){
  if(SIZE_BAG_ARME > (int)armes.size()){
        armes.push_back(obj);
        return true;
  }else{
    return false;
  }

}

void Character::affiche(ostream& s){

    s<<(char)this->getType();
}

void Character::attack(ObjectWorld * monstre  ){
  nbrcoups =nbrcoups+1;
    int degatfinal;
  if(current_arme == 0){

    degatfinal =handArme *this->getDegat();
  }else{
    degatfinal= ((Object*)this->getArmeAt(current_arme))->getValueObject() * this->getDegat();
  }

      std::cout << "degatfinal " <<degatfinal<< '\n';
    ((Monstre*)monstre)-> setLifeBar(-degatfinal);

}

void Character::setNom(string nom){
    this->nom= nom;
}

string Character::getNom(){
    return nom;
}

void Character::setIsAlive(bool vie){
    isAlive = vie;
}
bool Character::getIsAlive(){
    return (this->lifeBar > 0);
}
void Character::setIsFullBarLife(bool life){
    isFullBarLife = life;
}
bool Character::getIsFullBarLife(){
    return isFullBarLife;
}
Character::~Character(){
    //delete [] bag;
}

void Character::setPosition(Position p){
    pos=p;
}

int Character::getNbObjectBag() {
    return (int) bag.size();
}
Position Character::getPosition(){
    return pos;
}
bool Character::throws_objects(int i){
  if(i>=0 && i<(int)bag.size()){
bag.erase(bag.begin() + i);
return true;

}else{
    return false;
}

}

bool Character::throws_armes(int i){
  if(i>=0 && i<(int)armes.size()){
armes.erase(armes.begin() + i);
return true;

}else{
    return false;
}

}

void  Character::useArme(int i){
  if(i>=0 && i<(int)armes.size()){
    current_arme = i;


}else{

}
}
void  Character::useObject(int i){
ObjectWorld *obj = bag[i];
((Object*)obj)->use(this);

}

ObjectWorld * Character::getArmeAt(int i){
  return armes[i];

}
ObjectWorld * Character::getObjectAt(int i){
  return bag[i];

}

void Character::setLifeBar(int l){

    lifeBar =lifeBar+l;
    std::cout << "lifeBar " <<lifeBar<< '\n';
}
void Character::setStrength(int l){
    strength=l;
}
void Character::setArmor(int arm){
    armor = arm;
}
int Character::getArmor(){
    return armor;
}
void Character::setExpr(int exp){
    expBar = exp;
}
int Character::getExpr(){
    return expBar;
}
int Character::getStrength(){
    return strength;
}
int Character::getLifeBar(){
    return lifeBar;
}

int Character::getMonsterDead() {
    return monsterDead;
}

void Character::setMonsterDead(int monsterDead) {
    Character::monsterDead = monsterDead;
}


bool Character::getVisibility(){
    return visibility;
}
void Character::setVisibility(bool v){
    visibility= v ;
}


void Character::setNumSalle(int num){
    numSalle = num;

}

int Character::getDegat(){
    return degat;
}

int Character::getNbAttack() {
    //return nbAttack;
    return nbrcoups;
}

void Character::setNbAttack(int Attack) {
    nbAttack = Attack;
}

int Character::getNumSalle(){
    return numSalle;
}
