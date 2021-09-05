#include <iostream>
#include <stdexcept>
#include "Time.h"

using namespace std;

int main() {
  Time t;

  cout << "The initial universal time is ";
  t.printUniversal();
  cout << "\nThe initial standard time is ";
  t.printStandard();

  t.setTime(13, 27, 6);

  cout << "\n\nUniversal time after setTime is ";
  t.printUniversal();
  cout << "\n\nStandard time after setTime is ";
  t.printStandard();

  // attempt to set time with invalid values
  try {
    t.setTime(99, 99, 99);
  } catch (invalid_argument &e) {
    cout << "Exception: " << e.what() << endl;
  }

  // output t's values after specifying invalid values
  cout << "\n\nAfter attempting invalid settings:"
    << "\nUniversal time: ";
  t.printUniversal();
  cout << "\nStandard time: ";
  t.printStandard();
  cout << endl;
}