// Jeff Caldwell
// CS 2336
// Lab 37

#include <lab37.h>
#include<vector>
#include<algorithm>

// we can (hopefully) reuse this function from 
// Lab 25 to make sure all integers
// in a given array are unique
template<typename T>
int numDistinct(const T *array, int n);


// Overloaded output operator - displays puzzle row-by-row to output
// stream out.  The elements in a row should be separated by one
// blank space.
ostream& operator<<(ostream& out, const Sudoku& puzzle) {
  for(int i = 0; i < puzzle.gameBoard.rows(); ++i) {
    for(int j = 0; j < puzzle.gameBoard.cols(); ++j) {
      out << puzzle.gameBoard[i][j] << ' ';
    }
    out << '\n';
  }
  return out;
}


// Overloaded input operator - initializes puzzle from input stream
// in.  The function should read four four-digit unsigned
// integers. The first unsigned integer is used to initialize the
// elements of the first row of the puzzle, the second the second,
// etc. The least significant digit of the four-digit number is used
// to initialize the last element in the row, the next-to-least the
// next-to-last, etc.
istream& operator>>(istream& in, Sudoku& puzzle) {
  int i, j, num;

  for(i = 0; i < puzzle.gameBoard.rows(); ++i) {
    in >> num; // read 4-digit int for each row
    for(j = puzzle.gameBoard.cols() - 1; j >= 0 ; --j) {
      int rightmostDigit = num % 10;
      puzzle.gameBoard[i][j] = rightmostDigit;
      num = num / 10;
    }
  }

  return in;
}


// default constructor - resizes puzzle to have four rows and four
// columns
Sudoku::Sudoku() {
  gameBoard.resize(4,4);
}


// Returns true if puzzle represents a valid sudoku game board as
// described in the lab handout
bool Sudoku::isValid() const {

  uint currentRow[gameBoard.rows()];
  uint currentColumn[gameBoard.rows()];
  uint currentQuadrant[gameBoard.rows()];

  // Rows and Columns
  for(int i = 0; i < gameBoard.rows(); i++) {

    // Trap 1:
    // if any of the values in a row are
    // smaller than 1 or larger than the size of a row,
    // the value is out of range and the board is not valid
    for(int j = 0; j < gameBoard.cols(); j++) {
      if(gameBoard[i][j] <= (uint)0 || gameBoard[i][j] > (uint)gameBoard.rows()) {
        return false;
      }
    }

    // save each integer in the row
    // and save each in the column
    for(int j = 0; j < gameBoard.rows(); j++) {
      currentRow[j] = gameBoard[i][j];
      currentColumn[j] = gameBoard[j][i];
    }

    // Trap 2:
    // check that all integers in the row are distinct
    if(numDistinct(currentRow, gameBoard.rows()) < gameBoard.rows()) {
      return false;
    }

    // Trap 3:
    // check all ints in column are distinct
    if(numDistinct(currentColumn, gameBoard.cols()) < gameBoard.cols()) {
      return false;
    }
  }

  // Quadrants

  // temporary vector to push_back
  // quadrant values
  vector<int> tempQuad;
  
  for(int i = 0; i < gameBoard.rows() / 2; i++) {
    for(int j = 0; j < gameBoard.cols() / 2; j++) {
      tempQuad.push_back(gameBoard[i][j]);
    }
  }

  // copy the vector's elements into the currentQuadrant array
  copy(tempQuad.begin(), tempQuad.end(), currentQuadrant);

  // Trap 4:
  // check all values in quadrant are distinct
  if(numDistinct(currentQuadrant, gameBoard.rows()) < gameBoard.rows()) {
    return false;
  }

  return true;
  
}

template<typename T>
int numDistinct(const T *array, int n) {
  const T *j;
  const T *const end = array + n;

  if(n <= 1) return 1;
  
  for(j = array + 1; j < end && *j != *array; j++) {
  }

  if(j >= end) {
    return numDistinct(array + 1, n - 1) + 1;
  }
  return numDistinct(array + 1, n - 1);
}