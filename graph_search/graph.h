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
	typedef Cnode<self>  Node;
	typedef N n_;
    vector<Node*> mnodes;
	deque<Node*> q;
	
	bool find(Node*, unsigned int &id);
	void InsNode(N);
	void first_queue(){q.push_back(mnodes[0]);}
	void dfs();
	void printGraph();
	virtual ~Cgraph(){
		unsigned int t = mnodes.size(), i;
        for(i=0; i<t; i++)  delete mnodes[i];
	}
};

template<class N>
bool Cgraph<N>::find(Node* d, unsigned int &id){
	for(id=0; id< mnodes.size(); id++){
		if(mnodes[id]->date==d)  return 1;
	}
	return 0;
}

template<class N>	
void Cgraph<N>::InsNode(N date){
	Node* new_node= new Node(date);
	mnodes.push_back(new_node);
}

template<class N>	
void Cgraph<N>::dfs(){
	if(!q.empty()){
		Node *v= q.front();
		cout<<"-- "<<v->date;
		q.pop_front();
		v->color= Node::b;
		for (typename list<Node*>::iterator it= v->nneighbors.begin(); it != v->nneighbors.end(); ++it){
			if((*it)->color== Node::w){
				(*it)->color== Node::g;
				q.push_back(*it);
			}
		}
		dfs();
	}
}
	
template<class N>	
void Cgraph<N>::printGraph(){
	for(int i=0; i<mnodes.size(); i++) {//ingreso al vector de nodos del grafo
		Node *tmp_node = mnodes[i]; // cada nodo
		//cout<<tmp_node->date;// etiqueta-valor de cada nodo

		for (typename list<Node*>::iterator it= tmp_node->nneighbors.begin(); it != tmp_node->nneighbors.end(); ++it){
			cout<<" ---> "<< (tmp_node)->date<<"("<<(*it)->date<<")";
			cout<<endl;
		}
		cout<<"\n";
	}
}

#endif //GRAPH_H