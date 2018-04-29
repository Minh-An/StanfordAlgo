#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>

using namespace std;

int64_t shortestShortestPath(string filename)
{
	ifstream input(filename, ios::in);

	int n;
	input >> n;

	int edges;
	input >> edges;

	vector<vector<int64_t>> A(n);

	int shortest = 0;
	for (int i = 0; i < n; i++)
	{
		A[i].resize(n, numeric_limits<int64_t>::max());
		A[i][i] = 0;
	}

	for (int i = 0; i < edges; i++) {
		int v, w, cost;
		input >> v;
		input >> w;
		input >> cost;
		if (cost < shortest) shortest = cost;
		A[v - 1][w - 1] = cost;
	}


	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (A[i][k] != numeric_limits<int64_t>::max() && A[k][j] != numeric_limits<int64_t>::max())
				{
					if (A[i][k] + A[k][j] < A[i][j])
					{
						A[i][j] = A[i][k] + A[k][j];
						if (shortest > A[i][j]) shortest = A[i][j];
					}
				}
			}
		}
	}
		
	for (int i = 0; i < n; i++)
	{
		if (A[i][i] < 0)
		{
			cout << "There is a negative cycle!" << endl;
			return 1;
		}
	}

	return shortest;
}


int main(int argc, char* argv[])
{
	string fileLocation = "D:\\repos\\StanfordAlgo\\course4\\week1\\APSP\\";
	vector<string> graphFiles = {"g1.txt", "g2.txt", "g3.txt", "gSmall.txt" }; 
	for (string filename : graphFiles)
	{
		int64_t distance = shortestShortestPath(fileLocation + filename);
		if (distance < 1) cout << " The shortest shortest path is length " << distance << endl;
	}
}