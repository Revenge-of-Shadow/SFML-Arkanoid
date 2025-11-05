#include <iostream>

#include "Pilka.h"

int main(){
  const float FiW = 640.0, FiH = 480.0, vX=5, vY=5, r=5;

  Pilka pl(FiW, FiH, FiW/2, FiH/2, vX, vY, r);

  for(int i = 0; i<0x100; ++i){
    pl.przesun();
    pl.kolizjaSciana();
    std::cout<<"\tX: "<<pl.getX()<<"\tY:"<<pl.getY()<<"\tvX: "<<pl.getVX()<<"\tvY:"<<pl.getVY()<<std::endl;
  }
}
