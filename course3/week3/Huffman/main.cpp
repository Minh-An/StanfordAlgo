#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include "priority_queue.h"

using namespace std;

void getCodeLengths(vector<int>& lengths, Node* x, int length)
{
	if (!x->isLeaf()) {
		getCodeLengths(lengths, x->left, length + 1);
		getCodeLengths(lengths, x->right, length + 1);
	}
	else {
		lengths.emplace_back(length);
	}
}

int main()
{
	string filename = "D:\\repos\\StanfordAlgo\\course3\\week3\\Huffman\\huffman_tiny.txt";
	ifstream input(filename, ios::in);

	int n;
	input >> n;

	vector<int> weights;
	while (true) {
		int x;
		input >> x;
		weights.emplace_back(x);
		if (input.eof()) break;
	}


	sort(weights.begin(), weights.end());


	PriorityQueue nodes([](Node* x, Node* y)
	{
		return x->weight < y->weight;
	});

	for (int i = 0; i < n; i++)
	{
		nodes.Insert(&Node(i, weights[i]));
	}

	while (nodes.Size() > 1)
	{
		Node* min1 = nodes.Pop();
		Node* min2 = nodes.Pop();
		Node merge(min1->weight + min2->weight, min1, min2);
		nodes.Insert(&merge);
		cout << min1->id << ": " << min1->weight << ", " << min2->id << ": " << min2->weight << endl;
	}

	Node* root = nodes.Pop();
	cout << root->weight << endl;
	vector<int> codeLengths;

	getCodeLengths(codeLengths, root, 0);

	sort(codeLengths.begin(), codeLengths.end());
	cout << codeLengths.size() << endl;
	cout << "Minimum encoding length: " << codeLengths[0] << endl;
	cout << "Maximum encoding length: " << codeLengths[codeLengths.size() - 1] << endl;

}