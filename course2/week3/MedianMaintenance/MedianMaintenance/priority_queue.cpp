#include "priority_queue.h"
#include <iostream>

PriorityQueue::PriorityQueue(const function<bool(int, int)>& comparator): comparator(comparator), n(0)
{
	heap.emplace_back(0);
}

void PriorityQueue::Insert(int i)
{
	heap.emplace_back(i);
	n++;
	BubbleUp(n);
}

int PriorityQueue::Pop()
{
	if (!IsEmpty())
	{
		int min = heap[1];
		Swap(1, n--);
		BubbleDown(1);
		heap.pop_back();
		return min;
	}
	return 0;
}

int PriorityQueue::Top()
{
	if (!IsEmpty())
	{
		return heap[1];
	}
	return 0;
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
	while (i > 1 && comparator(heap[i], heap[i / 2]))
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

		if (j < n && comparator(heap[j+1], heap[j]))
		{
			j++;
		}
		if (comparator(heap[i], heap[j]))
		{
			return;
		}

		Swap(i, j);
		i = j;
	}
}

void PriorityQueue::Swap(int i, int j)
{
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}
