#include "weighted_graph.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
	
WeightedGraph::WeightedGraph(int n): n(n)
{
	adj.resize(n);
}

WeightedGraph::WeightedGraph(string filename)
{
	ifstream input(filename, ios::in);
	string line;
	getline(input, line);
	n = stoi(line.substr(0, line.find(" ")));
	adj.resize(n);

	while (getline(input, line))
	{
		stringstream lineStream(line);
		int v, w, weight;
		char no_op;
		lineStream >> v;
		while (lineStream >> w)
		{
			lineStream >> weight;
			AddEdge(v - 1, w - 1, weight);
		}
	}
}

void WeightedGraph::AddEdge(int v, int w, int weight)
{
	adj[v].emplace_back(make_pair(w, weight));
	adj[w].emplace_back(make_pair(v, weight));
}

int WeightedGraph::V()
{
	return n;
}

vector<pair<int, int>> WeightedGraph::Adjacent(int v)
{
	return adj[v];
}

ostream & operator<<(ostream & out, WeightedGraph & g)
{
	for (int v = 0; v < g.V(); v++)
	{
		out << v << ": ";
		for (pair<int, int> w : g.Adjacent(v))
		{
			out << w.first << "," << w.second << " ";
		}
		out << endl;
	}
	return out;
}
