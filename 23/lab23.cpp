
// iterative solution
template<typename T>
int numDistinct(const T *array, int n) {
  const T *j;
  const T *const end = array + n;

  if(n <= 1) return 1;
  
  for(j = array + 1; j < end && *j != *array; j++) {
  }

  if(array >= end) {
    // return numDistinct(array + 1, n - 1) + 1;
    return 1;
  }
  return numDistinct(array + 1, n - 1);
}