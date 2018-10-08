
#include <iostream>
#include <vector>

#include "../Header/MonstreIntelligent.hpp"
#include "../Header/Jeu.hpp"
#include "../Header/ObjectWorld.hpp"
using namespace std;


MonstreIntelligent::MonstreIntelligent(Position p,ObjectWorld *obj,int level):Monstre(p,obj),qi(30){
    type = monstreI;
    int range = 4 - 1 + 1; // max -min+1 ,jamais statik cq smart monster
    int num = rand() % range + 1; // entre 1 et 3
    switch (num) {
            
        case 1: this->setTypeMove(hasard);break;
        case 2 : this->setTypeMove(hasard);break;
            
        case 3: this->setTypeMove(follow);break;
        case 4 : this->setTypeMove(teleport);break;
            
        default:
            //statique
            break;
            
    };
    
    
    this->qi= level * this->qi;
    //this->setStrength(this->getStrength() + qi);
    this->setLifeBar(this->getLifeBar() + qi);
    
};

void MonstreIntelligent::affiche(ostream& s){
    if(visibility == true){
        char c = (char) this->getType();
        string str ="";
        str.push_back(c);
        switch(getTypeMove()) {
                // 
            case hasard:{
                s << "\033[1;35m"+str+"\033[0m";
                break;
            }
            case follow: {
                s << "\033[1;34m"+str+"\033[0m";
            }
            case teleport: {
                s << "\033[1;36m"+str+"\033[0m";
            }
            default:
                break;
        }
    }else{
        s << (char)stfloor;
    }
    
    
};

void MonstreIntelligent::attack(Character * c){
    int degatFinal = this->getStrength()*this->getDegat();
    c->setLifeBar(-degatFinal);
}

void MonstreIntelligent::setQi(int q){
    qi= q;
}

int MonstreIntelligent::getQi(){
    return qi;
}

Position MonstreIntelligent::staticMove(){ // regarde si le joeur est à cote de lui et attaque sinon reste
    Character *c = Character::getInstance();
    Position p = this->getPosition();
    Position g = this->pasMonstre(p,GAUCHE);
    Position d = this->pasMonstre(p,DROITE);
    Position h= this->pasMonstre(p,HAUT);
    Position b = this->pasMonstre(p,BAS);
    
    if(g.equals(c->getPosition())){
        return g;
        //  jeu::joueMonstre(this,g);
    }else if(d.equals(c->getPosition())){
        //  jeu::joueMonstre(this,d);
        return d;
    }else if (h.equals(c->getPosition())){
        return h;
        
        //jeu::joueMonstre(this,h);
    }else if(b.equals(c->getPosition())){
        //  jeu::joueMonstre(this,b);
        return b;
    }else{
        std::cout << "je ne fais rien " << '\n';
        return this->getPosition();
    }
    
}
Position MonstreIntelligent::followMove(char cmd){
    std::cout << "followwwww move intelligent" << '\n';
    
    Position p = this->getPosition();
    
    Position g = this->pasMonstre(p,GAUCHE);
    
    Position d = this->pasMonstre(p,DROITE);
    
    Position h= this->pasMonstre(p,HAUT);
    
    Position b = this->pasMonstre(p,BAS);
    
    switch(cmd){
        case GAUCHE:
            return g;
            break;
        case DROITE:
            return d;
            break;
        case HAUT:
            return h; break;
        case BAS:
            return b;
            break;
        default :
            std::cout << "defaultttt move" << '\n';
            return p;
            
            
    }
    
    
}
Position MonstreIntelligent::HasardMove(){
    Position p = this->getPosition();
    Position dest;
    //std::cout << "p" <<p.getX() << " y "<<p.getY()<< '\n';
    int range = 4 - 1 + 1; // max -min+1 ,jamais statik cq smart monster
    int num = rand() % range + 1; // entre 1 et 3
    switch (num) {
            
            
        case 1 :
        { dest = this->pasMonstre(p,GAUCHE);}
            //  jeu::joueMonstre(this,g);}
            break;
            
        case 2:
        {
            dest = this->pasMonstre(p,DROITE);
        }
            break;
        case 3 :
        {dest= this->pasMonstre(p,HAUT);
        }
            break;
        case 4:
        { dest = this->pasMonstre(p,BAS);
        }
            break;
        default:
            
            //  { // dest=p;}
            //statique
            break;
            
    };
    //std::cout << "p" <<dest.getX() << " y "<<dest.getY()<< '\n';
    return dest;
    
    
}

Position MonstreIntelligent::teleportMove(){
    std::cout << "teleporttttttttttttttttttt moeve intel" << '\n';
    // un monstre qui se teleporte = se deplace au hasard mais peut passer à travers les murs
    Position move = HasardMove();
    return move;
    
}

MonstreIntelligent::~MonstreIntelligent(){
    std::cout << "/* monstrer intelligent destructeur */" << '\n';
}
