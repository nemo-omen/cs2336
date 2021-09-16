# Defining a member function with a parameter

Member functions, like all other functions, can require parameters.

```cpp
#include <iostream>
#include <string>
using namespace std;


class Gradebook {
  public:
    void displayMessage(string courseName) const {
      cout << "Welcome to the grade book for\n << courseName << "!" << endl;
    }
}
```

```cpp
int main() {
  string nameOfCourse;
  GradeBook myGradeBook;

  cout << "Please enter the course name:" << endl;
  getline(cin, nameOfCourse);
  cout << endl;

  myGradeBook.displayMessage(nameOfCourse);
}
```

