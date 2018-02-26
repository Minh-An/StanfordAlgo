#include "dijkstra.h"
#include <queue>
#include <climits>
#include <algorithm>

class DijkstraComparator
{
public:
	bool operator()(const pair<int, int>&i, const pair<int, int>&j)
	{
		return i.second > j.second;
	}
};

Dijkstra::Dijkstra(int s, WeightedDigraph& g)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, DijkstraComparator> queue;
	distances.resize(g.V());
	fill(distances.begin(), distances.end(), -1);
	queue.push({s, 0});
	
	while (!queue.empty())
	{
		pair<int,int> min = queue.top();
		int v = min.first;
		queue.pop();
		if (distances[v] == -1)
		{
			distances[v] = min.second;
			for (pair<int, int> p : g.Adjacent(min.first))
			{
				int score = distances[v] + p.second;
				queue.push({p.first,score});
			}
		}
	}
}

ostream & operator<<(ostream & out, Dijkstra & dijkstra)
{
	for (int i = 0; i < dijkstra.distances.size(); i++)
	{
		out << i << ": " << dijkstra.distances[i] << endl;
	}

	int testInputs[10] = { 6,36,58,81,98,114,132,164,187,196 };
	for (int i : testInputs)
	{
		out << dijkstra.distances[i] << ",";
	}
	out << endl;

	return out;
}
