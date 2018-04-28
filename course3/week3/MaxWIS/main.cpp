#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string filename = "D:\\repos\\StanfordAlgo\\course3\\week3\\MaxWIS\\mwis.txt";
	ifstream input(filename, ios::in);

	int n;
	input >> n;

	vector<int> weights;
	while (true) {
		int x;
		input >> x;
		weights.emplace_back(x);
		if (input.eof()) break;
	}

	vector<int> totalWeights(n + 1);
	totalWeights[1] = weights[0];

	for (int i = 2; i < totalWeights.size(); i++)
	{
		totalWeights[i] = max(totalWeights[i - 1], totalWeights[i - 2] + weights[i - 1]);
	}

	vector<int> WIS;

	int i = n;
	
	while(i>0)
	{
		if (i > 1 && totalWeights[i-1] >= totalWeights[i-2] + weights[i-1])
		{
			i--;
		}
		else
		{
			WIS.emplace_back(i);
			i -= 2;
		}
	}

	vector<int> test = { 1, 2, 3, 4, 17, 117, 517, 997 };

	for (int v : test)
	{
		if (find(WIS.begin(), WIS.end(), v)!= WIS.end())
		{
			cout << "1";
		}
		else cout << "0";
	}
	cout << endl;

}