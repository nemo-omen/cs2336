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
  vector<uint> out;
  int multiplier = 10;
  // int digitCount = numDigits;
  cout << "before: " << v;
  vector<uint>::size_type i, j;

  for(i = 0; i < v.size(); i++) {
    int current = v[i];
    int targetDigit;

    targetDigit = current % multiplier;
    buckets[targetDigit].push_back(v[i]);
    --numDigits;
  }

  for(i = 0; i < buckets.size(); i++) {
    cout << "bucket: " << buckets[i];
  }

  for(i = 0; i < buckets.size(); i++) {
    if(buckets[i].size() > 0) {
      for(j = 0; j < buckets[i].size(); j++) {
        out.push_back(buckets[i][j]);
      }
    }
  }

  cout << "out: " << out;
}