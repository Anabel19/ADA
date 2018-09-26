#include<iostream>
#include<time.h>
using namespace std;

//2*x+1
//2*x+2
//7 1 4 5 8
void heap_n(int *&a, int n, int tam)
{
	int nl= 2*n+1;//left kid
	int nr= 2*n+2;//right kid
	int auxmax=n;
	
	if(nl < tam and *(a+nl) > *(a+n)) auxmax=nl;
	if(nr < tam and *(a+nr) > *(a+auxmax)) auxmax=nr;
		
	if(auxmax!=n){
		swap(*(a+auxmax),*(a+n));
	    heap_n(a, auxmax, tam);
	}	
}
void heapSort(int *a, int tam)
{
	for(int i=tam-1; i>=0; i--){
		heap_n(a,i,tam);
	}
}

void print(int *a, int tam){
	for(int i=0; i<tam; i++){
		cout<<*(a+i)<<" ";
	}
}
int main()
{
	srand(time(NULL));
	
	int t=10;
	//int arr[t]={7,4,1,5,8};
	int *arr = new int[t];
	for (int i = 0; i< t; i++) {
		arr[i] = ((rand() % t) - (rand() % t));
	}
	cout<<"original array:"<<endl;
	print(arr, t);
	cout<<endl;
	
	heapSort(arr, t);
	cout<<"heap:"<<endl;
	print(arr, t);
	return 0;
}