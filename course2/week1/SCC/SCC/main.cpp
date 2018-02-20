#include "digraph.h"
#include "computeSCC.h"
#include <iostream>

using namespace std;

int main()
{
	Digraph g(875715, "D:\\repos\\StanfordAlgo\\course2\\week1\\SCC\\SCC\\SCC.txt");
	//cout << g; 

	ComputeSCC scc(&g);
	cout << scc;
}