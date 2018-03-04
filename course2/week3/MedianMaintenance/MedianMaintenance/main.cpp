#include <iostream>
#include <fstream>
#include "priority_queue.h"

int sumMedians(string filename)
{
	int sum = 0;

	//stores greater half of the numbers
	PriorityQueue high([](int x, int y)
	{
		return x < y;
	});
	
	//stores lower half of the numbers
	PriorityQueue low([](int x, int y)
	{
		return x > y;
	});

	ifstream input(filename, ios::in);
	int median = 0;
	int next;
	while (input >> next)
	{
		if (next > median)
		{
			if (high.Size() > low.Size())
			{
				int num = high.ExtractMin();
				low.Insert(num);
			}
			high.Insert(next);
		}
		else
		{
			if (low.Size() > high.Size())
			{
				int num = low.ExtractMin();
				high.Insert(num);
			}
			low.Insert(next);
		}

		//find median
		if (high.Size() > low.Size()) median = high.GetMin();
		else median = low.GetMin();
		sum += median;
	}

	return sum;
}


int main()
{
	int sum = sumMedians("D:\\repos\\StanfordAlgo\\course2\\week3\\MedianMaintenance\\Median.txt");
	cout << sum << endl;
	cout << sum % 10000 << endl;
}

