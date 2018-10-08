
#include "../Header/Jeu.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "../Header/TypeObject.hpp"
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

int Jeu::current_level=1;
int Jeu::minExp=100;
int Jeu::monstrestues=0;
Jeu::Jeu(vector<MakeWorld*>m){
    character = Character::getInstance();
    makers= m;
    for(int i = 0; i< (int) m.size(); i++){
        //  std::cout << "/* legnth de makers */" << m.size()<<'\n';
        this->jeux.push_back(m[i]->init_map());
        
    }
    
    std::random_shuffle ( this->jeux.begin(), this->jeux.end(),mapAleatoire);
    
    for(int i = 0; i< (int) this->jeux.size();i++){
        for(int  j = 0; j< (int) this->jeux[i]->salles.size(); j++){
            this->jeux[i]->salles[j]->setLevel(i+1); // on met à jour le niveau de chaque salle
            this->jeux[i]->salles[j]->setNumero(j);  }
    }
    for(int i = 0; i< (int) m.size(); i++){
        this->jeux.at(i)->placerEscaliers();
        
    }
    
    for(int i = 0; i< (int) m.size(); i++){
        
        this->jeux.at(i)->createsWolrd();
        this->jeux.at(i)->initStaticWorld();
        
    }
    
    for(int i = 0; i< (int) this->jeux.size();i++){
        for(int  j = 0; j< (int) this->jeux[i]->salles.size(); j++){
            this->jeux[i]->salles[j]->genererMonstres(4); // on genere les monstres dans chaque salle
        }
    }
    
    Position p =   this->jeux.at(0)->escalierD->getPosition();
    character->setPosition(p);
    this->jeux.at(0)->placerCharacter(character);
    
    Jeu::current_level=1;
    current_map = this->jeux[0];
    
    //cout << *current_map;
    displayMap(current_level-1);
    
    
}

Position Jeu::getEspaceVideInSalle(int ind){
    
    while(true){
        random_device rd;
        mt19937 mt(rd());
        
        
        uniform_real_distribution<double> _first(1,this->jeux[current_level-1]->salles.at(ind)->getHeight()-1);
        uniform_real_distribution<double> _second(1,this->jeux[current_level-1]->salles.at(ind)->getWidth()-1);
        
        
        int x = (int) _first(mt);
        int y = (int) _second(mt);
        
        if(this->jeux[current_level-1]->salles[ind]->composants.at(x).at(y)->getType() == stfloor){ // premiere position libre
            return this->jeux[current_level-1]->salles[ind]->composants.at(x).at(y)->getPosition();
        }
        
    }
}


void   Jeu::teleportation(Monstre * m){
    std::cout << "TELEPORTATIONNNNNN FUNCTION" << '\n';
    random_device rd;
    mt19937 mt(rd());
    bool trouve = false;
    while(trouve == false){
        int taille = (int) this->jeux[current_level-1]->salles.size();
        //std::cout << "size salle " << taille<< '\n';
        uniform_real_distribution<double> _numsalle(0,taille-1);
        int salledest = _numsalle(mt);
        int salleorigin= m->getNumSalle();
        if(salledest!=salleorigin){
            trouve = true;
            //  std::cout << "salle teleportatio trouvee" << '\n';
            Position next = getEspaceVideInSalle(salledest);
            m->setPosition(next);
            m->setNumSalle(salledest);
            //  std::cout << "salle origin" <<salleorigin<< '\n';
            //std::cout << "sallle dest" <<salledest<< '\n';
            this->jeux[current_level-1]->salles[salledest]->addMonstreObserver(m);
            //  this->world.at(m->getPosition().getX()).at(m->getPosition().getY()) =m;
            //  std::cout << "apres add monstre observers" << '\n';
            this->jeux[current_level-1]->salles[salleorigin]->removeMonstreObserver(m);
            //std::cout << "apres removeMonstreObserver" << '\n';
            
            //updateMonstre(m,next);
        }
    }
    
    
    
}

