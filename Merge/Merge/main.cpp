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
	//void MergeSortI(int *arr, int ini, int fin);
};


template<class compara>
void ordenamiento<compara>::MergeSort(int *a, int left, int right) {
	if (left == right)
		return;

	int middle = (left + right) >> 1;

	MergeSort(a, left, middle);
	MergeSort(a, middle + 1, right);

	int	l = middle - left + 1;
	int r = right - left;
	cout << l << r << "----" << endl;
	int *b = new int[l];
	int *c = new int[r];
	for (unsigned int i = 0; i < l; i++)
		*(b + i) = *(a + i);
	for (unsigned int j = 0; j < r; j++)
		*(c + j) = *(a + middle + 1 + j);

	int i = 0; int j = 0;
	int k = 0; 

	while (i < l and j <= r) {//pieces
		if (*(b + i) < *(c + j)) {
			*(a + k) = *(b + i);    i++;
		}
		else {
			*(a + k) = *(c + j);	j++;
		}
		k++;
	}
	while (i < l) {
		*(a + k) = *(b + i);	i++;	k++;
	}
	while (j < r) {
		*(a + k) = *(c + j);	j++;	k++;
	}
	/*
	for (unsigned int k = 0; k < t; k++) {
		cout << *(a + k);
	}*/
	delete b;
	delete c;
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
		if (*(a + i)> *(a + j)){
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
	while (j < right) {
		*(b + k) = *(a + j);	j++;	k++;
	}
	for (unsigned int k = 0; k < t; k++) {
		cout<<*(b+k);
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
		while (tmp>inic && compara(*(tmp - 1), *(tmp))<0)
		{
			swap(*(tmp - 1), *(tmp));
			tmp--;
		}
		arr++;
	}
}

void print(int *p, int tam) {
	for (int x = 0; x < tam; x++) {
		cout << *p << "\t";
		*p++;
	}
}
int main() {
	srand(time(NULL));
	time_t timer, timer2;

	const int t = 7;
	int arr[t]={38,27,43,3,9,82,10};
	/*
	int *arr = new int[t];
	for (int i = 0; i< t; i++) {
		arr[i] = ((rand() % t) - (rand() % t));
	}
	*/
	int *y;
	y = &arr[t - 1];//Fin
	print(arr,t);

	
	ordenamiento<comparacion> S;
	
	S.MergeSort(arr,0,t);
	cout<<"merge: "<<endl;
	print(arr,t);
	

	/*
	ofstream a;
	timer = clock();
	S.InsertSort(arr, y);
	timer2 = clock();
	cout << endl << "selection: " << endl;
	print(arr, t); //big numbers only comment is slown
	a.open("arr.txt");
	for (int i = 0; i< t; i++) {
		a << arr[i] << " ";
	}
	cout << endl << "TIEMPO: " << double(timer2 - timer) / CLOCKS_PER_SEC << endl;
	*/
	//delete[]arr;
	//*arr = NULL;

	system("pause");
	return 0;

}