// Jeff Caldwell
// CS 2336
// Lab 35

#include <d_matrix.h>

bool isIdentityMatrix(const matrix<int>& mat) {
  for(int i = 0; i < mat.rows(); i++) {
    for (int j = 0; j < mat.rows(); j++) {
      if(i == j) {
        // if any of these values is not the same as the
        // first value it's not an identity matrix
        if(mat[i][j] != mat[0][0]) {
          return false;
        }
      } else {
        // if any of these values is not 0
        // it's not an identity matrix
        if(mat[i][j] != 0) {
          return false;
        }
      }
    }
  }
  // if you made it this far, you must have an identity matrix!
  return true;
}