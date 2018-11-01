/*BACKTRACKING*/
#include<iostream>
#include"n_reynas.h"

using namespace std;

int main()
{
  //dimension
  int dim=10;
  //int dcol=8;    int dfil=8;
  int cant_r=8;

  CNreynas<int> Nr(dim, cant_r);
  if(Nr.sol_nreynas(0,0)==false)//first col | cant reynas
      cout<<"oh";
  else Nr.print_board();
  return 0;
}
