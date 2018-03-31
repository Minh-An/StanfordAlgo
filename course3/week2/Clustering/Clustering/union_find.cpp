#include "union_find.h"


UnionFind::UnionFind(int n)
{
	rank.resize(n);
	for (int i = 0; i < n; i++)
	{
		parent.emplace_back(i);
	}
}

int UnionFind::Find(int v)
{
	int root = v;
	while (root != parent[root]) { root = parent[root]; }
	return root;
}

void UnionFind::Union(int v, int w)
{
	int rootV = Find(v);
	int rootW = Find(w);
	if (rank[rootV] > rank[rootW]) { parent[rootW] = rootV; }
	else
	{
		if (rank[rootV] == rank[rootW]) { rank[rootW]++; }
		parent[rootV] = rootW;
	}
}

