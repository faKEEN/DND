//
//  main.cpp
//  DND
//
//  Created by on 06/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#include <iostream>
#include "../Header/PotionOfHealing.hpp"
#include "../Header/PotionOfExperience.hpp"
#include "../Header/PotionOfWeakness.hpp"
#include "../Header/ObjectSword.hpp"
#include "../Header/ObjectAxe.hpp"
#include "../Header/Salle.hpp"
#include "../Header/StaticObject.hpp"
#include "../Header/Map.hpp"
#include "../Header/MakeWorld.hpp"
#include "../Header/Character.hpp"
#include "../Header/MonstreResistant.hpp"
#include "../Header/MoveState.hpp"
#include "../Header/AbstractMonstreFactory.hpp"
#include "../Header/MonstrePuissantFactory.hpp"
#include "../Header/MonstreIntelligentFactory.hpp"
#include "../Header/MonstreResistantFactory.hpp"
#include "../Header/ObjectSword.hpp"
#include "../Header/Jeu.hpp"

#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include<string>
using namespace std;

int main(int argc, const char * argv[]) {

  std::vector<MakeWorld*> v;
    
    v.push_back(new MakeWorld("level1"));
    v.push_back(new MakeWorld("level2"));
    Jeu jeu(v);
    jeu.jouer();

    /* Map* map = mw.init_map();
    map->createsWolrd();
    cout << *map; */
  /*  PotionOfHealing *poh ;
    poh= new PotionOfHealing;
    Character *character;
    character=Character::getInstance();
    poh->use(character);
    Position p=Position(3,4);
    MonstreResistant *  monster = new MonstreResistant(p,poh,2);
    cout<<"type " << *monster<<endl;
    cout<<"regard player " << *character<<endl;

    AbstractMonstreFactory *factory = new MonstrePuissantFactory();
    Monstre * m = factory->buildSpecificMonster(p,poh,3);
    cout<<"m " << *m<<endl;
    AbstractMonstreFactory *factory2 = new MonstreIntelligentFactory();
    AbstractMonstreFactory *factory3 = new MonstrePuissantFactory();

    delete character;
    delete poh;
    delete monster;
    delete factory;
    delete factory2;
    delete factory3;
    delete m;

    return 0; */
}
