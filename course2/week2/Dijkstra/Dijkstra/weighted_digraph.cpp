#include "weighted_digraph.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

WeightedDigraph::WeightedDigraph(int n): n(n)
{
	adj.resize(n);
}

WeightedDigraph::WeightedDigraph(int n, string filename): WeightedDigraph(n)
{
	ifstream input(filename, ios::in);
	for (string line; getline(input, line);)
	{

		stringstream lineStream(line);
		int v, w, weight;
		char no_op;
		lineStream >> v;
		while (lineStream >> w)
		{
			lineStream >> no_op;
			lineStream >> weight;
			AddEdge(v-1, w-1, weight);
		}
	}
}

void WeightedDigraph::AddEdge(int v, int w, int weight)
{
	adj[v].emplace_back(make_pair(w, weight));
}

int WeightedDigraph::V()
{
	return n;
}

vector<pair<int, int>> WeightedDigraph::Adjacent(int v)
{
	return adj[v];
}

ostream & operator<<(ostream & out, WeightedDigraph & g)
{
	for (int v = 0; v < g.V(); v++)
	{
		out << v << ": ";
		for (pair<int,int> w : g.Adjacent(v))
		{
			out << w.first << "," << w.second << " ";
		}
		out << endl;
	}
	return out;
}