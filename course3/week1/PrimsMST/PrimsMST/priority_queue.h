#pragma once
#include <vector>
#include <functional>
#include <utility>
#include <unordered_map>

using namespace std;

class PriorityQueue
{
public:
	PriorityQueue(const function<bool(pair<int, int>, pair<int, int>)>& comparator);
	void Insert(pair<int, int> i);
	void Delete(int v);
	int Get(int v);
	pair<int, int> Pop();
	pair<int, int> Top();

	int Size();
	bool IsEmpty();

private:
	vector<pair<int, int>> heap;
	unordered_map<int, int> indexes;
	int n;

	const function<bool(pair<int, int>, pair<int, int>)> compare;

	void BubbleUp(int i);
	void BubbleDown(int i);
	void Swap(int i, int j);
};
