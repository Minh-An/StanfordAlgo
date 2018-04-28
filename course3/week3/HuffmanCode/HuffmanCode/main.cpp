#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>

#include "Node.h"

using namespace std;

void getCodeLengths(vector<int>& lengths, Node* x, int length)
{
	if (!x->isLeaf()) {
		getCodeLengths(lengths, x->left, length+1);
		getCodeLengths(lengths, x->right, length + 1);
	}
	else {
		lengths.emplace_back(length);
	}
}

void getCodes(vector<string>& codes, Node* x, string code)
{
	if (!x->isLeaf()) {
		getCodes(codes, x->left, code + '0');
		getCodes(codes, x->right, code +'1');
	}
	else {
		codes.emplace_back(code);
	}
}

Node* getMin(list<Node*>& leaves, list<Node*>& parents)
{

	if (leaves.empty())
	{
		Node* min = parents.front();
		parents.pop_front();
		return min;
	}
	else if (parents.empty())
	{
		Node* min = leaves.front();
		leaves.pop_front();
		return min;
	}
	else
	{
		Node* parent = parents.front();
		Node* leaf = leaves.front();
		if (leaf->weight < parent->weight)
		{
			leaves.pop_front();
			return leaf;
		}
		else
		{
			parents.pop_front();
			return parent;
		}
	}
}

int main()
{
	string filename = "D:\\repos\\StanfordAlgo\\course3\\week3\\HuffmanCode\\huffman.txt";
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

	list<Node*> leafNodes;
	for (int i = 0 ; i < n; i++)
	{
		leafNodes.emplace_back(new Node(i, weights[i]));
	}

	list<Node*> parentNodes;
	while (!(leafNodes.empty()) || parentNodes.size() > 1)
	{
		Node* min1 = getMin(leafNodes, parentNodes);
		Node* min2 = getMin(leafNodes, parentNodes);
		Node* merge = new Node(min1->weight+min2->weight, min1, min2);
		parentNodes.emplace_back(merge);
		//cout << min1->id << ": " << min1->weight << ", " << min2->id << ": " << min2->weight << endl;
		//cout << merge->id << ": " << merge->weight << endl;
	}

	Node* root = parentNodes.front();

	
	vector<int> codeLengths;

	getCodeLengths(codeLengths, root, 0);

	sort(codeLengths.begin(), codeLengths.end());
	cout << codeLengths.size() << endl;
	cout << "Minimum encoding length: " << codeLengths[0] << endl;
	cout << "Maximum encoding length: " << codeLengths[codeLengths.size()-1] << endl;

	vector<string> codes;
	getCodes(codes, root, "");
	sort(codes.begin(), codes.end(), [](string& x, string& y)
	{
		return x.length() < y.length();
	});

	for (string code : codes) cout << code << endl;

}