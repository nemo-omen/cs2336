#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


bool isPalindrome(string s) {
  stack<char, vector<char>> a, b,c;
  stack<char, vector<char>>::size_type i, j;
  // basic_string<char>::size_type k;
  
  // cout << "before: " << s << '\n';
  
  transform(s.begin(), s.end(), s.begin(),
    [] (unsigned char c) -> unsigned char { return toupper(c); });

  cout << "\nafter: " << s << '\n';

  cout << "\n s: ";

  for(int k = 0; k < s.length(); k++) {
    cout << s.at(k) << " ";
    a.push(s.at(k));
    b.push(s.at(k));
  }

  cout << '\n' << "b: ";
  
  for(i = 0; i < b.size(); i++) {
    cout << b.top() << " ";
    c.push(b.top());
    b.pop();
  }
  
  cout << '\n';

  // for(j = 0; j < a.size(); j++) {
  //   if(c.top() != a.top()) {
  //     return false;
  //   }

  //   cout << "a: " << c.top() << " ";
  //   cout << "c: " << a.top() << " ";

  //   c.pop();
  //   a.pop();
  // }

  cout << '\n';

  return true;
}