void Jeu::MoveAllmonstres(){
    for(unsigned int i = 0; i< this->jeux[current_level-1]->salles.size();i++){
        
        for(unsigned int j = 0; j< this->jeux[current_level-1]->salles[i]->observers.size();j++){
            Monstre *m = this->jeux[current_level-1]->salles[i]->observers.at(j);
            //  std::cout << "observers sizeeee" << this->jeux[current_level-1]->salles[i]->observers.size()<<'\n';
            if(this->jeux[current_level-1]->salles[i]->getVisibility() == true){
                
                
                
                //std::cout << "move allllll monsterrss m->getTypeMove " << (char)m->getType()  << '\n';
                Position current =m->getPosition();
                Position move;
                
                
                switch(m->getTransitionMove()  ){
                        
                    case statique:
                    {
                        std::cout << "static moveeee " << '\n';
                        move = m->staticMove();
                        //m->getObject()->setPosition(move);
                        joueMonstre(m,move);
                    }
                        break;
                    case follow:
                        std::cout << "folow jeu move" << '\n';
                    { // 4 sections
                        // si le monstre est dans la mm piece
                        if(current.getX() <= character->getPosition().getX() && current.getY() <= character->getPosition().getY() && possibleMonstre(current_level-1,m,m->pasMonstre(current,BAS))){
                            move = m->followMove(BAS);
                            //  joueMonstre(m,pasMonstre(current,BAS));
                        }else  if(current.getX() <= character->getPosition().getX() && current.getY() <= character->getPosition().getY() && !possibleMonstre(current_level-1,m,m->pasMonstre(current,BAS))){
                            move = m->followMove(DROITE);
                            //  joueMonstre(m,pasMonstre(current,DROITE));
                            
                        }else  if(current.getX() >= character->getPosition().getX() && current.getY() <= character->getPosition().getY() && possibleMonstre(current_level-1,m,m->pasMonstre(current,HAUT))){
                            move = m->followMove(HAUT);
                            //joueMonstre(m,pasMonstre(current,HAUT));
                        }else  if(current.getX() >= character->getPosition().getX() && current.getY() <= character->getPosition().getY() && !possibleMonstre(current_level-1,m,m->pasMonstre(current,HAUT))){
                            move = m->followMove(DROITE);
                            //  joueMonstre(m,pasMonstre(current,DROITE));
                            
                        }else  if(current.getX() >= character->getPosition().getX() && current.getY() >= character->getPosition().getY() && possibleMonstre(current_level-1,m,m->pasMonstre(current,HAUT))){
                            move = m->followMove(HAUT);
                            //joueMonstre(m,pasMonstre(current,HAUT));
                        }else  if(current.getX() >= character->getPosition().getX() && current.getY() >= character->getPosition().getY() && !possibleMonstre(current_level-1,m,m->pasMonstre(current,HAUT))){
                            move = m->followMove(GAUCHE);
                            //joueMonstre(m,pasMonstre(current,GAUCHE));
                            
                        }else  if(current.getX() <= character->getPosition().getX() && current.getY() >= character->getPosition().getY() && possibleMonstre(current_level-1,m,m->pasMonstre(current,BAS))){
                            move = m->followMove(BAS);
                            //joueMonstre(m,pasMonstre(current,BAS));
                        }else  if(current.getX() <= character->getPosition().getX() && current.getY() >= character->getPosition().getY() && !possibleMonstre(current_level-1,m,m->pasMonstre(current,BAS))){
                            move = m->followMove(GAUCHE);
                            //  joueMonstre(m,pasMonstre(current,GAUCHE));
                            
                        }
                        //  m->getObject()->setPosition(move);
                        joueMonstre(m,move);
                        
                    }
                        break;
                    case hasard:
                    {
                        std::cout << "hasarddddd move " << '\n';
                        //  move = m->HasardMove();
                        //  m->getObject()->setPosition(move); // maj aussi de l'objet deplacé
                        joueMonstre(m,move);
                    }
                        break;
                    case teleport:
                    {
                        std::cout << "teleportation moveee " << '\n';
                        move = m->teleportMove();
                        //m->getObject()->setPosition(move);
                        joueMonstre(m,move);
                    }
                        break;
                    default:
                        move = m->staticMove();
                        //  m->getObject()->setPosition(move);
                        joueMonstre(m,move);
                        
                        break;
                }
            }
            
        }
    }
    
}


void  Jeu::updateMonstre(Monstre * m, Position next){
    this->jeux.at(current_level-1)->world.at(next.getX()).at(next.getY())=m;
    
}

int Jeu::mapAleatoire(int i){
    srand((int)time(0));
    int aleatoire = (rand() % i);
    return aleatoire;
}


Map * Jeu::getMapAt(int ind){
    current_map = jeux[ind];
    return current_map;
}


