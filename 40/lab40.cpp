// Jeff Caldwell
// CS 2336
// Lab 40

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isNestedCorrectly(string str) {
  stack<char> opening;
  char current;
  char compare;
  basic_string<char>::size_type i;
  
  for(i = 0; i < str.length(); i++) {
    current = str[i];

    if(current == '[' || current == '{' || current == '(') {
      opening.push(current);
    }

    if(current == ']' || current == '}' || current == ')') {
      if(opening.empty()) 
        return false;

      compare = opening.top();
      opening.pop();

      if(current == ')') {
        if(compare == '{' || compare == '[') 
          return false;
      }

      if(current == '}') {
        if(compare == '(' || compare == '[') 
          return false;
      }

      if(current == ']') {
        if(compare == '{' || compare == '(') 
          return false;
      }
    }
  }
  return opening.empty();
}