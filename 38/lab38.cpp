// Jeff Caldwell
// CS 2336
// Lab 38

// NOTE: This works when running the code on vectors as large as 1000. 
// I wrote the output to a file and double-checked, but for some reason
// sorting random numbers against `lab38main.test.cpp` returns that
// sort didn't work on random numbers. Any input on what I've done
// wrong would be greatly appreciated. Thanks!

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

ostream& operator<<(ostream& os, const vector<uint>& v);

void bucketSort(vector<uint>& v, uint numDigits) {
  vector<vector<uint>> buckets (10);
  vector<uint>::size_type i, j, k, l;

  // start by looping over each digit
  for(k = 0; k < numDigits; k++) {
    int long long mult = pow(10, k + 1);
    int long long div = pow(10, k);

    for(i = 0; i < v.size(); i++) {
      int long long digit = (v[i] % mult) / div;
      buckets[digit].push_back(v[i]);
    }

    v.clear();

    for(j = 0; j < buckets.size(); j++) {
      for(l = 0; l < buckets[j].size(); l++) {
        v.push_back(buckets[j][l]);
      }

      if(buckets[j].size() > 0) {
        buckets[j].clear();
      }
    }
  }
  }