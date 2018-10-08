//
//  Map.hpp
//  DND
//
//  Created by Matthieu Jolo on 28/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <vector>
#include "ObjectWorld.hpp"
#include "Salle.hpp"
#include "Couloir.hpp"
#include "EscalierM.hpp"
#include "EscalierD.hpp"
#include "Character.hpp"
class Map{

public:
    Map(int,int);
    void affiche();

    void makeMap(string);

    vector< vector<ObjectWorld*>> world;
  //  vector< vector<type_object>> staticWorld;
    vector< vector<ObjectWorld*>> staticworld;
    vector<Salle*> salles;
    vector<Couloir*> couloirs;
    EscalierM *escalierM;
    EscalierD *escalierD;
    friend ostream& operator <<(ostream &o, Map &map){
        for (int i = 0; i <(int) map.world.size(); i++) {
            for (int j = 0; j < (int) map.world[i].size(); j++) {
                o << *(map.world[i][j]);
            }
         o << endl;
        }
       return o;
    }
  void setSalles(vector<Salle*> s);
  void setCouloirs(vector<Couloir*> sc);
    void  createsWolrd();
  void placerCharacter(Character *c);
  void placerEscaliers();
  void initStaticWorld();
void affichestaticworld();
    virtual ~Map();
private:
    const int h;
    const int w;
};


#endif /* Map_hpp */
