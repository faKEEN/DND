
#include <iostream>
#include "../Header/MonstreIntelligentFactory.hpp"
#include "../Header/MonstreIntelligent.hpp"
Monstre * MonstreIntelligentFactory::buildSpecificMonster(Position p,ObjectWorld *obj,int level){
  Monstre *mon = new MonstreIntelligent(p,obj,level);
  return mon;

}

MonstreIntelligentFactory::~MonstreIntelligentFactory(){
std::cout << "/* intelligent */" << '\n';


}
