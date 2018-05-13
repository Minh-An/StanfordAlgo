#include <vector>
#include <set>
#include <iostream>

using namespace std;

void recursiveCombinations(int n, int m, int start, vector<set<int>>& combos, set<int>& S)
{
	if (m == 0)
	{
		S.emplace(1);
		combos.emplace_back(S);
		return;
	}
	for (int i = start; i <= n-m; i++)
	{
		S.emplace(i + 1);
		recursiveCombinations(n, m - 1, i + 1, combos, S);
		S.erase(--S.end());
	}
}

vector<set<int>> combinations(int n, int m)
{
	vector<set<int>> combos;
	set<int> S{};
	recursiveCombinations(n, m - 1, 1, combos, S);
	return combos;
}

int main()
{
	int count = 0;
	for (set<int> S: combinations(8,5))
	{
		count++;
		for (int i : S)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	cout << count << endl;
}