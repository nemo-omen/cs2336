#include <iostream>
#include <stdexcept>
#include "Time.h"

using namespace std;

int main() {
  
  Time t1;              // all arguments defaulted
  Time t2(2);           // hour specified
  Time t3(21, 34);      // hour and minute specified
  Time t4(12, 35, 42);  // hour, minute, and second specified


  cout << "Constructed with:\n\nt1: all arguments defaulted\n";
  cout << "\t";
  t1.printUniversal();
  cout << "\n\t";
  t1.printStandard();
  cout << endl;

  cout << "\n\nt2: hour specified; minute and second defaulted\n";
  cout << "\t";
  t2.printUniversal();
  cout << "\n\t";
  t2.printStandard();
  cout << endl;

  cout << "\n\nt3: hour and minute specified; second defaulted\n";
  cout << "\t";
  t3.printUniversal();
  cout << "\n\t";
  t3.printStandard();
  cout << endl;

  cout << "\n\nt3: hour, minute, and second specified\n";
  cout << "\t";
  t4.printUniversal();
  cout << "\n\t";
  t4.printStandard();
  cout << endl;

  // attempt to initialize t5 with invalid values
  try {
    Time t5(27, 74, 99);
  } catch (invalid_argument &e) {
    cerr << "\n\nException while initializing t5: " << e.what() << endl;
  }
}