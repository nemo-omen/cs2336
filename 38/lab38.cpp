// Jeff Caldwell
// CS 2336
// Lab 38

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<uint> merge(vector<uint> &a, vector<uint> &b);

ostream& operator<<(ostream& os, const vector<uint>& v);

void bucketSort(vector<uint>& v, uint numDigits) {
  vector<vector<uint>> buckets (10);
  int multiplier = 10;
  int digitCount = numDigits;
  cout << "before: " << v;

  for(int i = 0; i < (int)v.size(); i++) {
    int current = v[i];
    int targetDigit;

    targetDigit = current % 10;
    buckets[targetDigit].push_back(v[i]);
    --numDigits;
  }

  for(int i = 0; i < (int)buckets.size(); i++) {
    cout << "bucket: " << buckets[i];
  }

  for(int i = 0; i < buckets.size(); i++) {
    if(buckets[i].size() > 0) {
      
    }
  }

  cout << "buckets after: " << buckets;
}

vector<uint> merge(vector<uint> &a, vector<uint> &b) {
  // int size = a.size() > b.size() ? a.size() : b.size();
  vector<uint> result(a.size() + b.size());
  vector<unsigned int>::size_type i = 0, j = 0, k = 0;

  while(i < a.size() && j < b.size()) {
    if(a[i] < b[i]) {
      result[k] = a[i];
      ++k;
      ++i;
    } else {
      result[k] = b[j];
      ++k;
      ++j;
    }
  }

  while(i < a.size()) {
    result[k] = a[i];
    ++k;
    ++i;
  }

  while(j < b.size()) {
    result[k] = b[j];
    ++k;
    ++j;
  }

  return result;
}