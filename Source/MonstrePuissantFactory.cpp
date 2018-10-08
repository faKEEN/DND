
#include <iostream>
#include "../Header/MonstrePuissantFactory.hpp"
#include "../Header/MonstrePuissant.hpp"
Monstre * MonstrePuissantFactory::buildSpecificMonster(Position p,ObjectWorld *obj,int level){
  Monstre *mon = new MonstrePuissant(p,obj,level);
  return mon;

}

MonstrePuissantFactory::~MonstrePuissantFactory(){

std::cout << "/* puissant */" << '\n';
}
