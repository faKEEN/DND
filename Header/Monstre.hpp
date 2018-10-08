#ifndef Monstre_hpp
#define Monstre_hpp
#include <random>
#include <iostream>
#include "AliveObject.hpp"
#include "Character.hpp"
#include "Object.hpp"
#include "Position.hpp"
#include "MoveState.hpp"
#include "MorphoState.hpp"
using namespace std;

class Character;
class Monstre: public AliveObject {
private:

    Position pos;
    int lifeBar; // Barre de vie
    int expBar; // Barre d'experience
    int strength; //Force sde frappe
    int degat; //

    int numSalle;
    bool isAlive;
protected:
    ObjectWorld *obj;
    type_object type;
  type_move t_move;
  type_move transition;
  type_morpho morpho;
    bool visibility;
public:

    Monstre(Position p,ObjectWorld *obj);
    virtual void affiche(ostream& s)=0;

    virtual void attack(Character *)=0;

    void setObject(ObjectWorld *p);

    ObjectWorld* getObject();
    void setPosition(Position p);
    void setLifeBar(int l);
    void setStrength(int l);
    Position getPosition();
    void setTypeMove(type_move m);
    type_object getType();
    void setType(type_object t);
    int getStrength();
    int getLifeBar();
    int getDegat();

    void setMove(type_move m,type_morpho mor );
    type_move getTypeMove();
    type_morpho getTypeMorpho();
    void setTypeMorpho(type_morpho m);
    bool getVisibility();
    void setVisibility(bool v);
    void setNumSalle(int num);
    int getNumSalle();
    void setTransitionMove(type_move t);
    type_move getTransitionMove();
    virtual void setIsAlive(bool vie);
    virtual bool getIsAlive();

    virtual Position staticMove()=0;
    virtual Position followMove(char cmd)=0;
    virtual Position HasardMove()=0;
    virtual Position teleportMove()=0;
    Position pasMonstre(Position pos_depart,char cmd);
    virtual ~Monstre();
};


#endif /* Character_h */
