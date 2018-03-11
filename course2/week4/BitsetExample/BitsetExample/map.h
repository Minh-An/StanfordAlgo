#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

class Map
{
public:
	Map(string input)
	{
		int x;
		int prev = 0;
		int next = next = input.find(" ");
		string s;
		for (int i = 0; i < 8; i++)
		{
			string row = input.substr(prev, next);
			stringstream ss;
			ss << std::hex << row;
			ss >> x;
			bitset<8> bs((uint8_t)x);
			rows.emplace_back(bs);

			prev = next + 1;
			next = input.find(" ", prev);
		}
	}

	bool GetValue(int row, int col)
	{
		return rows[col - 1][8 - row];
	}

private:
	vector<bitset<8>> rows;
};