#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


bool isPalindrome(string s) {
  cout << "before: " << s << '\n';
  
  stack<char, vector<char>> a, b,c;
  
  transform(s.begin(), s.end(), s.begin(),
    [] (unsigned char c) -> unsigned char { return toupper(c); });

  cout << "after: " << s << '\n';

  return true;
}
