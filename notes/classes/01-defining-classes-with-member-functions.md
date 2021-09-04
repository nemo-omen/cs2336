# Defining classes with member functions
## Gaddis - Chapter 13

- Define a class `GradeBook` with a member function `displayMessage`
- create a `GradeBook` object, and call its `displayMessage` function

__Define a class__ by using the keyword `class` and by giving the class a _name_

The following function has these features:
- __Access specifier__ -> the `public` keyword, followed by a colon `:`, the other _access specifier_ we should be familiar with is the `private` specifier.
  - if something is included in the `public` section, it will be available outside of the class. They are part of the __public interface__
  - anything within the __private__ section will be available within the class, but not outside of the class.
- __member function__ `displayMessage`
  - when a member ffunction is designated as `const`, it means that member function will have the inability to modify member data

```cpp
class GradeBook {
  public: // access specifier
    void displayMessage() const { // member function
      cout << "Welcome to the Grade Book! << endl;
    }
}
```

The `main` function, in this case, is where we are creating an __instance__ of the `GradeBook` class — `myGradeBook`.

To call `public` member functions, use __dot notation__ — i.e. `myGradeBook.displayMessage()`

__Just having a _class specification_ does not allocate any space in memory.__ It's not until you _instantiate_ that class that memory is allocated.
```cpp
int main() {
  GradeBook myGradeBook;

  myGradeBook.displayMessage();
}
```