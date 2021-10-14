# Introduction to Time Complexities

- If an algo. works w/varying amts. of data each time, we would normally expect that:
  - when working with a larger amt. of data, the algo. would take longer to complete execution
  - small amt. of data? algo. would complete execution in shorter time

__Programs spend most of their time looping__
- make sure loops are as efficient as possible


## Linear Algorithm
```
[TIME]
20                                *
                              *
15                        *  
                      *
10                *
              *
5         *
      *
0 *
  1   2   3   4   5   6   7   8   9    [ITEMS]
```

## Parabolic Algorithm
(square) -- N<sup>2</sup>
- bubble sort
- selection sort
- only seeing the right half because there can't be a negative amount of data
```
[TIME]
20                                *
                                *
15                            *  
                           *
10                      *
                    *
5              *
         *
0 *
  1   2   3   4   5   6   7   8   9    [ITEMS]
```

## Logarithmic Algorithm
- these are super-fast!
- time to work continues to increase, but does so VERY slowly
- binary search
- Euclid's Algorithm
- the only thing better is a __constant algorithm__
N<sub>0</sub>
```

[TIME]                             *
20                           *
                       *
15                *  
              *
10         *
        *
5     *
    *
0 *
  1   2   3   4   5   6   7   8   9    [ITEMS]
```

## Time Complexities
- the above behaviors represent __time complexity__
- time complexities are used to help make an intelligent decision about which algorithm to use, when two different algorithms accomplish the same task.

## Crossover Point

The graphs of two algos with two different time complexities will have a __cross-over__ point - that is the point at which the amount of data being process is high enough that one algorithm begins outperforming the other.

__We don't care too much about algorithmic behavior before the crossover point (to the left)__

- no elems is low, so most algos will be fast
- to the right - where the num of elems is high, is where people notice the difference in algorithm running time.
- __Asymptotic running time__ - running time of an algo as the num of elems approaches infinity

## Algorithm Behavior Components
- __n__ is used to stand for the number of elements
  - in reality - can be anything that has a pronounced effect on exec. time of an algorithm
  - n is often referred to as the __problem size__
- the amt of time an algo takes to execute is represented by the number of instructions that are executed

## How many instructions?

```
sum = 0; <-- instruction
i = 0; <-- instruction
while(i < 3) { <-- (i < 3) - instruction -|
  sum += A[i]; <-- instruction -----------|-- executed 3 times
  i++ <-- instruction --------------------|
}
```
`3 + 3(3)` = __12 instructions__

```
sum = 0;
i = 0;
while(i < numElements) {
  sum += A[i];
  i++;  
}
```
- because `numElements` is `n`, the number of instructions is `3 + n(3) = 3n + 3`
  - or `f(n) = 3n + 3`

Because `n` in the above examples has an exponent of `1`, this will graph as a line - it's a __linear algorithm__

```
sum = 0;
i = 0;
while(i < n) {
  j = 0;
  while(j < n) {
    sum += i * j;
    j++;
  }
  i++;
}
```

3 + 4n(3n)

- look at the inner loop first
  - `3n + 3`
- add condition of outer loop
  - `3n + 4`
  - but wait! That loop is being done `n` times!
  - `n(3n + 4)`
- now move up to the global scope
  - `n(3n + 4) + 3` or, to be correct <code>3n<sup>2</sup> + 4n + 3</code>