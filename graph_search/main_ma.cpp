#include <iostream>
#include "graph_ma.h"

using namespace std;

int main(){
	Cgraph<float> graph;
	
	//graph.randomEdge();
	graph.createVertex();
	graph.createEdges();
	graph.printGraph();
	graph.first_queue();
	cout<<"dfs: "<<endl;
	graph.dfs();
	return 0;
}