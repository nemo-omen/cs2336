// Jeff Caldwell
// CS 2336
// Lab 42

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool isPalindrome(string str) {
  stack<char> stk;
  queue<char> q;

  for(auto c : str) {
    stk.push(c);
    q.push(c);
  }

  while(!stk.empty() && !q.empty()) {
    unsigned char sTop = (unsigned char)toupper(stk.top());
    unsigned char qFront = (unsigned char)toupper(q.front());
    if(sTop != qFront) return false;
    stk.pop();
    q.pop();
  }

  return true;
}