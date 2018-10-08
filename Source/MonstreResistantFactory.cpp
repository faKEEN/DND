
#include <iostream>
#include "../Header/MonstreResistantFactory.hpp"
#include "../Header/MonstreResistant.hpp"
Monstre * MonstreResistantFactory::buildSpecificMonster(Position p,ObjectWorld *obj,int level){
  Monstre *mon = new MonstreResistant(p,obj,level);
  return mon;

}

MonstreResistantFactory::~MonstreResistantFactory(){
std::cout << "/* resistant */" << '\n';

}
