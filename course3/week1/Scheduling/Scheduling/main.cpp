#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int64_t WeightedCompletionTimes(vector<pair<int, int>>& jobs)
{
	int64_t sum = 0;
	int64_t completionTime = 0;
	for (int i = 0; i < jobs.size(); i++)
	{
		completionTime += jobs[i].second;
		sum += (completionTime * jobs[i].first);
	}
	return sum;
}

int main()
{
	vector<pair<int, int>> jobs;

	ifstream input("D:\\Downloads\\jobs.txt", ios::in);
	string line;
	getline(input, line);
	//jobs.resize(stoi(line));

	while (getline(input, line))
	{
		stringstream lineStream(line);
		int weight, length;
		lineStream >> weight;
		lineStream >> length;
		jobs.emplace_back(make_pair(weight, length));
	}


	sort(jobs.begin(), jobs.end(), [](const pair<int, int> & a, const pair<int, int> & b) -> bool
	{
		if ((a.first - a.second) == (b.first - b.second))
		{
			return a.first > b.first;
		}
		return (a.first - a.second) > (b.first - b.second);
	});
	
	cout << WeightedCompletionTimes(jobs) << endl;


	sort(jobs.begin(), jobs.end(), [](const pair<int, int> & a, const pair<int, int> & b) -> bool
	{
		return (static_cast<double>(a.first) / a.second) > (static_cast<double>(b.first) / b.second);
	});

	cout << WeightedCompletionTimes(jobs) << endl;

}