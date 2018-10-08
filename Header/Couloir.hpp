#ifndef Couloir_hpp
#define Couloir_hpp

#include "StaticObject.hpp"
#include "Monstre.hpp"
#include <vector>
#include "Position.hpp"
#include <iostream>

class Couloir{
  vector< Monstre* >observers;
  vector<Position>positions;
    bool visibility;
    int numCouLoir;
      int numSalle;
public:

  vector<ObjectWorld*>passages;
  Couloir();
   void affiche(ostream&  s);
  void addMonstreObserver(Monstre *);
    void removeMonstreObserver(Monstre * p);
    void notifyMonstreObservers();
    void setNumCouloir(int num);
     int getNumCouloir();
     bool getVisibility();
     void setVisibility(bool v);
    virtual ~ Couloir();


};

#endif /* Object_h */
