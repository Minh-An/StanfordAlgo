#include "computeSCC.h"
#include <iostream>
#include <algorithm>

ComputeSCC::ComputeSCC(Digraph* G): graph(G)
{
	vector<bool> marked(graph->V());
	stack<int> order = ReversePost();
	while (!order.empty())
	{
		int v = order.top();
		if (!marked[v])
		{
			int sccSize = DFS(v, marked);
			sccSizes.emplace_back(sccSize);
		}
		order.pop();
	}

	sort
	(
		sccSizes.begin(), sccSizes.end(), [](auto& a, auto& b) { return b < a; }
	);

}

stack<int> ComputeSCC::ReversePost()
{
	stack<int> order;
	Digraph reverse = graph->Reverse();
	vector<bool> marked(reverse.V());
	for (int v = 0; v < reverse.V(); v++)
	{
		if (!marked[v])
		{
			
			ReverseDFS(reverse, v, order, marked);
		}
	}
	return order;
}

int ComputeSCC::DFS(int v, vector<bool>& marked)
{
	int sccSize = 1;
	marked[v] = true;
	for (int w : graph->Adjacent(v))
	{
		if (!marked[w])
		{
			sccSize += DFS(w, marked);
		}
	}
	return sccSize;
}

void ComputeSCC::ReverseDFS(Digraph& reverse, int v, stack<int>& order, vector<bool>& marked)
{
	marked[v] = true;
	for (int w: reverse.Adjacent(v))
	{
		if (!marked[w])
		{
			ReverseDFS(reverse, w, order, marked);
		}
	}
	
	order.push(v);
}

ostream & operator<<(ostream & out, ComputeSCC & computeSCC)
{
	for (int i = 0; i < 5; i++)
	{
		out << computeSCC.sccSizes[i] << " ";
	}
	out << endl;
	return out;
}
