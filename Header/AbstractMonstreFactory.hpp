
#ifndef AbstractMonstreFactory_hpp
#define AbstractMonstreFactory_hpp
#include "Monstre.hpp"
#include "ObjectWorld.hpp"

class AbstractMonstreFactory {
    public:
    virtual Monstre * buildSpecificMonster(Position p,ObjectWorld *obj,int level)=0;
    virtual ~AbstractMonstreFactory(){
        std::cout << "/* destructeur interface AbstractMonstreFactory */" << '\n';
    };


};


#endif