void Jeu::jouer(){
    //seting the terminal in raw mode
    
    bool finjeu= false;
    type_object dir;

    //bool jeter = false;
    Position character_position;
    while(1){
        
        std::cout <<">";
        
        char cmd;
        cin>>cmd;
        switch(cmd){
                
            case 'a': // changer armes
                changerArmeCharacter();
                
                break;
            case 'm':
                displayWeapons();
                break;
            case 'u': // use potion at
                
                useObjectsCharacter();
                break;
            case 't': // jetger potion at
                obj=jeterObjectcharacter();
                
                break;
            case 'c':
                finjeu =true;
                break;
                
            case 'o':
                displayBag();
                break;
                
            case 'i':
                std::cout << "liste commandes : monter = z | descendre = s | gauche = q | droite = d | o = seeObjectsHeros |  c = quitter "<<endl;
                break;
                
            case HAUT: //throws current object for attaq
                std::cout << "haut" << '\n';
                dir =haut;
                character_position = character->getPosition(); /* on recupere la position actuelle de sokoban */
                joue(current_level-1,dir,character_position,character->getType());  /* deplacement du sokoban */
                finjeu = FinJeu();
                break;
                
            case BAS:
                std::cout << "bas" << '\n';
                /* *deplacer vers le bas */
                dir =bas;
                character_position = character->getPosition(); /* on recupere la position actuelle de sokoban */
                joue(current_level-1,dir,character_position,character->getType()); /* deplacement du sokoban */
                finjeu = FinJeu();
                break;
                
            case GAUCHE:
                std::cout << "gauche" << '\n';
                /* *deplacer vers la gauche*/
                dir=gauche;
                character_position = character->getPosition(); /* on recupere la position actuelle de sokoban */
                joue(current_level-1,dir,character_position,character->getType()); /* deplacement du sokoban */
                finjeu = FinJeu();
                break;
                
            case DROITE:
                std::cout << "droite" << '\n';
                /* *deplacer vers la droite */
                dir=droite;
                character_position = character->getPosition(); /* on recupere la position actuelle de sokoban */
                joue(current_level-1,dir,character_position,character->getType()); /* deplacement du sokoban */
                finjeu = FinJeu();
                
            default:
                
                break;
        }
        
        if(finjeu == true){
            //this->current_map->affichestaticworld();
            cout<<"bravo vous avez gagné en %d coups "<< endl;
            break;
        }
        
        switch(cmd){
            case 'a' :case 'm' : case 'u' :case 't' :case 'c':case 'o' : case 'i':
                
                break;
            default:
                UpdateMap();
                
        }
    }
}


Position Jeu::joue(int numMap,type_object cmd,Position depart,type_object dir_hero){
    
    Position next;  // position suivante
    bool pas_correct;
    ObjectWorld *dest;   // pointeur objet destination
    type_object type_next; // type regard objet destination
    type_action action;  // type d'action
    next= pas(numMap,depart,cmd,dir_hero);
    
    /* utilisation de possible */
    //std::cout << " pos courante x " << depart.getX() << " y" << depart.getY() <<'\n';
    //std::cout << " pos next x " << next.getX() << " y" << next.getY() <<'\n';
    pas_correct=possible(numMap,next);
    
    if(pas_correct == true){
        std::cout << "/*  correct */" << '\n';
        type_next= this->jeux.at(numMap)->world.at(next.getX()).at(next.getY())->getType();
        
        
        action= getTypeAction(type_next);
        dest =  this->jeux.at(numMap)->world.at(next.getX()).at(next.getY());
        moveAction(action,character,dest,cmd);
    }else{
        std::cout << "/* pas non correc */" << '\n';
        next = depart;
        type_next=dir_hero;
        character->setType(cmd);
    }
    // pas de chhangement => meme direction regard   et mm position
    return next;
}

Position Jeu::pas(int numMap,Position pos_depart,type_object cmd,type_object dir_hero){
    Position pos_res = pos_depart; /*postion à retourner */
    
    switch(cmd){
            
        case haut:
            if(dir_hero == haut){ // si le joueur regardait deja en haut
                pos_res.setX(pos_depart.getX()-1);/* on monte d'1 getX() */
                pos_res.setY(pos_depart.getY());
            }
            break;
            
        case bas:
            if(dir_hero == bas){ // si le joueur regardait deja en bas
                pos_res.setX(pos_depart.getX()+1);/* on decend d'1 getX() */
                pos_res.setY(pos_depart.getY());
            }
            
            break;
            
        case gauche:
            if(dir_hero == gauche){
                pos_res.setX(pos_depart.getX());
                pos_res.setY(pos_depart.getY()-1);/* on recule d'1 getY() */
            }
            break;
            
        case droite:
            if(dir_hero == droite){
                pos_res.setX(pos_depart.getX());
                pos_res.setY(pos_depart.getY()+1);/* on avance d'1 getY() */
            }
            
            break;
            
        default:
            //  printf("cette commande n'est pas une commande directionnelle\n");
            // autre chose à completer
            break;
            
    }
    
    return pos_res;
}
void Jeu::displayMap(int current){
    current_map = this->jeux[current];
    std::cout << "/* current map */" << current<<'\n';
    cout << *current_map;
    displayStatistic();
    
}

