//
//  Character.h
//  DND
//
//  Created by Matthieu Jolo on 06/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <iostream>
#include <vector>
#include "Object.hpp"
#include "AliveObject.hpp"
#include "Position.hpp"
#include "Monstre.hpp"
using namespace std;

class Character: public AliveObject {
private:
    static Character *player;
    Character();
    Position pos;
    string nom;
    bool visibility;
    int numSalle;
    int monsterDead;
    const int MAX;
    bool isFullBarLife;
    bool isAlive;
    const int degat;
    int nbAttack;
    type_object type;

    // manque enum du joueur
    int lifeBar; // Barre de vie
    int expBar; // Barre d'experience
    int strength; //Force de frappe
    int armor; // Resistance aux attaques
    int SIZE_BAG;
    int SIZE_BAG_ARME;


public:
  vector< ObjectWorld* > bag;
  vector< ObjectWorld* > armes;
  void setCurrentArme(int i);
  int getCurrentArme();
    static int nbrcoups;
  static int handArme;
  static int current_arme;
    static Character * getInstance();
    type_object getType();
    void affiche(ostream& s);
    void attack(ObjectWorld * monstre);
    void setNom(string nom);
    string getNom();

    int getNbObjectBag();

    void setPosition(Position p);
    Position getPosition();
    bool pickup(ObjectWorld *obj);
    bool pickupArm(ObjectWorld *obj);
    bool throws_objects(int i);
    bool throws_armes(int i);
    ObjectWorld * getArmeAt(int i);
    ObjectWorld * getObjectAt(int i);


    void setLifeBar(int l);
    void setStrength(int l);
    void setArmor(int arm);
    int getArmor();
    void setExpr(int arm);
    int getExpr();
    int getStrength();
    int getLifeBar();
    int getDegat();
    int getNbAttack();
    void setNbAttack(int);
    vector<ObjectWorld*> getBag();
    vector<ObjectWorld*> getWeapons();
    int getMonsterDead();
    void setMonsterDead(int);

    void setType(type_object t);
    void setIsAlive(bool vie);
    bool getIsAlive();
    bool getVisibility();
    void setVisibility(bool v);
    void setNumSalle(int num);
    int getNumSalle();
    void setIsFullBarLife(bool life);
    bool getIsFullBarLife();
    void useArme(int i);
    void useObject(int i);

    virtual ~Character();



};

#endif
