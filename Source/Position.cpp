#include "../Header/Position.hpp"
#include <iostream>
using namespace std;


Position::Position(int x, int y){
  _x=x;
  _y=y;

}
void Position::setPosition(Position p){
  _x=p.getX();
  _y=p.getY();

}


int Position::getX(){
  return _x;
}


int Position::getY(){
  return _y;
}

void Position::setX(int x){
  _x=x;
}


void Position::setY(int y){
  _y=y;
}


    bool Position::equals(Position p){
      return (this->_x == p.getX() && this->_y == p.getY());
    }
