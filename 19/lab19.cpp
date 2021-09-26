// Jeff Caldwell
// CS 2336
// Lab 19

#include <string>

using namespace std;

bool isPalindrome(string s) {
  if(s.length() <= 1) {
    return true;
  } else {
    if(tolower(s.front()) != tolower(s.back())) {
      return false;
    } else {
      return (isPalindrome(s.substr(1, s.length() - 2)));
    }
  }
}