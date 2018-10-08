//
//  Map.cpp
//  DND
//
//  Created by Matthieu Jolo on 28/12/2017.
//  Copyright © 2017 Matthieu Jolo. All rights reserved.
//

#include "../Header/Map.hpp"
#include "../Header/Jeu.hpp"
#include "../Header/ObjectWorld.hpp"
#include "../Header/StaticVoid.hpp"
#include "../Header/TypeObject.hpp"
#include "../Header/Salle.hpp"
#include "../Header/StaticPassage.hpp"
#include "../Header/Couloir.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>


using namespace std;


Map::Map(int i,int j): h(i), w(j) {
    world.resize(h);
    for(int i = 0; i<h; i++){
        world.at(i).resize(w);
    }

}



void Map::createsWolrd(){
    // les salles
    for (int i = 0; i <(int)salles.size(); i++) {
        for (int j= 0; j < (int)salles[i]->composants.size(); j++) {
            for (int k= 0; k <(int)salles[i]->composants.at(j).size(); k++) {
                //std::cout << "i " <<salles[i]->composants[j][k]->getPosition().getX() << "j"<<salles[i]->composants[j][k]->getPosition().getY()<<'\n';
                world[salles[i]->composants[j][k]->getPosition().getX()][salles[i]->composants[j][k]->getPosition().getY()]=salles[i]->composants[j][k];
            }

        }
    }

    for (int i = 0; i <(int)couloirs.size(); i++) {
        for (int j= 0; j <(int)couloirs[i]->passages.size(); j++) {

            world[couloirs[i]->passages.at(j)->getPosition().getX()][couloirs[i]->passages.at(j)->getPosition().getY()]=couloirs[i]->passages.at(j);

        }

    }
    for (int i = 0; i <h; i++) {
        for (int j = 0; j < w; j++) {
            if(world.at(i).at(j) == NULL){
                world[i][j]=new StaticVoid(Position(i,j));
            }
        }

    }
}

void Map::initStaticWorld(){
    staticworld= (world);

}

void Map::setSalles(vector<Salle*> s){
    salles =s;
}


void Map::setCouloirs(vector<Couloir*> c){
    couloirs = c;
}

void Map::makeMap(string path) {

}

void Map::placerCharacter(Character *c){

    c->setNumSalle(escalierD->getNumSalle());
 
    this->salles.at(c->getNumSalle())->setVisibility(true);

    this->salles.at(c->getNumSalle())->notifyMonstreObservers(c);
    world[c->getPosition().getX()][c->getPosition().getY()]=c;


}
void Map::placerEscaliers(){
    //  std::cout << "/* placer escaliers */" << '\n';
    random_device rd;
    mt19937 mt(rd());
    // on on choisit une salle au hasdard et on lace l'escaliere Montant et Descendant
    for(int i = 0; i<2; i++){
        if(i==0){
            uniform_real_distribution<double> _numsalle(0, (int)salles.size());
            std::cout << "size" <<(int)salles.size()<< '\n';
            int num = (int) _numsalle(mt);
            std::cout << "num random " <<num<< '\n';
            uniform_real_distribution<double> _first(1,salles[num]->getHeight()-1);
            uniform_real_distribution<double> _second(1,salles[num]->getWidth()-1);



            int x = (int) _first(mt);
            int y = (int) _second(mt);
            Position p = Position(salles[num]->getPosition().getX()+x,salles[num]->getPosition().getY()+y);
            escalierM = new EscalierM(p,num);
            //salles[num]->composants.at(x).at(y) =new EscalierM(p);

            salles[num]->composants.at(x).at(y) =escalierM;
            //std::cout << "U" << '\n';
            //  std::cout << " escalier M x " <<p.getX()  <<"y "<<p.getY() << " "<<(char)salles[num]->composants.at(x).at(y)->getType()<<'\n';
        }else{
            uniform_real_distribution<double> _numsalle(0, (int)salles.size());
            mt19937 mt(rd());
            int num = (int) _numsalle(mt);

            uniform_real_distribution<double> _first(1,salles[num]->getHeight()-1);
            uniform_real_distribution<double> _second(1,salles[num]->getWidth()-1);



            int x = (int) _first(mt);
            int y = (int) _second(mt);
            Position p = Position(salles[num]->getPosition().getX()+x,salles[num]->getPosition().getY()+y);
            escalierD = new EscalierD(p,num);
            salles[num]->composants.at(x).at(y) =escalierD;
            std::cout << "D" <<escalierD->getNumSalle()<< '\n';
            //std::cout << " escalier D x " <<p.getX()  <<"y "<<p.getY();
            //  std::cout << " escalier D x " <<p.getX()  <<"y "<<p.getY() << " "<<(char)salles[num]->composants.at(x).at(y)->getType()<<'\n';

        }



    }

}

void Map::affichestaticworld(){
    for (int i = 0; i <(int) staticworld.size(); i++) {
        for (int j = 0; j < (int) staticworld[i].size(); j++) {
            cout << *(staticworld[i][j]);
        }
        cout << endl;
    }

}

Map::~Map(){
    std::cout << "map destructeur " << '\n';
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            delete world[i][j];
            //delete copy[i][j]; // delete stored pointer
        }

    }


}
