#pragma once
#include <vector>

using namespace std;

class UnionFind
{
public:
	UnionFind(int n);
	int Find(int v);
	void Union(int v, int w);

private:
	vector<int> parent;
	vector<int> rank;
};

