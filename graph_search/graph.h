#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <vector>
#include <queue>
 
 using namespace std;
template <class T>
class Cnode{
	public:
	T date;
	string label;
	list<Cnode*> nneighbors;
	
	Cnode(T value){
		this->date= value;
	}
	void InsEdge(Cnode *b){
		nneighbors.push_back(b);
	}
};

template<class N>
class Cgraph{
	public:
	typedef CGraph<N>  self;
	typedef CNode<self>  Node;
    vector<Node*> mnodes;
	bool find(Node*, unsigned int &id);
	void InsNode(N);
	void randomEdge();
	void printGraph();
	virtual ~Cgraph(){
		unsigned int t = mnodes.size(), i;
        for(i=0; i<t; i++)  delete mnodes[i];
	}
};

template<class N>
bool Cgraph<N>::find(Cnode*, unsigned int &id){
	for(id=0; id< mnodes.size(); id++){
		if(mnodes[id]->value==d)  return 1;
	}
	return 0;
}

template<class N>	
void Cgraph<N>::InsNode(N date){
	Node* new_node= new Node(date);
	mnodes.push_back(new_node);
}

template<class N>	
void Cgraph<N>::dfs(queue q){
	if(!q.empty){
		Node *v= q.pop_front();
		v.color=b;
		for (typename list<Node*>::iterator it= v->nneighbors.begin(); it != v->nneighbors.end(); ++it){
			if((*it)->color==w){
				(*it)->color==q;
				q.push_back(*it);
			}
		}
	}
	dfs(q);
}
	
template<class N>	
void Cgraph<N>::printGraph(){
	for(int i=0; i<mnodes.size(); i++) {//ingreso al vector de nodos del grafo
		Node *tmp_node = mnodes[i]; // cada nodo
		//cout<<tmp_node->date;// etiqueta-valor de cada nodo

		for (typename list<Node*>::iterator it= tmp_node->nneighbors.begin(); it != tmp_node->nneighbors.end(); ++it){
			cout<<" ---> "<< (*tmp_node)->date<<"("<<(*it)->date<<")";
			cout<<endl;
		}
		cout<<"\n";
	}
}

#endif //GRAPH_H