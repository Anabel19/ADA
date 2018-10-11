#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <vector>
#include <deque>
 
 using namespace std;
template <class T>
class Cnode{
	public:
	typedef typename T::n_ N;
	N date;
	enum label{
		w,b,g //white, black, gris
	};
	label color;
	list<Cnode*> nneighbors;
	
	Cnode(N value){
		this->date= value;
		color=w;
	}
	void InsEdge(Cnode *b){
		nneighbors.push_back(b);
	}
};

template<class N>
class Cgraph{
	public:
	typedef Cgraph<N>  self;
	typedef Cnode<self>  gNode;
	typedef N n_;
    //vector<Node*> mnodes;
	deque<gNode*> q;
	
	bool find(gNode*);
	void createVertex();
	void createEdges();
	void first_queue(){q.push_back(malla[0][0]);}
	void dfs();
	void printGraph();
	gNode ***malla;//double pointer[#error!]
	int col=6;	int row=6;
	Cgraph(){
		malla= new gNode**[row];
		for(unsigned int i=0; i<row; i++){
			malla[i]= new gNode*[col];
		}
	}
	virtual ~Cgraph(){
        for(unsigned int i=0; i<row; i++) 
			delete malla[i];
		delete malla;
	}
};

template<class N>
bool Cgraph<N>::find(gNode* d){
	for(unsigned int i=0; i< row; i++){
		for(unsigned int j=0; j< col; j++){
			if(malla[i][j]->date==d)  return 1;
		}
	}
	return 0;
}

template<class N>
void Cgraph<N>::createVertex(){
	int k=0;
	for(unsigned int i=0; i<row; i++){
		for(unsigned int j=0; j<col; j++){
		     malla[i][j]=new gNode(k);
			 k++;
		} 	
	} 
}
template<class N>
void Cgraph<N>::createEdges(){
	malla[0][0]->InsEdge(malla[4][4]);
	malla[0][0]->InsEdge(malla[3][3]);
	malla[1][1]->InsEdge(malla[5][5]);
	malla[1][1]->InsEdge(malla[4][4]);
	malla[2][2]->InsEdge(malla[0][0]);
	malla[3][3]->InsEdge(malla[1][1]);
	malla[3][3]->InsEdge(malla[0][0]);
	/*
	for(unsigned int i=0;i<row-1;i++){
		for(unsigned int j=0;j<col-1;j++){
			malla[i][j]->EdgeNode(malla[i][j+1]);
		}
	}*/
}

template<class N>	
void Cgraph<N>::dfs(){
	if(!q.empty()){
		gNode *v= q.front();
		cout<<"-- "<<v->date;
		q.pop_front();
		v->color= gNode::b;
		for (typename list<gNode*>::iterator it= v->nneighbors.begin(); it != v->nneighbors.end(); ++it){
			if((*it)->color== gNode::w){
				(*it)->color== gNode::g;
				q.push_back(*it);
			}
		}
		dfs();
	}
}
	
template<class N>
void Cgraph<N>::printGraph(){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
		    cout<<malla[i][j]->date;
		}
		cout<<endl;
	}
	cout<<"edjesss  "<<endl;
	for(unsigned int i=0; i<row-1; i++){
		for(unsigned int j=0;j<col-1;j++){
			//cout<<malla[i][j]->x<<","<<malla[i][j]->y<<" ";
			for(typename std::list<gNode *>::iterator it = malla[i][j]->nneighbors.begin(); it!=malla[i][j]->nneighbors.end(); it++){
				cout<<(*it)->date;	
			}
			//cout<<endl;
		}
	}		
}

#endif //GRAPH_H