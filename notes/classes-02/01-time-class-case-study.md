# Time class case study

- use `#ifndef`, `#define`, and `#endif` preprocessing directives to form an __include guard__ that prevents headers from being included more than once in a source file.

- __compile the files in `/time` using `./cc`__

### Interface
```cpp
// Time.h

// prevent multipe inclusions of header

// if not defined
#ifndef TIME_H

// define
#define TIME_H

class Time {
  public:
    Time();
    void setTime(int, int, int);  // set hour, minute, second
    void printUniversal() const;  // print in universal-time format
    void printStandard() const;   // print in standard-time format

  private:
    unsigned int hour;            // 0 - 23 (24-hour clock format)
    unsigned int minute;          // 0 - 59
    unsigned int second;          // 0 - 59
};

#endif
```

### Implementation

```cpp
// Time.cpp
#include <iostream>
#include <iomanip>
#include <stdexcept> // for invalid argument exception class
#include "Time.h"

using namespace std;

Time::Time()
  :hour(0), minute(0), second(0) { // initializer list

  }

void Time::setTime(int h, int m, int s) {
  if((h >= 0 && h <= 24) && (m >= 0 && m <= 60) && (s >= 0 && s <= 60)) {
    hour = h;
    minute = m;
    second = s;
  } else {
    throw invalid_argument(
      "hour, minute and/or second out of range"
    );
  }
}

void Time::printUniversal() const {
  cout 
    << setfill('0') 
      << setw( 2 ) 
    << hour << ":"
      << setw( 2 )
    << minute << ":"
      <<setw( 2 )
    << second;
}

void Time::printStandard() const {
  cout
    << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
      << setfill('0') << setw(2)
    << minute << ":"
      << setw(0)
    << second
    << (hour < 12 ? " AM" : " PM");
}
```

### Client Code

```cpp
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
```