/*BACKTRACKING*/
#include<iostream>
#include"horse_ride.h"

using namespace std;

int main()
{
  //dimension
  int dim=8;
  //int dcol=8;    int dfil=8;
  int x0=3;    int y0=7;
  if(x0<0 or y0<0 or x0>=dim or y0>=dim){
    cout<<"start not valid"<<endl;
    return 0;
  }
  bool vale;
  Chorse_ride<int> HR(dim, x0, y0);
  HR.mov_horse(x0, y0,2,&vale);//porque ya posicione el primero
  HR.print_board();
  return 0;
}
