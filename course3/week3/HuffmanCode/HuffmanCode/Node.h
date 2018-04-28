#pragma once
#include <iostream>
#include <memory>

using namespace std;

class Node
{
public:
	Node(int id, int weight): id(id), weight(weight)
	{
	}

	Node(int weight, Node* left, Node* right): weight(weight), left(left), right(right), id(-1)
	{
	}

	bool isLeaf()
	{
		return (left == nullptr && right ==nullptr);
	}

	int id;
	int weight;
	Node* left;
	Node* right;
};