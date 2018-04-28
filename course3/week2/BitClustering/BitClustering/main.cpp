#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <bitset>
#include <cmath> 
#include <unordered_map>
#include "union_find.h"

int main()
{
	string filename = "D:\\repos\\StanfordAlgo\\course3\\week2\\BitClustering\\clustering_big.txt";
	ifstream input(filename, ios::in);

	string line;
	getline(input, line);
	int space = line.find(" ");
	int n = stoi(line.substr(0,space));
	int bits = stoi(line.substr(space+1));
	
	unordered_set<uint32_t> nodes;

	while (getline(input, line))
	{
		line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
		uint32_t node = stoul(line, nullptr, 2);
		nodes.insert(node);
	}

	unordered_map<uint32_t, int> ids;
	int count = 0;
	for (uint32_t node : nodes)
	{
		ids.emplace(node, count++);
	}

	cout << count << endl;

	UnionFind uf(count);

	cout << "insertion done" << endl;

	cout << uf.Clusters() << endl;

	for (uint32_t node: nodes)
	{
		bitset<24> bs(node);
		for (int i = 0; i < bits; i++)
		{
			bs.flip(i);
			if (nodes.find(bs.to_ulong()) != nodes.end()) uf.Union(ids[node], ids[bs.to_ulong()]);
			for (int j = i+1; j < bits; j++)
			{
				bs.flip(j);
				if (nodes.find(bs.to_ulong()) != nodes.end()) uf.Union(ids[node], ids[bs.to_ulong()]);
				bs.flip(j);
			}
			bs.flip(i);
		}

	}
	cout << uf.Clusters() << endl;

	return 0;
}