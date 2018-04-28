/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Knapsack(vector<pair<int, int>>& items, int i, int x)
{
	pair<int, int> item = items[i - 1];
	if (i == 1)
	{
		if (x < item.second) return 0;
		return item.first;
	}

	if (x - item.second >= 0) return max(Knapsack(items, i - 1, x), Knapsack(items, i - 1, x - item.second) + item.first);
	else return Knapsack(items, i - 1, x);
}


struct PairHash {
	size_t operator()(const std::pair<int, int>& p) const {
		return p.first ^ p.second;
	}
};

int main()
{
	unordered_map<std::pair<int, int>, int, PairHash> hashtable;

	string filename = "D:\\repos\\StanfordAlgo\\course3\\week4\\Knapsack\\knapsack1.txt";
	ifstream input(filename, ios::in);

	int capacity;
	input >> capacity;

	int n;
	input >> n;

	vector<pair<int, int>> items;
	for (int i = 0; i < n; i++) {
		int v, w;
		input >> v;
		input >> w;
		items.emplace_back(make_pair(v, w));
	}

	cout << Knapsack(items, n, capacity);
}
*/