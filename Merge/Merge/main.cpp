#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
class comparacion {
	public:
	bool operator()(int a, int b) {
		return a - b;
	}
};

template<class compara>
class ordenamiento
{
	private:
	compara c_sort;
	public:
	void InsertSort(int *arr, int *n);
	void MergeSort(int *arr, int ini, int fin);
	void MergeSortN_2(int *arr, int ini, int fin);
	void MergeSortI(int *, int , int , int );
};


template<class compara>
void ordenamiento<compara>::MergeSort(int *a, int left, int right) {
	if (left < right){		
		int middle = left + ((right - left) >> 1);

		MergeSort(a, left, middle);
		MergeSort(a, middle + 1, right);
		//merge
		int	l = (middle - left) + 1;
		int r = right - middle;
		
		//divide in subarray
		int *b = new int[l];
		int *c = new int[r];
		for (unsigned int i = 0; i < l; i++)
			*(b + i) = *(a + left + i);
		for (unsigned int j = 0; j < r; j++)
			*(c + j) = *(a + middle + 1 + j);

		int i = 0; int j = 0;
		int k = left; //merge
		while (i < l and j < r) {//pieces
			if (*(b + i) <= *(c + j)) {
				*(a + k) = *(b + i);    i++;
			}
			else {
				*(a + k) = *(c + j);	j++;
			}
			k++;
		}
		//rest of elements
		while (i < l) {
			*(a + k) = *(b + i);	i++;	k++;
		}
		while (j < r) {
			*(a + k) = *(c + j);	j++;	k++;
		}
		delete b;
		delete c;
	}
}


template<class compara>
void ordenamiento<compara>::MergeSortN_2(int *a, int left, int right) {
	if (left == right)
		return;

	int t = right - left + 1;//tam
	int middle = (left + right) >> 1;

	MergeSort(a, left, middle);
	MergeSort(a, middle + 1, right);

	int *b = new int[t];
	int i = left; int j = middle+1;
	int k = 0; //int aux = right - middle;
	
	while (i < middle+1 and j<=right) {
		if (*(a + i)< *(a + j)){
			*(b + k) = *(a + i);    i++;
		}
		else {
			*(b + k) = *(a + j);	j++;
		}
		k++;
	}
	
	while (i < middle+1) {
		*(b + k) = *(a + i);	i++;	k++;
	}
	while (j <= right) {
		*(b + k) = *(a + j);	j++;	k++;
	}
	for (unsigned int k = 0; k < t; k++) {
		*(a + k) = *(b + k);
	}
	delete b;
}

template<class compara>
void ordenamiento<compara>::MergeSortI(int *a, int left, int right, int kbase) {
	
	if (left < kbase){
		int *y;
		y = &a[right - 1];//Fin
		InsertSort(a,y);
	}
	
	int t = right - left + 1;//tam
	int middle = (left + right) >> 1;

	MergeSort(a, left, middle);
	MergeSort(a, middle + 1, right);

	int *b = new int[t];
	int i = left; int j = middle+1;
	int k = 0; //int aux = right - middle;
	
	while (i < middle+1 and j<=right) {
		if (*(a + i)< *(a + j)){
			*(b + k) = *(a + i);    i++;
		}
		else {
			*(b + k) = *(a + j);	j++;
		}
		k++;
	}
	
	while (i < middle+1) {
		*(b + k) = *(a + i);	i++;	k++;
	}
	while (j <= right) {
		*(b + k) = *(a + j);	j++;	k++;
	}
	for (unsigned int k = 0; k < t; k++) {
		*(a + k) = *(b + k);
	}
	delete b;
}

template<class compara>
void ordenamiento<compara>::InsertSort(int *arr, int *y)
{
	int *tmp;
	int *inic = arr;
	while ((arr + 1) <= y)
	{
		tmp = arr + 1;
		while (tmp>inic && c_sort(*(tmp - 1), *(tmp))<0)
		{
			swap(*(tmp - 1), *(tmp));
			tmp--;
		}
		arr++;
	}
}

void fprint(ofstream &output, int *p, int tam) {
	for (int x = 0; x < tam; x++) {
		output << *p << "\t";
		*p++;
	}
}
void print( int *p, int tam) {
	for (int x = 0; x < tam; x++) {
		cout << *p << "\t";
		*p++;
	}
}
int main() {
	srand(time(NULL));
	time_t timer, timer2;

	const int t = 7;
	//int arr[t]={38,27,43,3,9,82,10};
	
	int *arr = new int[t];
	for (int i = 0; i< t; i++) {
		arr[i] = ((rand() % t) - (rand() % t));
	}
	
	/*
	int *y;
	y = &arr[t - 1];//Fin
	*/
	print(arr,t);
	cout<<endl;
	
	ordenamiento<comparacion> S;
	
	ofstream Txtsort;
	Txtsort.open("txtsort.txt");
	S.MergeSort(arr,0,t-1);
	Txtsort << "merge: " <<endl;
	fprint(Txtsort, arr,t);
	cout<<endl;
	
	S.MergeSortN_2(arr,0,t-1);
	Txtsort <<endl<< "mergeN_2: "<<endl;
	fprint(Txtsort, arr,t);
	
	int k = 3;
	S.MergeSortI(arr,0,t-1,k);
	Txtsort <<endl<< "mergeInsert: "<<endl;
	fprint(Txtsort, arr,t);
	
	Txtsort.close();
	
	delete[]arr;
	arr = NULL;

	system("pause");
	return 0;

}