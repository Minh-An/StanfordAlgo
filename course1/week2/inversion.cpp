#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

size_t CountSplitInversions(vector<int>& A, vector<int>& aux, int lo, int mid, int hi)
{
  size_t inversions = 0;
  int i = lo;
  int j = mid+1;
  
  for(int k = lo; k <= hi; k++)
  {
    aux[k] = A[k];
  }

  for(int k = lo; k <= hi; k++ )
  {
    if(i > mid)
    {
      A[k] == aux[j++];
    }	
    else if(j > hi)
    {
      A[k] = aux[i++];
    }
    else if (aux[j] < aux[i])
    {
      A[k] = aux[j++];
      inversions += mid+1 - i;
    }
    else
    {
      A[k] = aux[i++];
    }	
  }
  return inversions;
}


size_t SortAndCount(vector<int>& A, vector<int>& aux, int lo, int hi)
{
  if(lo == hi) { return 0; }
  int mid = (hi - lo) /2 + lo;
  size_t x = SortAndCount(A, aux, lo, mid);
  size_t y = SortAndCount(A, aux, mid+1, hi);
  size_t z = CountSplitInversions(A, aux, lo, mid, hi);
  return x + y + z;
}



int main() {
  ifstream inputFile("IntegerArray.txt", ios::in);

  vector<int> integers;

  istream_iterator<int> begin(inputFile);
  istream_iterator<int> eof;

  copy(begin, eof, back_inserter(integers));
  
  vector<int> aux(integers.size());
  size_t inversions = SortAndCount(integers, aux, 0, integers.size()-1);

  cout << inversions << endl;
}