/* fonction qui change l'état du monstre en potion */


void Jeu::setStateMonster() {
    for(int i = 0; i< (int) this->jeux.size();i++){
        for(int  j = 0; j< (int) this->jeux[i]->salles.size(); j++){
            vector<Monstre*> monstres = this->jeux[i]->salles.at(j)->getObservers();
            for(unsigned int k = 0; k < monstres.size() ;k++) {
                if(monstres[k]->getLifeBar() <=0) {
                    monstres[k]->setIsAlive(false);
                    //maj de la position de l'objet porté par le monstre
                    monstres[k]->getObject()->setPosition(monstres[k]->getPosition());
                    this->jeux.at(i)->world[monstres[k]->getPosition().getX()][monstres[k]->getPosition().getY()]= this->jeux.at(i)->staticworld[monstres[k]->getPosition().getX()][monstres[k]->getPosition().getY()];
                    //monstres[k]->setVisibility(false);
                    this->jeux.at(i)->world[monstres[k]->getPosition().getX()][monstres[k]->getPosition().getY()] = monstres[k]->getObject();
                    
                    this->jeux[i]->salles.at(j)->removeMonstreObserver(monstres[k]);
                    
                    //cout << monstres[k]->getObject()->getType() << endl;
                }
            }
        }
    }
}



type_action Jeu::getTypeAction(type_object move){
    // prend le type de la case de destination et renvoie le type de moveAction
    //attaquer,ramasser,jeter,lancer,monter,descendre,entre,sortir,tourner
    type_action action;
    switch (move) {
        case monstreP: case monstreI:case monstreR:
            action=attaquer;
            break;
        case gauche : case droite:case  bas:case haut:
            action=tourner;
            break;
        case potionH: case potionE: case potionW: case potionAlea:
            action = ramasserPotion;
            break;
        case armeSword: case armeGun:
            action = ramasserArme;
            break;
        case levelUP:
            action=monter;
            break;
        case levelDown:
            action=descendre;
            break;
        case marcheCouloir:
            // sil le heros se trouvait dans une postion qui corresppndait à une porte dans le statiworld  et qu'il va dans une marche d'escalier , alors il sort
            if(this->jeux.at(current_level-1)->staticworld.at(character->getPosition().getX()).at(character->getPosition().getY())->getType() == porte){
                action = sortir;
            }else{
                //sinon il avance juste dans le couloir
                action = avancer;
            }
            break;
        case stfloor:
            //  case sfloor = porte
            // sil le heros se trouvait dans une postion qui corresppndait à une marche de couloir dans le statiworld  et qu'il va dans une marche de porte ou sfloor , alors il entre
            
            if(this->jeux.at(current_level-1)->staticworld.at(character->getPosition().getX()).at(character->getPosition().getY())->getType() == marcheCouloir){
                action = entrer;
            }else{
                //sinon il avance juste dans la salle
                action = avancer;
            }
            break;
        default :
            action= avancer;
            break;
            
            
    }
    return action;
    
}


bool Jeu::possible(int numMap, Position p){
    type_object type;
    
    bool estPossible=false;
    type = this->jeux.at(numMap)->world.at(p.getX()).at(p.getY())->getType();
    //  std::cout << " type next  " << (char) type <<'\n';
    switch(type){
            /*   gauche='<',droite ='>',bas='V',haut='^',wallV='|',wallH='-',stfloor='.',porte='.',empty=' ',marcheCouloir='#',levelUP='U',levelDown='D',monstre='%',potionH='+',potionE='*',potionW='-',potionAlea='?',
             armeSword='(',armeGun='$' */
        case gauche : case droite:case  bas:case haut:
            estPossible = true;
        case marcheCouloir:
            estPossible = true;
            break;
        case empty:
            estPossible=false;
            break;
        case stfloor : case levelUP: case levelDown: case  monstreP: case monstreI:case monstreR : case potionH: case potionE: case potionW: case potionAlea: case armeSword: case armeGun:
            estPossible = true;
            break;
        case wallH:case wallV:
            estPossible= false;
            break;
        default:
            break;
            
    }
    return estPossible;
    
}

bool Jeu::FinJeu(){
    if(character->getIsAlive() == false){
        return true;
    }else{
        for(int i = 0; i< (int) this->jeux.size();i++){
            for(int  j = 0; j< (int) this->jeux[i]->salles.size(); j++){
                vector<Monstre*> monstres = this->jeux[i]->salles.at(j)->getObservers();
                for(unsigned int k = 0; k < monstres.size() ;k++) {
                    if(monstres[k]->getIsAlive() == true) {
                        return false;
                        
                    }
                }
            }
        }
        return true;
    }
}


