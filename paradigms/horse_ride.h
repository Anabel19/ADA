//DEBE MEJORAR
#include <iostream>
#include <stdio.h>
using namespace std;
const int movx[8]={-1,-2, -2,-1,1,2,2,1},
					movy[8]={-2,-1,1,2,2,1,-1,-2};


template<class B>
class Cboard
{
	public:
	  typedef typename B::d D;
		//typedef typename B::c C;
		//dimensiones
		D dim;
		//C dcol;
		int cant;
		int **board;
		Cboard(D d){
				  this->dim=d;
				  //this->dcol=tamcol;
					this->cant=dim*dim;
				  board=new int*[dim];
				  for(int i=0; i<dim; i++){
							 board[i]=new int[dim];
				  }
					llenado();
		}

		void llenado(){
			for(unsigned int i=0; i<dim; i++){
				for(unsigned int j=0; j<dim; j++){
					 board[i][j]=0;
				}
			}
		}
};

template<class D>
class Chorse_ride
{
	public:
		typedef Chorse_ride<D>self;
		typedef Cboard<self>board;
		typedef D d;
		//typedef C c;
		int posx;
		int posy;
		board *hboard;
		 Chorse_ride(int dim, int x0, int y0){
			 this->posx=x0;
			 this->posy=y0;
			 hboard =new board(dim);
			 hboard->board[posx][posy]=1;//hboard[posx][posy]
		 }
		 ~Chorse_ride(){
			 for(unsigned int i=0; i<hboard->dim; i++){
				 	delete hboard->board[i];
			 }
			 delete hboard->board;
		 }
		 void print_board();
		 void mov_horse(int px, int py, int, bool*);
};

template<class D>
void Chorse_ride<D>::print_board(){
	 for(unsigned int i=0; i<hboard->dim; i++){
		 for(unsigned int j=0; j<hboard->dim; j++){
			  printf("%3d", hboard->board[i][j]);
		 }
		 printf("\n");
	 }
	 printf("\n\n");
}

template<class D>
void Chorse_ride<D>::mov_horse(int px, int py, int i, bool *vale){
	int k=0; int x,y;
	*vale=false;
	do{
	 		//print_board();
			x=px+movx[k];		y=py+movy[k];
			if(x>=0 and x<hboard->dim and y<hboard->dim and y>=0){
					if(hboard->board[x][y]==0){ //hboard[x][y]
							hboard->board[x][y]=i;

							if(i<hboard->cant){//todas las casillas
									mov_horse(x,y,i+1, vale);
									if(!*vale) hboard->board[x][y]=0;
							}
							else *vale=true;
					}
			}
			k++;
 	}while(!*vale and k<8);
}
