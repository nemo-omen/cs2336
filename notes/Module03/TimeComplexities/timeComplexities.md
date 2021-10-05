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

### Example
