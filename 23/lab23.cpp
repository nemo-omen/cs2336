
// iterative solution
template<typename T>
int numDistinct(const T *array, int n) {
  const T *i, *j, *const end = array + n;

  int distinct = 0;
  
  for(i = array; i < end; i++) {
    for(j = i + 1; j < end && *i != *j; j++) {
      // do nothing!
    }
    if(j >= end) {
      distinct++;
    }
  }
  
  return distinct;
}