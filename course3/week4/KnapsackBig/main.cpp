#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	string filename = "D:\\repos\\StanfordAlgo\\course3\\week4\\KnapsackBig\\knapsack_big.txt";
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

	vector<int64_t> previous(capacity + 1, 0);
	vector<int64_t> current(capacity + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		for (int x = 0; x <= capacity; x++)
		{
			pair<int, int> item = items[i - 1];
			if (x - item.second >= 0) current[x] = max(previous[x], previous[x - item.second] + item.first);
			else current[x] = previous[x];
		}
		previous = current;
	}

	cout << current[capacity];
}
