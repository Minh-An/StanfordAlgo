#pragma once
#include <vector>
#include <functional>

using namespace std;

class PriorityQueue
{
public:
	PriorityQueue(const function<bool(int, int)>& comparator);
	void Insert(int i);
	int ExtractMin();
	int GetMin();

	int Size();
	bool IsEmpty();

private:
	vector<int> heap;
	int n;

	const function<bool(int, int)> comparator;

	void BubbleUp(int i);
	void BubbleDown(int i);
	void Switch(int i, int j);
};
