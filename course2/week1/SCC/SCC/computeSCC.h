#pragma once

#include <stack>
#include "digraph.h"

class ComputeSCC
{
public:
	ComputeSCC(Digraph* G);
	stack<int> ReversePost();
	  
	friend ostream& operator<<(ostream& out, ComputeSCC& computeSCC);

private:

	vector<int> sccSizes;
	Digraph * graph;

	int DFS(int v, vector<bool>& marked);
	void ReverseDFS(Digraph& reverse, int v, stack<int>& order, vector<bool>& marked);
};

