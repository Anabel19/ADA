/*
------------------------- MATRIX CHAIN MULTIPLICATION
DYNAMIC PROGRAMMING->time complexity is O(n^3)
brute force->time complexity is exponencial
*/
#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;
/*brute force*/
int MatrixChainMul(int i, int j, vector<int> d){
	int c;//cost
	int m[i][j];
	if(i==j) m[i][i]= 0;
	else{
		m[i][j]=INT_MAX;
		for(unsigned k=i; k<j; k++){
			c= MatrixChainMul(i,k,d)+MatrixChainMul(k+1,j,d)+d[i-1]*d[k]*d[j];
			if(c<m[i][j])
				m[i][j]=c;	
		}
	}	
	return m[i][j];
}

void BackTracking(int i, int j, vector<vector<int>>s, char &t){
	if(i==j) cout<<t++;
	else{
		cout<<"{";
		BackTracking(i,s[i][j],s,t);
		BackTracking(s[i][j]+1,j,s,t); cout<<"}";
	}
}
/*dynamic programming*/
int MatrixChainMul_dp(int n, vector<int> d){
	int m[n][n];
	//splitting markers	
	vector<vector<int>> s(n);
	//int s[n][n];
	char t='a';//or with number
	int j, tmp;
	for(unsigned i=1; i<n; i++){
		m[i][i]=0;//one matrix
		s[i].assign(n,0);
	}
	
	for(unsigned h=1; h<n-1;h++){ //h is chain lengt
		for(unsigned int i=1; i<n-h; i++){
			j=i+h;
			m[i][j]=INT_MAX; //maximum value
			for(unsigned int k=i; k<=j-1; k++){
				tmp=m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j];
				if(tmp<m[i][j])
					m[i][j]=tmp;
					s[i][j]=k;
			}
		}
	}
	BackTracking(1,n-1,s,t);	cout<<endl;
	return m[1][n-1];
}
main(){
	vector<int> b={10,20,50,1,100};
	//vector<int> b={10,100,20,5,80};
	int n=b.size();
	
	cout<<"FOURCE BRUTE"<<endl;
	cout<<"Minimum number of multiplications: "<<MatrixChainMul(1,n-1,b)<<endl<<endl;
	cout<<"DYNAMIC"<<endl;
	cout<<"Minimum number of multiplications: "<<MatrixChainMul_dp(n,b)<<endl;
}