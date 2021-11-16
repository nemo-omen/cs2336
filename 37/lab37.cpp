// Jeff Caldwell
// CS 2336
// Lab 37

#include <lab37.h>
#include<vector>
#include<algorithm>

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

  for(int i = 0; i < gameBoard.rows(); i++) {
    uint unique[gameBoard.rows()];
    for(int j = 0; j < gameBoard.cols(); j++) {
      // if any of the values in a row are
      // smaller than 1 or larger than 4, the row
      // is out of range and the board is not valid
      if(gameBoard[i][j] <=0 || gameBoard[i][j] > (int)gameBoard.rows()) {
        return false;
      }
      
    }
  }
  return true;
  
}

bool isInRange(matrix<uint> board) {
}
