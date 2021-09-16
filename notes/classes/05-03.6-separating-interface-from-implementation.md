# Separating interface from implementation

- __Interfaces__ define and standardize the ways in which things such as people and systems interact with each other.
- the interface of a class describes what services a class's clients can use and how to request those services, but not how those services are carried out
- a class's _public_interface consists of the class's _public_ member functions (also known as the class's _public services_)
- previous examples - each class definition contained the complete definitions of the class's _public_ member functions and the declarations of its _private_ data members.
- it's __better software engineering__ to define member functions outside the class definition, so their implementation details can be hidden from the __client code__
  - ensures you don't write client code that depends on the class's implementation details
- the following program separates `GradeBook`'s __interface__ from its __implementation__ by splitting the class definition into two files — the header file `GradeBook.h`, in which the class `GradeBook` is defined, and the __source-code__ file, `GradeBook.cpp` in which the member functions are defined.

__NOTE:__ So, this essentially means that the class definition in the header file acts in the same way as a Java _interface_, while we essentially use the _constructors_ to define the implementation in a separate file.

### Interface (or specification)
Only the __prototypes__ of the __member functions__ are included in the _interface/specification_
```cpp
// GradeBook.h

#include<string>

class GradeBook {
  public:
    explicit GradeBook( std::string ); // constructor
    void setCourseName( std::string );
    std::string getCourseName() const;
    void displayMessage() const;

  private:
    std::string courseName;
}

```

### Implementation
It's necessary to use the __binary scope resolution operator__ `::`
- this works like `ClassName::MemberFunctionName(){}`
```cpp
// GradeBook.cpp
#include <iostream>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(string name)
  :courseName( name ) { // member initializer (delegator)
    // empty body
  }

void GradeBook::setCourseName( string name ) {
  courseName = name;
}

```

## Client Code
Client code doesn't need to know how the member functions are implemented. 
```cpp
// main.cpp
#include <iostream>
#include "GradeBook.h

// see how we don't have to include GradeBook.cpp?

using namespace std;

int main () {
  GradeBook gb1("CS101 Introduction to C++ Programming");
  GradeBook gb2("CS102 Data Structures in C++");

  cout
    << "Gradebook created for course: "
      << gb1.getCourseName()
    << "\nGradebook creaded for course: "
      << gb2.getCourseName()
    << endl;
}
```