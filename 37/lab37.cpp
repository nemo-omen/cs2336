// Jeff Caldwell
// CS 2336
// Lab 37

#include <lab37.h>

// Overloaded output operator - displays puzzle row-by-row to output
// stream out.  The elements in a row should be separated by one
// blank space.
ostream& operator<<(ostream& out, const Sudoku& puzzle) {
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
    in >> num;
    for(j = 0; j < puzzle.gameBoard.cols(); ++j) {

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
  return true;
}
