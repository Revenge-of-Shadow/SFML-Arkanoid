#include <iostream>
#include "paletka.h"

int main(){
  const int width = 320;
  const int y = 450;
  Paletka p(80, 20, y, 10);

  for(int i = 0; i< 100; ++i){
    if(i%20<10) p.mvLeft(); else p.mvRight();
    std::cout<<"Step "<< i << "\tx = "<<p.getX()<<"\ty = "<<p.getY();
    p.limitMv(width);
    std::cout<<std::endl;
  }

}
