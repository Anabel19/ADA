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
class CNreynas
{
	public:
		typedef CNreynas<D>self;
		typedef Cboard<self>board;
		typedef D d;
		//typedef C c;
		int cant_r;
		board *hboard;
		 CNreynas(int dim, int cant){
			 this->cant_r=cant;
			 hboard =new board(dim);
		 }
		 ~CNreynas(){
			 for(unsigned int i=0; i<hboard->dim; i++){
				 	delete hboard->board[i];
			 }
			 delete hboard->board;
		 }
		 void print_board();
		 bool BoardPos(int, int);
		 bool sol_nreynas(int, int);
};

template<class D>
void CNreynas<D>::print_board(){
	 for(unsigned int i=0; i<hboard->dim; i++){
		 for(unsigned int j=0; j<hboard->dim; j++){
			  printf("%3d", hboard->board[i][j]);
		 }
		 printf("\n");
	 }
	 printf("\n\n");
}

template<class D>
bool CNreynas<D>::BoardPos(int row, int col){
	 int r,c;
	 for(c=0; c<col; c++){
		 	if(hboard->board[row][c]==1) return false;
	 }
	 for(r=row,c=col; r>=0 and c>=0;r--, c--){
		 if(hboard->board[r][c]==1)  return false;
	 }
	 for(r=row, c=col; c>=0 and r<hboard->dim; r++, c--){
		 	if(hboard->board[r][c]==1) return false;
	 }
	 //cout<<"sale";
	 return true;
}

template<class D>
bool CNreynas<D>::sol_nreynas(int col, int k){
	print_board();
	if(col>=hboard->dim) return true;
	for(unsigned int i=0; i<hboard->dim and k<cant_r; i++){
		if(BoardPos(i,col)==true){
				hboard->board[i][col]=1;
				k++;
						cout<<k<<" ";
				if(sol_nreynas(col+1,k)==true) return true;
				hboard->board[i][col]=0;
		}
	}
	return false;
}
