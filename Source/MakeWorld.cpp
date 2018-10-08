//
//  MakeWorld.cpp
//  DND
//
//  Created by Matthieu Jolo on 03/01/2018.
//  Copyright © 2018 Matthieu Jolo. All rights reserved.
//

#include "../Header/MakeWorld.hpp"
#include "../Header/Map.hpp"
#include "../Header/Salle.hpp"
#include "../Header/StaticPassage.hpp"
#include "../Header/Position.hpp"
#include "../Header/Couloir.hpp"
#include "../Header/Porte.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Salle;
class Couloir;
enum state {MAP,DIM, PAS, ERROR};

state stringToState (string s) {
    if (s == "MAP") return MAP;
    if (s == "DIM") return DIM;
    if (s == "PAS") return PAS;
    return ERROR;
}

vector<string> split(const string &s, char delimiter){
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

MakeWorld::MakeWorld(string _path): path(_path) {
    cout << "Initialisation de la map..." << endl;
}

Map* MakeWorld::init_map() {
    Map* _map = nullptr;

    string line;
    vector<string> token;

    ifstream myfile;
    myfile.open(path);

    std::string::size_type sz;

    if(!myfile) {
        cout << "probleme de fichier" << endl;
    }
    else {
        while(getline(myfile, line)) {
            token = split(line,' ');

            switch (stringToState(token[0])) {
                case MAP: {
                  //  cout << "MAP \n";
                    _map = new Map(stoi(token[1],&sz),stoi(token[2],&sz));
                    break;
                }
                case DIM: {
                //    cout << "DIM \n";
                    std::vector<Porte *> portes;

                    //vector<pair<int,int>> doors;
                    Position p(stoi(token[1]),stoi(token[2],&sz));

                  //  pair<int,int> coor_pos(stoi(token[1],&sz),stoi(token[2],&sz));
                  // à inverser pour avoir les dimensiosn varriables
                  int w = stoi(token[4],&sz);
                  int h = stoi(token[3],&sz);
                //    pair<int,int> coor_size(stoi(token[4],&sz),stoi(token[3],&sz));
                //  std::cout << "tokensize    " << token.size()<< '\n';
                    for (int i = 5; i < (int)token.size()-1; i+=2) {


                        int x = stoi(token[i],&sz);
                        int y = stoi(token[i+1],&sz);

                //pair<int,int> door(first,second);
                  //   std::cout << "x" <<x<<" y "<<y<< '\n';
                        portes.push_back(new Porte(Position(x,y)));
                    }
                //    std::cout << "/* portes sizes */" <<portes.size()<< '\n';
                  //  std::cout << "p " <<p.getX()<<" y "<<p.getY()<< '\n';
            //   _map->salles.push_back(new Piece(coor_pos,coor_size,doors,*_map));
                 _map->salles.push_back(new Salle(h,w,p,portes));
                    //std::cout << "apres" << '\n';
                    break;

                }
                case PAS:{
                    cout << "PAS \n";
                    Couloir *c ;
                     c = new Couloir;
                    for(int i = 1; i <(int) token.size()-1; i+=2) {
                    //   cout << i << "pas ," << i+1 << endl;
                        int x = stoi(token[i],&sz);
                        int y = stoi(token[i+1],&sz);

                        c->passages.push_back(new StaticPassage(Position(x,y)));

                      //  _map->world[i][i+1] = new StaticPassage();
                    }

                    _map->couloirs.push_back(c);
                    break;
                }
                default:{
                    cout << "TOKEN NON EXISTANT" << endl;
                }
            }
        }
    }
    return _map;
}
