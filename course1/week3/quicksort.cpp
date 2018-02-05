#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

enum class Pivot : short
{
  FIRST, LAST, MEDIAN
};

int Median(vector<int>& a, int lo, int hi)
{
  int mid = (hi + lo)/2;
  if ((a[hi] < a[lo] && a[lo] < a[mid]) || (a[hi] > a[lo] && a[lo] > a[mid]))
  {
     return lo;
  }

  if ((a[lo] < a[hi] && a[hi] < a[mid]) || (a[lo] > a[hi] && a[hi] > a[mid]))
  {
    return hi;
  }
  return mid;
}

int Partition(vector<int>& a, int lo, int hi, Pivot pivot)
{
  int pivotIndex;
  if(pivot == Pivot::FIRST) pivotIndex = lo;
  if(pivot == Pivot::LAST) pivotIndex = hi;
  if(pivot == Pivot::MEDIAN) pivotIndex = Median(a, lo, hi);

  swap(a[lo], a[pivotIndex]);
  int i = lo+1;
  for(int j = lo+1; j <= hi; j++)
  {
    //cout << a[j] << " ";
    if(a[j] < a[lo])
    {
      swap(a[j], a[i]);
      i++;
    }
  }
  //cout << endl;
  swap(a[lo], a[i-1]);
  return i-1;
}

uint64_t QuickSort(vector<int>& a, int lo, int hi, Pivot pivot)
{
  if(lo >= hi) { return 0;}
  int pivotIndex = Partition(a, lo, hi, pivot);
  int comparisons = hi -lo;
  uint64_t left = QuickSort(a, lo, pivotIndex-1, pivot);
  uint64_t right = QuickSort(a, pivotIndex+1, hi, pivot);
  //cout << comparisons << " " << left << " " << right << endl; 
  return comparisons + left + right;
  
}

int main()
{
  ifstream input("QuickSort.txt", ios::in);
  vector<int> integers1;
  istream_iterator<int> begin(input);
  istream_iterator<int> end;

  copy(begin, end, back_inserter(integers1));
  vector<int> integers2 = integers1;
  vector<int> integers3 = integers2;
  uint64_t comparisons1 = QuickSort(integers1, 0, integers1.size()-1, Pivot::FIRST);
  uint64_t comparisons2 = QuickSort(integers2, 0, integers2.size()-1, Pivot::LAST);
  uint64_t comparisons3 = QuickSort(integers3, 0, integers3.size()-1, Pivot::MEDIAN);

  cout << "First Index Pivot: " << comparisons1 << endl;
  cout << "Last Index Pivot: " <<  comparisons2 << endl;
  cout << "Median Index Pivot: " << comparisons3 << endl;

}
