// Jeff Caldwell
// CS 2336
// Lab 41

#include <iostream>
#include <stack>

using namespace std;

int precedence(char c);
bool isOperator(char c);

void infix2Postfix(string infix, ostream& out) {
  stack<char> stk;
  basic_string<char>::size_type i;

  for(i = 0; i < infix.size(); i++) {
    char c = infix[i];

    if(isspace(c)) {
      continue;

    } else if(c == '(') {
      stk.push(c);

    } else if(isupper(c)) {
      out << c << " ";

    } else if(isOperator(c)) {
      while(!stk.empty() && stk.top() != '(' && (isOperator(stk.top()) && precedence(stk.top()) >= precedence(c))) {
        out << stk.top() << " ";
        stk.pop();
      }
      
      stk.push(c);
    } else {
      while(!stk.empty() && stk.top() != '('){
        out << stk.top() << " ";
        stk.pop();
      };

      if(stk.empty()) {
        out << '\n' << "Error: Unbalanced expression. Exiting.";
        exit(0);
      }

      stk.pop();
    }
  }

  while(stk.size() > 0) {
    out << stk.top() << " ";
    stk.pop();
  }
}

bool isOperator(char c) {
  if (c == '+' || c == '-' || c == '/' || c == '*') {
    return true;
  }
  return false;
}

int precedence(char c) {
  if(c == '/' || c == '*') return 2;
  return 1;
}