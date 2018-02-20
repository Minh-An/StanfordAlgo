#include "digraph.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>

Digraph::Digraph(int n) : n(n)
{
	adj.resize(n);
}

Digraph::Digraph(int n, string filename ) : Digraph(n)
{
	ifstream input(filename, ios::in);
	for (string line; getline(input, line);)
	{
		int next = line.find(" ");
		string s = line.substr(0, next);
		int v = stoi(s);
		s = line.substr(next + 1);
		int w = stoi(s);
		AddEdge(v, w);
	}
}

void Digraph::AddEdge(int v, int w)
{
	adj[v].emplace_back(w);
}


int Digraph::V()
{
	return n;
}

vector<int> Digraph::Adjacent(int v)
{
	return adj[v];
}

Digraph Digraph::Reverse()
{
	Digraph reverse = Digraph(n);
	for(int v = 0; v < adj.size(); v++)
	{
		for (int w: adj[v])
		{
			reverse.AddEdge(w, v);
		}
	}
	return reverse;
}

ostream & operator<<(ostream & out, Digraph & g)
{
	for (int v = 0; v < g.V(); v++)
	{
		out << v << ": ";
		for (int w : g.Adjacent(v))
		{
			out << w << " ";
		}
		out << endl;
	}
	return out;
}
