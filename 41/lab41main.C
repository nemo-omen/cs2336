#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void infix2Postfix(string infix, ostream& out);

int main()
{
  string infix;

  while (getline(cin, infix))
  {
    cout << "Infix:   " << infix << endl;
    cout << "Postfix: ";
    infix2Postfix(infix, cout);
    cout << endl;
  }

  return EXIT_SUCCESS;
}
