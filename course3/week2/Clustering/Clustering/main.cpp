#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <sstream>
#include <algorithm>

#include "union_find.h"

int main(int argc, char *argv[])
{
	int k = stoi(argv[1]);

	string filename = "D:\\repos\\StanfordAlgo\\course3\\week2\\Clustering\\clustering1.txt";
	ifstream input(filename, ios::in);
	string line;
	getline(input, line);
	int n = stoi(line);
	
	vector <tuple<int, int, int>> edges;
	UnionFind uf(n);

	while (getline(input, line))
	{
		stringstream lineStream(line);
		int v, w, weight;
		lineStream >> v;
		while (lineStream >> w)
		{
			lineStream >> weight;
			edges.emplace_back(make_tuple(v - 1, w - 1, weight));
		}
	}

	sort(edges.begin(), edges.end(),
	[](const tuple<int, int, int> & a, const tuple<int, int, int> & b) -> bool
	{
		return get<2>(a) < get<2>(b);
	});

	int clusters = n;
	int i = 0;
	for(tuple<int,int,int> edge : edges)
	{
		if (uf.Find(get<0>(edge)) != uf.Find(get<1>(edge)))
		{
			if (clusters == k)
			{
				cout << get<2>(edge) << endl;
				return 0;
			}
			uf.Union(get<0>(edge), get<1>(edge));
			clusters--;
		}
	}

	cout << clusters << endl;
	return 0;
	//for (tuple<int, int, int> t : edges) cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;

}