#include <iostream>
#include "map.h"

int main()
{
	string rows = "C C7 85 D6 46 D7 E6 87";
	Map map(rows);

	for (int y = 1; y <= 8; y++)
	{
		for (int x = 1; x <= 8; x++)
		{
			if (map.GetValue(x, y))
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}