void Jeu::moveAction(type_action action,Character *c,ObjectWorld * obj,type_object dir){
    // regarde l'action à faire et execute l'action
    std::cout << "/* move action */" << '\n';
    switch (action) {
        case attaquer:
            std::cout << "/* attaquer */" << '\n';
            // attquer monstre diminution des ressources du monstre
            character->attack(obj);
            break;
        case tourner:
            std::cout << "/* tourner */" << '\n';
            // on chnge juste direction du regard
            character->setType(dir);
            break;
        case ramasserPotion:
        {
            //  Position pred=character->getPosition();
            Position reelInitObjet=character->getPosition();
            std::cout << "/* ramasser potion */" << '\n';
            if(character->pickup(obj) ==true){
                character->setPosition(obj->getPosition());
                
                // on remet en place l'objectworld recouvert par le joueur dans le monde initial
                std::cout << "rel type " <<(char)this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY())->getType()<<endl;
                // maj position joueur
                character ->setType(dir);
                //UpdateChracter();
                ObjectWorld *o= this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY());
                this->UpdateObjectAt(o);
            }
            
        }
            
            break;
        case ramasserArme:
        {
            std::cout << "/* ramasserArme */" << '\n';
            if(character->pickupArm(obj) == true){
                Position reelInitObjet;
                reelInitObjet.setPosition(character->getPosition()); // on memorise la position de l'objet de
                character->setPosition(obj->getPosition()); // maj position joueur
                character ->setType(dir);
                // on remet en place l'objectworld recouvert par le joueur dans le monde initial
                ObjectWorld *o= this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY());
                
                this->UpdateObjectAt(o);
            }
        }
            
            break;
        case monter:
            std::cout << "/* monter */" << '\n';
            // si assez d'experience
            if(character->getExpr()>=0 && current_level <(int) this->jeux.size()){
                Position reelInitObjet;
                reelInitObjet.setPosition(character->getPosition()); // on memorise la position de l'objet de
                // on remet en place l'objectworld recouvert par le joueur dans le monde initial
                obj= this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY());
                this->UpdateObjectAt(obj);
                monterNiveau();
            }else{
                
            }
            //changement niveau
            break;
        case descendre:
            //  std::cout << "/* descendre */" << '\n';
            if(current_level > 1){ // minimum superieur à 1 pour pouvoir decendre car current_level 1 = niveau 0 = map de 0
                Position reelInitObjet;
                reelInitObjet.setPosition(character->getPosition()); // on memorise la position de l'objet de
                
                // on remet en place l'objectworld recouvert par le joueur dans le monde initial
                obj= this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY());
                this->UpdateObjectAt(obj);
                descendreNiveau();
                
                
            }
            break;
        case avancer: // on avance dans la case suivante
            //std::cout << "/* avancer */" << '\n';
        {
            Position reelInitObjet;
            reelInitObjet.setPosition(character->getPosition()); // on memorise la position de l'objet de
            character->setPosition(obj->getPosition()); // maj position joueur
            character ->setType(dir);
            // on remet en place l'objectworld recouvert par le joueur dans le monde initial
            obj= this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY());
            
            this->UpdateObjectAt(obj);
            //  this-> UpdateObjectAt(character);
        }
            break;
            
        case entrer: // entrer c'est notify et avancer
        {
            std::cout << "/* entrer */" << '\n';
            Position next;
            next.setPosition(obj->getPosition());
            int num = obj->getNumSalle();
            //  int num =  this->jeux.at(current_level-1)->staticworld.at(next.getX()).at(next.getY())-> getNumSalle();
            //  std::cout << "current salle  " << num<<'\n';
            this->jeux.at(current_level-1)->salles.at(num)->setVisibility(true);
            this->jeux.at(current_level-1)->salles.at(num)->notifyMonstreObservers(character);
            
            Position reelInitObjet;
            reelInitObjet.setPosition(character->getPosition()); // on memorise la position de l'objet de
            character->setPosition(obj->getPosition()); // maj position joueur
            character ->setType(dir);
            // on remet en place l'objectworld recouvert par le joueur dans le monde initial
            obj= this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY());
            this->UpdateObjectAt(obj);
            
        }
            break;
            
        case sortir :
        {
            std::cout << "/* sortir */" << '\n';
            Position pred;
            pred.setPosition(character->getPosition());
            
            int num =  this->jeux.at(current_level-1)->staticworld.at(pred.getX()).at(pred.getY())-> getNumSalle();
            //std::cout << "current salle  " << num<<'\n';
            
            this->jeux.at(current_level-1)->salles.at(num)->unnotifyMonstreObservers(character);
            //  std::cout << "current porte position" <<  this->jeux.at(current_level-1)->salles.at(obj->getNumSalle())'\n';
            
            //  this->jeux.at(current_level-1)->salles.at(num)->setVisibility(true);
            
            Position reelInitObjet;
            reelInitObjet.setPosition(character->getPosition()); // on memorise la position de l'objet de
            character->setPosition(obj->getPosition()); // maj position joueur
            character ->setType(dir);
            //std::cout << "/* sotie vraie test  */" << '\n';
            // on remet en place l'objectworld recouvert par le joueur dans le monde initial
            obj= this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY());
            this->UpdateObjectAt(obj);
            
            
        }
            
            
            break;
            
        default:
            //je fais rien
            break;
            
    }
    
    
}

