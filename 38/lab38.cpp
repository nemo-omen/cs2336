// Jeff Caldwell
// CS 2336
// Lab 38

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

ostream& operator<<(ostream& os, const vector<uint>& v);

void bucketSort(vector<uint>& v, uint numDigits) {
  vector<vector<uint>> buckets (10);
  int multiplier = 1;

  for(int i = 0; i < (int)v.size(); i++) {
    int current = v[i];
    int targetDigit;
    while(current != 0) {
      targetDigit = current % 10;
      buckets[targetDigit].push_back(v[i]);
    }
  }
  for(int i = 0; i < (int)buckets.size(); i++) {
    cout << buckets[i];
  }
  // cout << v;
}