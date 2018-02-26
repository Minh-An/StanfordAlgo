#include <iostream>
#include "weighted_digraph.h"
#include "dijkstra.h"


int main()
{
	WeightedDigraph g(200, "D:\\Downloads\\dijkstraData.txt");
	//cout << g; 
	Dijkstra dijkstra(0, g);
	cout << dijkstra;
}