void Jeu::UpdateObjectAt(ObjectWorld *obj){
    
    this->jeux.at(current_level-1)->world.at(obj->getPosition().getX()).at(obj->getPosition().getY())=obj;
    
    
}

void Jeu::UpdateChracter(){
    //  std::cout << " herost update x " << character->getPosition().getX() << " y"<< character->getPosition().getY() << '\n';
    this->jeux.at(current_level-1)->world.at(character->getPosition().getX()).at(character->getPosition().getY())=character;
    
}
void Jeu::UpdateMap(){
    UpdateChracter();
    setStateMonster();
    MoveAllmonstres();
    displayMap(current_level-1);
}


void Jeu::displayStatistic(){
    cout << "Level: " << current_level << " Monster Killed: " << character->getMonsterDead() << " Knocks " << character->getNbAttack() <<  endl << "Life: " << character->getLifeBar() << " Strenght: " << character->getStrength() << " Objects bag: " << character->getNbObjectBag() << " Exp: " << character->getExpr() << endl;
}

void Jeu::monterNiveau() {
    
    
    
    current_level = current_level+1;
    Position p = this->jeux.at(current_level-1)->escalierD->getPosition();
    character->setPosition(p);
    this->jeux.at(current_level-1)->placerCharacter(character);
    //  current_map->placerCharacter(character);
    
    
}

void Jeu::descendreNiveau(){
    
    current_level = current_level-1;
    Position p = this->jeux.at(current_level-1)->escalierD->getPosition();
    character->setPosition(p);
    this->jeux.at(current_level-1)->placerCharacter(character);
    //  current_map->placerCharacter(character);
    
}


Position Jeu::joueMonstre(Monstre *m,Position next){
    
    bool pas_correct;
    ObjectWorld *dest;   // pointeur objet destination
    type_object type_next; // type regard objet destination
    type_action action;  // type d'action
    
    
    /* utilisation de possible */
    //std::cout << " pos courante x " << depart.getX() << " y" << depart.getY() <<'\n';
    //std::cout << " pos next x " << next.getX() << " y" << next.getY() <<'\n';
    pas_correct=possibleMonstre(current_level-1,m,next);
    
    if(pas_correct == true){
        //  std::cout << "/*  mosntre correct */" << '\n';
        type_next= this->jeux.at(current_level-1)->world.at(next.getX()).at(next.getY())->getType();
        
        
        action= getTypeActionMonstre(m,type_next);
        dest =  this->jeux.at(current_level-1)->world.at(next.getX()).at(next.getY());
        //  std::cout << "move action monstre avant " <<(char)dest->getType() <<'\n';
        moveActionMonstre(action,m,dest);
        //  std::cout << "apres move action monstree" << '\n';
    }else{
        type_next= this->jeux.at(current_level-1)->world.at(next.getX()).at(next.getY())->getType();
        //  std::cout << "/* pas non correc monstre  */" << (char)type_next << '\n';
        
        next = m->getPosition();
        
        
    }
    // pas de chhangement => meme direction regard   et mm position
    return next;
    
}
bool Jeu::possibleMonstre(int numMap,Monstre *m,Position next){
    type_object type;
    
    bool estPossible=false;
    type = this->jeux.at(numMap)->world.at(next.getX()).at(next.getY())->getType();
    //std::cout << " type next monstre move " << (char) type <<'\n';
    switch(type){
            /*   gauche='<',droite ='>',bas='V',haut='^',wallV='|',wallH='-',stfloor='.',porte='.',empty=' ',marcheCouloir='#',levelUP='U',levelDown='D',monstre='%',potionH='+',potionE='*',potionW='-',potionAlea='?',
             armeSword='(',armeGun='$' */
            
        case gauche : case droite: case  bas: case haut: // attaque possible ur le charactere
            estPossible = true;
        case marcheCouloir:
            if(m->getTransitionMove()== follow){
                estPossible = true;
            }else{
                estPossible = false;
            }
            break;
        case empty:
            estPossible=false;
            break;
        case stfloor :
            //std::cout << "stfloorrrrr" << '\n';
            estPossible = true;
            break;
        case wallH :case wallV:
            if(m->getTypeMove()== teleport){
                estPossible = true;
            }else{
                estPossible = false;
            }
        default:
            break;
            
    }
    return estPossible;
}


