

#ifndef Salle_hpp
#define Salle_hpp

#include "StaticObject.hpp"
#include "Monstre.hpp"
#include <iostream>
#include <vector>
#include "Position.hpp"
#include "PotionOfHealing.hpp"
#include "PotionOfWeakness.hpp"
#include "PotionOfExperience.hpp"
#include "ObjectAxe.hpp"

#include "MoveState.hpp"
#include "AbstractMonstreFactory.hpp"
#include "MonstrePuissantFactory.hpp"
#include "MonstreIntelligentFactory.hpp"
#include "MonstreResistantFactory.hpp"

#include "MonstreIntelligentFactory.hpp"
#include "MonstreResistant.hpp"
#include "MonstreIntelligentFactory.hpp"
#include "MonstrePuissant.hpp"
#include "Porte.hpp"
#include "StaticWallH.hpp"
#include "StaticWallV.hpp"
#include "StaticDoor.hpp"
#include "StaticVoid.hpp"
#include "StaticFloor.hpp"
#include "TypeObject.hpp"
using namespace std;


class Salle {
  int height;
  int width;

  Position pos;

  int level;
  bool visibility;
    int nummero;
public:
    vector< Monstre* >observers;
  Salle(int height, int width, Position p,  vector<Porte*>portes);
   void affiche(ostream&  s);
   void genererMonstres(int nb);
  void addMonstreObserver(Monstre *); // monstres de la salle
    void removeMonstreObserver(Monstre * p); // monstre mrt ou sort de la salle
    void notifyMonstreObservers(Character *c); // notify monstres
    void unnotifyMonstreObservers(Character *c);
    int getWidth();
    int getHeight();
    void setLevel(int l);
    void setPosition(Position p);
    Position getPosition();
    vector<vector<ObjectWorld *>>composants;
    vector<Porte*>portes;
    vector<Porte*> getPortes();
    vector<Monstre*> getObservers();
    void setNumero(int num);
    int getNumero();
    virtual ~Salle();
    bool getVisibility();
    void setVisibility(bool v);


};

#endif /* Object_h */
