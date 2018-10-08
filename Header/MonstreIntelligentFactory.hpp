#ifndef MonstreIntelligentFactory_hpp
#define MonstreIntelligentFactory_hpp





#include "AbstractMonstreFactory.hpp"
#include "ObjectWorld.hpp"
class MonstreIntelligentFactory:public AbstractMonstreFactory  {
public:
virtual Monstre * buildSpecificMonster(Position p,ObjectWorld *obj,int level);

 ~MonstreIntelligentFactory();


};




#endif
