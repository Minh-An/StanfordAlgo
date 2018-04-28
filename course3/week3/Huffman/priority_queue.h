#pragma once
#include "node.h"
#include <vector>
#include <functional>

using namespace std;

class PriorityQueue
{
public:
	PriorityQueue(const function<bool(Node*, Node*)>& comparator);
	void Insert(Node* i);
	Node* Pop();
	Node* Top();

	int Size();
	bool IsEmpty();

private:
	vector<Node*> heap;
	int n;

	const function<bool(Node*, Node*)> comparator;

	void BubbleUp(int i);
	void BubbleDown(int i);
	void Swap(int i, int j);
};
