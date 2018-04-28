#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


int main(int argc, char* argv[])
{
	ifstream input("D:\\repos\\StanfordAlgo\\course3\\week4\\Knapsack\\knapsack1.txt", ios::in);

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

	vector<vector<int64_t>> A(n + 1);

	for (int i = 1; i <= n; i++)
	{
		A[i].resize(capacity + 1, 0);
	}

		for (int x = 0; x <= capacity; x++)
		{
			for (int i = 1; i <= n; i++)
			{
				pair<int, int> item = items[i - 1];
				if (x - item.second >= 0) A[i][x] = max(A[i - 1][x], A[i - 1][x - item.second] + item.first);
				else A[i][x] = A[i - 1][x];

			}
		}

	cout << endl << "The optimal solution value is " << A[n][capacity];
}
