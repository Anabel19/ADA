#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

typedef int (*fun)(int *, int *);
void swap( int *a, int *b ){

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
int comparacion_Asc(int a,int b)
{
    return b-a;//return a-b;

}
int comparacion_Desc(int a,int b)
{
    return a-b;//return b-a;

}
int comparacion_AscAbs(int a,int b)
{
    return abs(b)-abs(a);//return a-b;

}

int* particion(int *begin, int *end, int(*compara)(int a, int b))
{
    int indexPivote, valuePivote;
	int *index;
	valuePivote = *begin;

	swap(begin,end);
	index = begin;

	for( int *i =begin; i<end; i++){
		 if( compara(*i, valuePivote)>0 ){ // c_sort es el criterio para relizasr el ordenamiento
              swap(index,i);
              index++;
           }
        }
    swap(end,index);
   return index;
}

void quicksort( int *begin, int *end ,int (*compara)(int a, int b))
{
    int* pos_particion;
    if(begin < end){
        pos_particion = particion( begin, end, compara);
		quicksort( begin, pos_particion-1, compara);
		quicksort( pos_particion+1, end, compara);
    }
}

void print(int *p, int tam)
{
   for(int x=0; x<7; x++)
    {
        cout<<*p<<"\t";
        *p++;
    }
}
int main()
{
		srand(time(NULL));
	  double timer, timer2;
    int t=1000000;
		int *arr= new int[t];
    //int arr[t]={-15,10,-2,-3,8,13,15};
		for (int i=0; i< t; i++){
			arr[i]= ((rand()%t));
		}
    //int arr[t]={-15,10,-2,-3,8,13,15};
    int *y;
    y=&arr[t-1];//Fin
		ofstream a;
		timer= clock();
    quicksort(arr,y,comparacion_Desc);
		timer2= clock();
    cout<<"quickSort: "<<endl;
    //print(arr,t);
		a.open("arr.txt");
		for (int i=0; i< t; i++){
			a<<arr[i]<<" ";
		}
		cout<<endl<<"TIEMPO: "<<double(timer2-timer)/CLOCKS_PER_SEC<<endl;


    return 0;
}
