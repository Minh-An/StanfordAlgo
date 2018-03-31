#include "priority_queue.h"
#include "weighted_graph.h"	
#include <iostream>
#include <climits>

using namespace std;

int64_t PrimsMST(WeightedGraph& g)
{
	int64_t cost = 0;
	PriorityQueue queue([](pair<int,int> x, pair<int, int> y)
	{
		return x.second < y.second;
	});

	int s = 0; //starting vertex

	for (int i = 1; i < g.V(); i++)
	{
		queue.Insert(make_pair(i, INT_MAX));
	}
	
	for (pair<int, int> v : g.Adjacent(s))
	{
		queue.Delete(v.first);
		queue.Insert(v);
	}

	vector<pair<int, int>> MST = { make_pair(s, 0) };

	while (!queue.IsEmpty())
	{
		pair<int,int> x = queue.Pop();
		MST.emplace_back(x);
		cost += x.second;
		for (pair<int, int> e : g.Adjacent(x.first))
		{
			if(queue.Get(e.first) != 0 && e.second < queue.Get(e.first))
			{
				queue.Delete(e.first);
				queue.Insert(e);
			}
		}
	}

	return cost;

}

int main()
{
	WeightedGraph g("D:\\Downloads\\edges.txt");
	cout << g << endl;
	cout << PrimsMST(g) << endl;
}