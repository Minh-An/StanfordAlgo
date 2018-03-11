#include <unordered_set>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	unordered_set<int64_t> hashtable;

	string filename = "D:\\repos\\StanfordAlgo\\course2\\week4\\2Sum\\twoSum.txt";
	ifstream file(filename, ios::in);

	vector<int64_t> values;
	istream_iterator<int64_t> begin(file);
	istream_iterator<int64_t> eof;

	copy(begin, eof, back_inserter( values));
	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());

	cout << "Insertion done. " << values.size() << endl;

	vector<int64_t>::iterator low, high;
	for (int64_t x : values)
	{
		low = lower_bound(values.begin(), values.end(), -10000 - x);
		high = upper_bound(values.begin(), values.end(), 10000 - x);
		for (auto i = low; i != high+1; i++)
		{
			if (x + *i >= -10000 && x + *i <= 10000)
			{
				hashtable.insert(x + *i);
			}
		}
	}

	cout << hashtable.size() << endl;
}