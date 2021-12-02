// Jeff Caldwell
// CS 2336
// Lab 44

#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool isPalindrome(string str) {
  deque<char> dq;

  for(auto c : str) {
    dq.push_back(c);
  }

  while(!dq.empty()) {

    unsigned char dF = (unsigned char)toupper(dq.front());
    unsigned char dB = (unsigned char)toupper(dq.back());

    // front and back will be the same element if size() == 1
    if(dF != dB) return false;

    // pop_back only if enough elements are present
    if(dq.size() > 1) 
      dq.pop_back();
    
    // always pop_front
    dq.pop_front();
  }

  return true;
}