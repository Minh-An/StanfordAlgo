#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <limits>

using namespace std;

void merge(map<int, vector<int> >& g, int x, int y)
{
  g[x].insert(g[x].end(), g[y].begin(), g[y].end());
  g[x].erase(std::remove(g[x].begin(), g[x].end(), x), g[x].end());
  g[x].erase(std::remove(g[x].begin(), g[x].end(), y), g[x].end());

  vector<int> checked;
  
  for(int i = 0; i < g[x].size(); i++)
  {
    int index = g[x][i];
    if(find(checked.begin(), checked.end(), index) == checked.end())
    {
      for(int j = 0; j < g[index].size(); j++)
      {
	if(g[index][j] == y)
	{
	  g[index][j] = x;
	}
      }
      checked.emplace_back(index);
    }
  }

  g.erase(g.find(y));
  
}

pair<int,int> getRandomEdge(map<int, vector<int> >& g)
{
  vector<pair<int,int> > edges;
  for(auto p = g.begin(); p != g.end(); ++p)
  {
    for(int y: p->second)
    {
      pair<int,int> pair(p->first,y);
      edges.emplace_back(pair);
    }
  }
  return edges[rand()%edges.size()];
}

int karger(map<int, vector<int> > g)
{
  while(g.size() > 2)
  {
    pair<int, int> edge = getRandomEdge(g);
    merge(g, edge.first, edge.second);
  }

  return g.begin()->second.size();
  
}

int mincut(map<int, vector<int> >& g)
{
  int trials = 100;
  int minMinCut = numeric_limits<int>::max();  
  for(int i = 0; i< trials; i++)
  {
    int trialCut = karger(g);
    if(trialCut < minMinCut)
    {
      minMinCut = trialCut;
    }
    cout << "trial " << i << " done" << endl;
  }
  return minMinCut;
}


int main()
{
  srand(time(0));
  ifstream input("kargerMinCut.txt", ios::in);
  map<int, vector<int> > graph;

  for(string line; getline(input, line);)
  {
    int prev = 0;
    int next = line.find("\t");
    string s = line.substr(prev, next);
    int n = stoi(s);
    vector<int> adj;
    
    while(true)
    {
      prev = next+1;
      next = line.find("\t", prev);
      if(next != string::npos)
      {
	s = line.substr(prev, next);
	adj.emplace_back(stoi(s));
      }
      else
      {
	break;
      }
    }
    graph.emplace(n, adj);
  }

  map<int, vector<int> > g;
  vector<int> v1 = {2,4};
  vector<int> v2 = {1,3,4};
  vector<int> v3 = {2,4};
  vector<int> v4 = {1,2, 3};
  g.emplace(1, v1);
  g.emplace(2, v2);
  g.emplace(3, v3);
  g.emplace(4, v4);

  cout << mincut(graph) << endl;
  // merge(g, 2, 1);

  //for(auto p = g.begin(); p != g.end(); ++p)
  //{
  //  cout << p->first << ": ";
  //  for(auto i: p->second)
  //  {
  //    cout << i << " ";
  //  }
  //  cout << endl;
  //}

  
  
}
