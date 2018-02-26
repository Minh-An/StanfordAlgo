#pragma once

#include "weighted_digraph.h"

class Dijkstra
{
public:
	Dijkstra(int s, WeightedDigraph& g);
	friend ostream& operator<<(ostream& out, Dijkstra& dijkstra);

private:
	vector<int> distances;
};

