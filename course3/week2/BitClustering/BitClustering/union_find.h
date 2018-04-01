#pragma once
#include <vector>
#include <unordered_set>

using namespace std;

class UnionFind
{
public:
	UnionFind(int n);
	int Find(int v);
	void Union(int v, int w);
	int Clusters();

private:
	vector<int> parent;
	vector<int> rank;
	int count;
};

