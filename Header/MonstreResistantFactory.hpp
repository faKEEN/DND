#ifndef MonstreResistantFactory_hpp
#define MonstreResistantFactory_hpp





#include "AbstractMonstreFactory.hpp"
#include "../Header/ObjectWorld.hpp"

class MonstreResistantFactory:public AbstractMonstreFactory  {
public:
virtual Monstre * buildSpecificMonster(Position p,ObjectWorld *obj,int level);

   virtual ~MonstreResistantFactory();


};




#endif
