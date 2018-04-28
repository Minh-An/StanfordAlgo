#include "priority_queue.h"
#include <iostream>

PriorityQueue::PriorityQueue(const function<bool(Node*, Node*)>& comparator): comparator(comparator), n(0)
{
	heap.emplace_back(nullptr);
}

void PriorityQueue::Insert(Node* i)
{
	heap.emplace_back(i);
	n++;
	BubbleUp(n);
}

Node* PriorityQueue::Pop()
{
	if (!IsEmpty())
	{
		Node* min = heap[1];
		Swap(1, n--);
		BubbleDown(1);
		heap.pop_back();
		return min;
	}
	return nullptr;
}

Node* PriorityQueue::Top()
{
	if (!IsEmpty())
	{
		return heap[1];
	}
	return nullptr;
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
	Node* temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}
