
#ifndef Position_hpp
#define Position_hpp
#include <iostream>


class Position {
private:
  int _x,_y;

public:
  Position(int x=0,int y=0);
  void setPosition(Position p);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    bool equals(Position p);

};

#endif /* Position_h */
