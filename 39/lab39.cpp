// Jeff Caldwell
// CS 2336
// Lab 39

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
  stack<char, vector<char>> a, b, c;
  bool isPalindrome = false;
  
  transform(s.begin(), s.end(), s.begin(),
    [] (unsigned char c) -> unsigned char { return toupper(c); });

  for(int k = 0; k < s.length(); k++) {
    a.push(s.at(k));
    b.push(s.at(k));
  }
  
  while(!b.empty()) {
    c.push(b.top());
    b.pop();
  }

  while(!a.empty() && !c.empty()) {
    isPalindrome = (c.top() == a.top());
    c.pop();
    a.pop();
  }

  return isPalindrome;
}
