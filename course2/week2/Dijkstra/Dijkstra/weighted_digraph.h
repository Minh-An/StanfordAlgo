#pragma once

#include <string>
#include <vector>
#include <utility>

using namespace std;
class WeightedDigraph
{
public:
	WeightedDigraph(int n);
	WeightedDigraph(int n, string filename);
	void AddEdge(int v, int w, int weight);
	int V();
	vector<pair<int,int>> Adjacent(int v);

	friend ostream& operator<<(ostream& out, WeightedDigraph& g);

private:
	int n;
	vector<vector<pair<int,int>>> adj;

};
