#pragma once

#include <vector>
#include <string>

using namespace std;

class Digraph
{ 

public:
	Digraph(int n);
	Digraph(int n, string filename);
	void AddEdge(int v, int w);
	int V();
	vector<int> Adjacent(int v);
	Digraph Reverse();

	friend ostream& operator<<(ostream& out, Digraph& g);

private:
	int n;
	vector<vector<int>> adj;
};

