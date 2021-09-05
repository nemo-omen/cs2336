
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