type_action Jeu::getTypeActionMonstre(Monstre *m,type_object move){
    
    // prend le type de la case de destination et renvoie le type de moveAction
    //attaquer,ramasser,jeter,lancer,monter,descendre,entre,sortir,tourner
    Position dep = m->getPosition();
    type_action action;
    switch (move) {
        case  monstreP: case monstreI:case monstreR:
            action=rester;
            break;
        case gauche : case droite:case  bas:case haut:
            action=attaquer;
            break;
            
        case marcheCouloir:
            // sil le heros se trouvait dans une postion qui corresppndait à une porte dans le statiworld  et qu'il va dans une marche d'escalier , alors il sort
            //if((m->getTransitionMove()== follow) && m->getTypeMorpho()==mince){
            if((m->getTypeMove() == follow)){
                if(this->jeux.at(current_level-1)->staticworld.at(dep.getX()).at(dep.getY())->getType() == porte ){
                    action = sortir;
                }else{
                    //sinon il avance juste dans le couloir
                    action = avancer;
                }
                
            }else{
                action=rester;
            }
            
            break;
        case stfloor:
            //  case sfloor = porte
            // sil le heros se trouvait dans une postion qui corresppndait à une marche de couloir dans le statiworld  et qu'il va dans une marche de porte ou sfloor , alors il entre
            
            if(this->jeux.at(current_level-1)->staticworld.at(dep.getX()).at(dep.getY())->getType() == marcheCouloir){
                
                action = entrer;
            }else{
                //sinon il avance juste dans la salle
                action = avancer;
            }
            
            
            break;
            
        case wallH : case wallV:
            action = teleporter;
            break;
        default :
            action= rester;
            break;
            
    }
    return action;
    
}


void  Jeu::moveActionMonstre(type_action action,Monstre *m,ObjectWorld * obj){
    //std::cout << "/* move action monstre */" << '\n';
    switch (action) {
        case attaquer:
            std::cout << "/* monstre attaquer  */" << '\n';
            // attquer monstre diminution des ressources du monstre
            m->attack(Character::getInstance());
            break;
            
            
        case avancer: // on avance dans la case suivante
            //  std::cout << "/* avanceeeeeeeeeeeeeeeeeer monstre */" << '\n';
        {
            Position reelInitObjet;
            reelInitObjet.setPosition(m->getPosition()); // on memorise la position de l'objet de
            m->setPosition(obj->getPosition()); // maj position joueur
            
            // on remet en place l'objectworld recouvert par le joueur dans le monde initial
            obj= this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY());
            //  std::cout << "oject" << '\n';
            
            this->updateMonstre(m,m->getPosition());
            this->UpdateObjectAt(obj);
            
        }
            break;
            
        case entrer: // entrer c'est notify et avancer
        {
            //std::cout << "/* entrer monstre  */" << '\n';
            Position next;
            next.setPosition(obj->getPosition());
            //int num = obj->getNumSalle();
            int num =  this->jeux.at(current_level-1)->staticworld.at(next.getX()).at(next.getY())-> getNumSalle();
            //std::cout << "current salle monstre " << num<<'\n';
            
            m->setNumSalle(num); // change son num salle
            this->jeux.at(current_level-1)->salles.at(num)->getObservers().push_back(m);
            //supression de la salle d'origine à faire
            
            Position reelInitObjet;
            reelInitObjet.setPosition(m->getPosition()); // on memorise la position de l'objet de
            m->setPosition(obj->getPosition()); // maj position joueur
            
            // on remet en place l'objectworld recouvert par le joueur dans le monde initial
            obj= this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY());
            this->UpdateObjectAt(obj);
            this->updateMonstre(m,m->getPosition());
            
        }
            break;
            
        case sortir :
        {
            std::cout << "/* sortir monstre  */" << '\n';
            Position pred;
            pred.setPosition(m->getPosition());
            
            int num =  this->jeux.at(current_level-1)->staticworld.at(pred.getX()).at(pred.getY())-> getNumSalle();
            std::cout << "current salle monste exit " << num<<'\n';
            
            Position reelInitObjet;
            reelInitObjet.setPosition(m->getPosition()); // on memorise la position de l'objet de
            m->setPosition(obj->getPosition()); // maj position joueur
            
            //    std::cout << "/* sotie vraie test  */" << '\n';
            // on remet en place l'objectworld recouvert par le joueur dans le monde initial
            obj= this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY());
            this->UpdateObjectAt(obj);
            this->updateMonstre(m,m->getPosition());
            
            
        }
            
            
            break;
        case rester:
        {
            //ss  std::cout << "rester monstre" << '\n';
            break;
            
        case teleporter:
            
            std::cout << "ACTION TELEPORTATIONNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNS" << '\n';
            
            Position pred;
            pred.setPosition(m->getPosition());
            teleportation(m);
            //  int num =  this->jeux.at(current_level-1)->staticworld.at(pred.getX()).at(pred.getY())-> getNumSalle();
            //  std::cout << "current salle monste teleport " << num<<'\n';
            
            Position reelInitObjet;
            reelInitObjet.setPosition(pred); // on memorise la position de l'objet de
            //  m->setPosition(obj->getPosition()); // maj position joueur
            
            //std::cout << "/* sotie vraie test teleporte  */" << '\n';
            // on remet en place l'objectworld recouvert par le joueur dans le monde initial
            std::cout <<"mx" <<pred.getX()<< "my "<<pred.getY()<<'\n';
            std::cout <<"m1x" <<m->getPosition().getX()<< "m1y "<<m->getPosition().getY()<<'\n';
            
            obj= this->jeux.at(current_level-1)->staticworld.at(reelInitObjet.getX()).at(reelInitObjet.getY());
            this->UpdateObjectAt(obj);
            this->updateMonstre(m,m->getPosition());
            
        }
            break;
        default:
            //je fais rien
            break;
            
    }
    
}
bool Jeu::changerArmeCharacter(){
    char cmd;
    int ind=0;
    bool ok= false;
    while(ok == false){
        std::cout << "entrer l'indice de l'arme" << '\n';
        cin>>cmd;
        ind =cmd - '0';
        //    std::cout << "ind" << ind<< '\n';
        if(ind>=0 && ind<(int)character->armes.size()){
            std::cout << "trueeeeeeeeeee" << '\n';
            character->useArme(ind);
            ok =true;
        }
        
    }
    return true;
    
}


