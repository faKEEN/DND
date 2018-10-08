
#ifndef Jeu_hpp
#define Jeu_hpp

#include <stdio.h>
#include <vector>
#include "ObjectWorld.hpp"
#include "Salle.hpp"
#include "Couloir.hpp"
#include "Map.hpp"
#include "Monstre.hpp"
#include "TypeObject.hpp"
#include "TypeAction.hpp"
#include "MakeWorld.hpp"

#define HAUT 'z'
#define BAS 's'
#define GAUCHE 'q'
#define DROITE 'd'


class Jeu{

public:
    Character *character;
    static int mapAleatoire(int i);
    Jeu(vector<MakeWorld*>m);
    vector<MakeWorld*>makers;
    vector<Map*>jeux;
    Map * current_map;
    Map * getMapAt(int ind);
    static int current_level;
    static int minExp;
    static int monstrestues;
    Position pas(int numMap,Position pos_depart,type_object cmd,type_object dir_hero);
    Position joue(int numMap,type_object cmd,Position depart,type_object dir_hero); // change la position apres erifiacation
    bool possible(int numMap, Position p);
    void displayMap(int current);
    void jouer();
    void UpdateObjectAt(ObjectWorld *obj);
    bool FinJeu();

    void UpdateMap();
    void UpdateChracter();
    void setStateMonster();


    type_action getTypeAction(type_object move);
    void moveAction(type_action action,Character *c,ObjectWorld * obj,type_object dir);



    void displayStatistic();
  void monterNiveau();
  void descendreNiveau();

 Position joueMonstre(Monstre *m,Position next); // change la position apres erifiacation
bool possibleMonstre(int numMap,Monstre *m,Position next);
    type_action getTypeActionMonstre(Monstre *m,type_object move);
    void moveActionMonstre(type_action action,Monstre *m,ObjectWorld * obj);

        Position getEspaceVideInSalle(int ind);
void teleportation(Monstre * m);
void updateMonstre(Monstre * m, Position next);
void MoveAllmonstres();
bool changerArmeCharacter();

bool useObjectsCharacter();
bool jeterObjectcharacter();
void seeArmesHeros();
void displayBag();
void displayWeapons();
bool updateObjectJeter(ObjectWorld *obj);
  bool possibleThrow(int numMap, Position p);
    };


#endif
