
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