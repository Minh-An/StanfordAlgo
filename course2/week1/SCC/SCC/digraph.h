#pragma once

#include <vector>
#include <string>

using namespace std;

class Digraph
<<<<<<< HEAD
{ 
=======
{
>>>>>>> 481e21cc61057690c4784f8b63fce8adc0729868
public:
	Digraph(int n);
	Digraph(int n, string filename);
	void AddEdge(int v, int w);
	int V();
	vector<int> Adjacent(int v);
	Digraph Reverse();

	friend ostream& operator<<(ostream& out, Digraph& g);

private:
	int n;
	vector<vector<int>> adj;
};

