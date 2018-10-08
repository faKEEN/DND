
#include "../Header/Salle.hpp"
#include "../Header/TypeObject.hpp"
using namespace std;

Salle::Salle(int h, int w, Position p,vector<Porte*>portess):level(1),visibility(false){
  height = h;
  width= w;
  pos=p;
  portes = (portess);
//  std::cout << "p size " <<(int) portes.size()<< '\n';
  composants.resize(height);

}
void Salle::genererMonstres(int nb){


 //std::cout << "nb  " << nb<<'\n';
random_device rd;
 mt19937 mt(rd());
  for(int i = 0; i< nb; i++){

   uniform_real_distribution<double> _first(1,this->height-1);
   uniform_real_distribution<double> _second(1, this->width-1);
   uniform_real_distribution<double> _num(1, 4);

    int x = (int) _first(mt);
    int y = (int) _second(mt);
      int num = (int) _num(mt);
  ObjectWorld *objet;
  ObjectWorld *ob;
  AbstractMonstreFactory *factory;
  Position p = Position(pos.getX()+x,pos.getY()+y);


  switch (num) {


    case 1:
    {
      ob= new ObjectAxe(p);
    factory = new MonstrePuissantFactory();
    objet = new PotionOfHealing;
      objet->setPosition(p);
      break;
  }

    case 2:
    {
    factory = new MonstreResistantFactory();
    objet = new PotionOfWeakness;
      objet->setPosition(p);break;
  }
    case 3 :
    {
    factory = new MonstreIntelligentFactory();
    objet = new PotionOfExperience;
      objet->setPosition(p);

      break;
  }
    default:
    {
    factory= new MonstreResistantFactory();
    objet = new PotionOfWeakness;
    objet->setPosition(p);
      break;
    }

  }

Monstre *m= factory->buildSpecificMonster(p,objet,this->level);
m->setNumSalle(nummero);
    // teste l'existance d'un escalier monant ou descendant
      if(this->composants.at(x).at(y)->getType() != levelUP && this->composants.at(x).at(y)->getType() != levelDown  ){
      //  std::cout << "observers push " <<(int)this->observers.size()<< '\n';
          this->observers.push_back(m);
          this->composants.at(x).at(y) =m;
      }


  //delete m;
  delete factory;
//  delete objet;
  }
}

Salle::~Salle(){
  for (int i = 0; i < height;i++) {
    for (int j =0; j < width; j++) {
      delete composants[i][j];
    }

  }


  for (int i = 0;i < (int) portes.size();i++) {

      delete portes[i];
    }





}

void Salle::affiche(ostream&  s){
  for (int i = pos.getX(); i < height;i++) {
    for (int j = pos.getY(); j < width; j++) {
      s << *(composants[i][j]);
    }
  }

}
void Salle::addMonstreObserver(Monstre *m){

    this->observers.push_back(m);
    //std::cout << "ADDD OBERSERVER REUSSI SALLE 114" << '\n';
//  this->composants.at(m->getPosition().getX()).at(m->getPosition().getY()) =m;
}
void Salle::removeMonstreObserver(Monstre * m){
  /*Vector<object*>::iterator in = tonVector.begin()+indice;
TonVector.erase(in);
  std::vector<Monstre*>::iterator it; */
  /* for(it = this->observers.begin() ; it != this->observers.end() ; ++it){
    if((*it) == m){
      this->observers.erase(it);
      std::cout << "ERASEEEEE MONSTREEEEEE SALLE 123" << '\n';

    }

    }
    std::cout << "endddddddddd ERASEEEE" << '\n'; */

    for(unsigned int i = 0; i<this->observers.size();i++){

      if(observers[i]== m){
        this->observers.erase(this->observers.begin() + i);
      //  std::cout << "ERASEEEEE MONSTREEEEEE SALLE 123" << '\n';

      }
    }


}
void Salle::notifyMonstreObservers(Character *c){
  for(int i = 0; i< (int)this->observers.size(); i++){
    if((this->observers.at(i)->getIsAlive() == true) && (this->observers.at(i)->getTypeMove() != statique) && (this->observers.at(i)->getVisibility() == true)){
              std::cout << "/* monstre attaquez */" << '\n';
        this->observers.at(i)->setTransitionMove(follow);


    }
  }


}

  void Salle::unnotifyMonstreObservers(Character *c){
    for(int i = 0; i< (int)this->observers.size(); i++){
        if((this->observers.at(i)->getIsAlive() == true) && (this->observers.at(i)->getTypeMove() != statique) && (this->observers.at(i)->getVisibility() == true)){
  std::cout << "/* unnotifyMonstreObservers */" << '\n';
          this->observers.at(i)->setTransitionMove(  this->observers.at(i)->getTypeMove()); // reprennennt leur etat normal

      }

    }

  }

