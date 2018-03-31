#include "priority_queue.h"
#include <iostream>
#include <algorithm>

PriorityQueue::PriorityQueue(const function<bool(pair<int, int>, pair<int, int>)>& comparator): compare(comparator), n(0)
{
	heap.emplace_back(pair<int,int>());
}

void PriorityQueue::Insert(pair<int, int> i)
{
	heap.emplace_back(i);
	n++;
	indexes[i.first] = n;
	BubbleUp(n);
}

void PriorityQueue::Delete(int v)
{
	if (!IsEmpty())
	{
		int index = indexes[v];
		Swap(index, n--);
		BubbleUp(index);
		BubbleDown(index);
		heap.pop_back();
		indexes.erase(v);
	}
}

int PriorityQueue::Get(int v)
{
	if (!IsEmpty())
	{
		if (indexes.find(v) != indexes.end())
		{
			return heap[indexes[v]].second;
		}
	}
	return 0;
}

pair<int, int> PriorityQueue::Pop()
{
	if (!IsEmpty())
	{
		pair<int, int> min = heap[1];
		Swap(1, n--);
		BubbleDown(1);
		heap.pop_back();
		indexes.erase(min.first);
		return min;
	}
	return pair<int, int>();
}

pair<int, int> PriorityQueue::Top()
{
	if (!IsEmpty())
	{
		return heap[1];
	}
	return pair<int, int>();
}

int PriorityQueue::Size()
{
	return n;
}

bool PriorityQueue::IsEmpty()
{
	return n == 0;
}

void PriorityQueue::BubbleUp(int i)
{
	while (i > 1 && compare(heap[i], heap[i / 2]))
	{
		Swap(i, i / 2);
		i = i / 2;
	}
}

void PriorityQueue::BubbleDown(int i)
{
	while (2*i <= n)
	{
		int j = 2 * i;

		if (j < n && compare(heap[j+1], heap[j]))
		{
			j++;
		}
		if (compare(heap[i], heap[j]))
		{
			return;
		}

		Swap(i, j);
		i = j;
	}
}

void PriorityQueue::Swap(int i, int j)
{
	indexes[heap[i].first] = j;
	indexes[heap[j].first] = i;
	iter_swap(heap.begin() + i, heap.begin() + j);
}
