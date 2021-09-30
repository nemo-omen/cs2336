<style>
  .row {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    grid-gap: 0.25rem;
  }

  .col {
    display: flex;
    flex-direction: column;
    gap: 0.25rem;
  }
  pre {
    margin: 0;
  }
</style>

<div class="row"><!-- P1 Begin -->
  <div class="col"> <!-- P1, C1 Begin-->

```cpp
// __Recursion__
// DEPTH: REMEMBER - depth does __not__ include
// the initial call to the function 
```

  </div><!-- P1, C1 End-->
  <div class="col"> <!-- P1, C2 Begin-->

```cpp
// __TEMPLATES__
// most c++ compilers require the complete def. of
// a template to appear in the client source-code
// file that uses the temp. -- temps are often def'd
// in headers -- for class temps, member fns are also
// def'd in header
template // keyword
<typeName T> // template parameters
template<typeName T> // fundamental type
template<class T> // or user def'd type
// printArray ex
template<typename T>
void printArray(const T * const array, int count) {
  for (int i = 0; i < count; ++i) {
    cout << array[i] ";
    cout << endl; 
  }
}

//__If <T> is a user defined type, there MUST be an
// overloaded stream insertion operator for that type
// in order to use the stream operator in the fn temp.
```

```cpp
// multiple fn-temp specializations are instantiated
// at compile time, despite the fact that the temps
// are written only once. These copies consume considerable 
// memory - not normally an issue because generated code
// is sams size as code that would have been written
// as separate overloaded fns
```

  </div><!-- P1, C2 End-->
  <div class="col"> <!-- P1, C3 Begin-->

```cpp

```

  </div><!-- P1, C3 End-->
</div><!-- P1 End -->


<div class="row"><!-- P2 Begin -->
  <div class="col"> <!-- P2, C1 Begin-->

```cpp

```

  </div><!-- P2, C1 End-->
  <div class="col"> <!-- P2, C2 Begin-->

```cpp

```

  </div><!-- P2, C2 End-->
  <div class="col"> <!-- P2, C3 Begin-->

```cpp

```

  </div><!-- P2, C3 End-->
</div><!-- P2 End -->