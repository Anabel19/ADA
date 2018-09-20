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
};


template<class compara>
void ordenamiento<compara>::MergeSort(int *A, int start, int end) {
	
	if (start < end) {
		int t = end - start + 1;
		int medium = (start + end) >> 1;
		MergeSort(A, start, medium);
		MergeSort(A, medium+1, end);
		/*
		int *b = new int[t];
		for(unsigned int i=0; i<t; i++)
			*/
		int *b = new int[t];
		for (int i = 0; i<t; i++)
			*(b + i) = *(A + end + i);
		int j = 0;
		int k = medium - start + 1;

		for (int i = 0; i < t; i++) {
			if (k <= end - start)
				if (j <= medium - start)
					if (c_sort(*(b + k), *(b + j)))	*(A + i + start) = *(b + k++);
					else	*(A + i + start) = *(b + j++);
				else
					*(A + i + start) = *(b + k++);
			else
				*(A + i + start) = *(b + j++);
		}
		delete b;
	}
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
	//cout<<"bubble: "<<endl;
	//print(arr,t);
	

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
	delete[]arr;
	*arr = NULL;

	system("pause");
	return 0;

}