int Salle::getWidth(){
  return width;
}
int Salle::getHeight(){
  return height;
}
vector<Porte*> Salle::getPortes(){
  return portes;
}

void Salle::setLevel(int l){
  //std::cout << "set level " <<l<< '\n';
  this->level=l;
}
vector<Monstre *> Salle::getObservers(){
  return observers;
}


 void Salle::setPosition(Position p){
     pos= p;
 }
 Position Salle::getPosition(){
   return pos;
 }


bool Salle::getVisibility(){
  return visibility;
}
void Salle::setVisibility(bool v){


  visibility = v;
  //std::cout << "setvisibility  " << (int) observers.size()<< '\n';
  for (int i = 0;i < (int) observers.size();i++) {
  //  std::cout << "setvisibility2 " <<  (int) observers.size()<<'\n';
    //  this->composants.at(x).at(y)->getType()
    observers[i]->setVisibility(v);
  //    std::cout << "setvisibility3  " << '\n';
//   this->composants.at(observers[i]->getPosition().getX()).at(observers[i]->getPosition().getY())->setVisibility(v);
    }
//    std::cout << "setvisibility end " << '\n';
}

void Salle::setNumero(int num){
  nummero = num;

for (int i =0 ; i < height; i++){
 //std::cout << "height =" <<height<< '\n';
  composants[i].resize(width);
  for (int j = 0; j < width; j++) {
    if (i == 0 || i == height-1  ) {
    //cout << "salle1" << '\n';
      composants[i][j]=new StaticWallH(Position(pos.getX()+i,pos.getY()+j),num);
    //  std::cout << "/* num1 */" <<num<< '\n';
    }
    else if (j == 0 || j == width-1) {
      // cout << "salle2" << '\n';
      composants[i][j] = new StaticWallV(Position(pos.getX()+i,pos.getY()+j),num);
    //  std::cout << "/* num2 */" <<num<< '\n';
    }
    else {
    //cout << "salle3" << '\n';
      composants[i][j]=new StaticFloor(Position(pos.getX()+i,pos.getY()+j),num);
  //    std::cout << "/* num3 */" <<num<< '\n';
    }

//std::cout << "/* portes sizes */" <<(int) portes.size()<< '\n';
for( int k = 0; k <(int) portes.size(); k++) {
  // std::cout << "i et j " <<portes[k]->getPosition().getX()<< " , "<< portes[k]->getPosition().getY()<<'\n';

if ((pos.getX()+i) == portes[k]->getPosition().getX() && (pos.getY()+j) == portes[k]->getPosition().getY()  ) {

//  std::cout << "iciii i et j " <<portes[k]->getPosition().getX()<< " , "<< portes[k]->getPosition().getY()<<'\n';
//  composants[i][j] = new StaticDoor(portes[k]->getPosition());
composants[i][j] =new Porte(portes[k]->getPosition(),num);
//std::cout << "/* num4*/" <<num<< '\n';
}

}
  }
}

}


int Salle::getNumero(){
return nummero;
}
