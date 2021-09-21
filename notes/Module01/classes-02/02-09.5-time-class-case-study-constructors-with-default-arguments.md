# Time class case study: Constructors with default arguments

### Interface
Any change to the _default argument values_ of a function requires the __client code__ to be recompiled (to ensure that the function runs correctl).


```cpp
// Time.h

// prevent multipe inclusions of header

// if not defined
#ifndef TIME_H

// define
#define TIME_H

class Time {
  public:
    explicit Time(int = 0, int = 0, int = 0); // considered a default constructor
                                              // because all args ave default values

    // setters
    void setTime(int, int, int);    // set hour, minute, second
    void setHour(int);              // set hour (after validation)
    void setMinute(int);            // set minute (after validation)
    void setSecond(int);            // set second (after validation)
    
    // getters
    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;

    // methods/member functions
    void printUniversal() const;    // print in universal-time format
    void printStandard() const;     // print in standard-time format

  private:
    unsigned int hour;              // 0 - 23 (24-hour clock format)
    unsigned int minute;            // 0 - 59
    unsigned int second;            // 0 - 59
};

#endif
```

### Implementation

```cpp
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h"

using namespace std;

Time::Time(int hour, int minute, int second) {
  setTime(hour, minute, second);
}

void Time::setTime(int h, int m, int s) {
  setHour(h);
  setMinute(m);
  setSecond(s);
}

void Time::setHour(int h) {
  if(h >= 0 && h <= 24) {
    hour = h;
  } else {
    throw invalid_argument("Hour must be between 0 - 23");
  }
}

void Time::setMinute(int m) {
  if(m >= 0 && m <= 60) {
    minute = m;
  } else {
    throw invalid_argument("Minute must be between 0 - 60");
  }
}

void Time::setSecond (int s) {
  if(s >= 0 && s <= 60) {
    second = s;
  } else {
    throw invalid_argument("Second must be between 0 - 60");
  }
}

unsigned int Time::getHour() const {
  return hour;
}

unsigned int Time::getMinute() const {
  return minute;
}

unsigned int Time::getSecond() const {
  return second;
}

void Time::printUniversal() const {
  cout 
    << setfill('0') 
      << setw( 2 ) 
    << getHour() << ":"
      << setw( 2 )
    << getMinute() << ":"
      <<setw( 2 )
    << getSecond();
}

void Time::printStandard() const {
  cout
    << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
      << setfill('0') << setw(2)
    << getMinute() << ":"
      << setw(2)
    << getSecond()
    << (getHour() < 12 ? " AM" : " PM");
}
```

### Client Code

```cpp
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
```


### Output

```bash
Constructed with:

t1: all arguments defaulted
        00:00:00
        12:00:00 AM


t2: hour specified; minute and second defaulted
        02:00:00
        2:00:00 AM


t3: hour and minute specified; second defaulted
        21:34:00
        9:34:00 PM


t3: hour, minute, and second specified
        12:35:42
        12:35:42 PM


Exception while initializing t5: Hour must be between 0 - 23
```