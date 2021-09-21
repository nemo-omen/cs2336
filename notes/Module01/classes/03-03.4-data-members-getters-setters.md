# Data members, set member functions and get member functions

- variables defined in a function definition's body are known as __local variables__ and can only be used from the line of their definition until the closing right brace of the block in which they're declared
  - a local variable must be declared before it can be used in a function (no hoisting!)
  - local variables cannot be accessed outside the function in which it's declared (encapsulation)
  - When a function terminates, the values of its local variables are lost (unless you define that variable as `static`)
- An object has attributes that are carried with it as it's used in a program
  - Those attributes exist throughout the life of the object
  - a class normally consists of one or more member functions that manipulate the attributes that belong to a particular object of a class.
- Attributes are represented as variables in a class definition (__data members__)
  - declared inside a class definition but outside the bodies of the class's member-function definitions.
- Each object of a class maintains its own attributes in memory (memory not alloc. until instantiation).


__The "usual mode" is to put data in the `private` section and member functions in the `public` section, though there are exceptions.__
- this facilitates debugging because problems with data manipulations are localized to either the class's member functions or "the friends of the class"
- you'll get a `compilation error` if a function which is not a member of the class (or a friend of the class) attempts to access a `private` member of that class.
- always try to _localize_ the effects of changes to a class's data members by accessing and manipulating the members through their corresponding `get` and `set` functions.

We put data in `private` is because we want to minimize the places in which that data can be modified.

It's good practice to use getters and setters to modify the data within a class.

- it's also a good idea to define getters as `const` because they won't ever be modifying the member data.

Other terms for getters and setters:

- `getters` -> `get functions` -> `accessors`
- `setters` -> `set functions` -> `mutators`
  
```cpp
#include <iostream>
#include <string>
using namespace std;

class GradeBook {
  public:
    //setter
    void setCourseName(string name) {
      courseName = name;
    }

    // getter
    string getCourseName() const {
      return courseName;
    }

    void displayMessage() const {
      cout << "Welcome to the gradebook for\n" << getCourseName() << "!" << endl;
    }

  private:
    string courseName;
}

int main() {
  string nameOfCourse;
  GradeBook myGradeBook;

  cout << "Initial course name is: " << myGradeBook.getCourseName() << endl;

}
```