#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void printItemInfo(int capacity, vector<pair<int, int>>& items)
{
	cout << "The total capacity is " << capacity << endl;
	cout << items.size() << " Items: " << endl;
	for (int i = 0; i < items.size(); i++)
	{
		cout << i + 1 << " - Value:" << items[i].first << ", Size:" << items[i].second << endl;
	}
}

getMaxSolution(vector<vector<int64_t>>& A, pair<int, int>& item)
{
	if (x - item.second >= 0) A[i][x] = max(A[i - 1][x], A[i - 1][x - item.second] + item.first);
	else A[i][x] = A[i - 1][x];
}

int main(int argc, char* argv[])
{
	cout << "Enter the file name: ";
	string filename;
	getline(cin, filename);
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

	printItemInfo(capacity, items);

	// Algorithm Pseudocode derived from Coursera course : Algorithms - Stanford University taught by Tim Roughgarden
	vector<vector<int64_t>> A(n + 1);

	for (int i = 1; i <= n; i++)
	{
		A[i].resize(capacity + 1, 0);
	}

	if (i > 0 || capacity > 0)
	{
		for (int x = 0; x <= capacity; x++)
		{
			for (int i = 1; i <= n; i++)
			{
				pair<int, int> item = items[i - 1];
				getMaxSolution(A, item);
			}
		}
	}

	cout << endl << "The optimal solution value is " << A[n][capacity];
}
