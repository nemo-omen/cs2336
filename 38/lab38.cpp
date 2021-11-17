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

  for(int k = 1; k <= numDigits; k++) {
  }

  cout << "buckets: " << '\n' << "[";
  for(int i = 0; i < (int)buckets.size(); i++) {
    cout << buckets[i];
  }
  cout << "]\n";
}