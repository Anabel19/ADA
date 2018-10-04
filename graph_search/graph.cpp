#include <iostream>
#include "graph.h"

using namespace std;

int main(){
	Cgraph<int> graph;
	for(unsigned int i=0; i<6; i++)
		graph.InsNode(i);
	//graph.randomEdge();
	cout<<graph.mnodes[0];
	/*
	graph.mnodes[0]->InsEdge(graph.mnodes[3]);
	graph.mnodes[0]->InsEdge(graph.mnodes[4]);
	graph.mnodes[1]->InsEdge(graph.mnodes[3]);
	graph.mnodes[1]->InsEdge(graph.mnodes[5]);
	graph.mnodes[2]->InsEdge(graph.mnodes[4]);
	graph.mnodes[3]->InsEdge(graph.mnodes[0]);
	graph.mnodes[3]->InsEdge(graph.mnodes[1]);
	graph.mnodes[4]->InsEdge(graph.mnodes[0]);
	graph.mnodes[4]->InsEdge(graph.mnodes[2]);
	graph.mnodes[5]->InsEdge(graph.mnodes[1]);
	graph.mnodes[5]->InsEdge(graph.mnodes[4]);*/
	graph.printGraph();
	return 0;
}