bool Jeu::useObjectsCharacter(){
    char cmd;
    int ind=0;
    bool ok= false;
    while(ok == false){
        std::cout << "entrer l'indice de l'objet" << '\n';
        cin>>cmd;
        ind =cmd - '0';
        if(ind>=0 && ind<(int)character->bag.size()){
            character->useObject(ind);
            ok= true;
            
        }
        
    }
    return true;
}
void Jeu::seeArmesHeros(){
    std::cout << "0 = handArme ";
    for(unsigned int i = 0; i< character->armes.size();i++){
        std::cout << i+1 << " = " << (char)character->armes[i]->getType() ;
    }
    std::cout << " " << '\n';
    
    
}

ObjectWorld* Jeu::jeterObjectcharacter(){
    
    ObjectWorld *obj;
    char cmd;
    int ind=0;
    bool ok= false;
    while(ok == false){
        std::cout << "entrer l'indice de l'objet" << '\n';
        cin>>cmd;
        ind =cmd - '0';
        if(ind>=0 && ind<(int)character->bag.size()){
            obj=  character->getObjectAt(ind);
            ok = true;
            
            
        }
        
    }
    return obj;
    
    
}

void Jeu::displayWeapons() {
    vector<ObjectWorld*> armes = character->armes;
    string liste_armes;
    
    for (unsigned int i = 0; i < armes.size(); i++) {
        switch (armes[i]->getType()) {
            case '(': {
                liste_armes += to_string(i)+ " Epée ";
                break;
            }
            case '$': {
                liste_armes += to_string(i)+ " Hache ";
                break;
            }
            default:
                break;
        }
    }
    
    cout << liste_armes << endl << "Choisissez une arme:" << endl;
    
    
}
void Jeu::displayBag() {
    
    vector<ObjectWorld*> sac = character->bag;
    string liste_sac;
    
    for (unsigned int i = 0; i < sac.size(); i++) {
        switch (sac[i]->getType()) {
            case '+':{
                liste_sac += to_string(i)+ " Potion de Heal";
                break;
            }
            case '*': {
                liste_sac += to_string(i)+ " Potion d'experience";
                break;
            }
            case 'w': {
                liste_sac += to_string(i)+ " Potion de faiblesse";
                break;
            }
            default:
                break;
        }
    }
    cout << liste_sac << endl << "Choisissez votre item:" << endl;
    
}


bool Jeu::updateObjectJeter(ObjectWorld *obj){
    return true;
}
