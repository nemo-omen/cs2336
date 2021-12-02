// Jeff Caldwell
// CS 2336
// Lab 49

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
void pqSort(vector<T>& v) {
  priority_queue<T, vector<T>, greater<T>> pq;

  for(auto e : v) {
    pq.push(e);
  }

  while(v.size() > 0) {
    v.pop_back();
  }

  while(!pq.empty()) {
    v.push_back(pq.top());
    pq.pop();
  }
}