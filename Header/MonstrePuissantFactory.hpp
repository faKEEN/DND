#ifndef MonstrePuissantFactory_hpp
#define MonstrePuissantFactory_hpp





#include "AbstractMonstreFactory.hpp"

class MonstrePuissantFactory:public AbstractMonstreFactory  {
public:
virtual Monstre * buildSpecificMonster(Position p,ObjectWorld *obj,int level);

   virtual ~MonstrePuissantFactory();


};




#endif
