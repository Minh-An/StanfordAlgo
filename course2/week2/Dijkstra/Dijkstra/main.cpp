#include <iostream>
#include "weighted_digraph.h"
#include "dijkstra.h"


int main()
{
	WeightedDigraph g(200, "D:\\repos\\StanfordAlgo\\course2\\week2\\Dijkstra\\dijkstraData.txt");
	//cout << g; 
	Dijkstra dijkstra(0, g);
	cout << dijkstra;
}