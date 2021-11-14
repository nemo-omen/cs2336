// Jeff Caldwell
// CS 2336
// Lab 36

#include <lab36.h>
#include <iomanip>
#include<string>

ostream& operator<<(ostream& out, const Spiral& spiral) {
  int n = spiral.data.rows();
  int width = to_string(n * n).length();

  for(int i = 0; i < spiral.data.rows(); i++) {
    for(int j = 0; j < spiral.data.cols(); j++) {
      out << setw(width + 1) << spiral.data[i][j];
    }
    out << '\n';
  }
  return out;
}

void Spiral::initialize(int n) {
  data.resize(n, n);
}

void Spiral::build() {
  int n = data.rows(), r, c, k;

  r = c = - 1;
  k = 1; // the number that is being inserted

  while(k <= n * n) {
    // go east
    ++r;
    ++c;
    while(c < n && data[r][c] == 0) {
      data[r][c] = k;
      ++k;
      ++c;
    }

    // go south
    --c;
    ++r;
    while(r < n && data[r][c] == 0) {
      data[r][c] = k;
      ++k;
      ++r;
    }

    // go west
    --r;
    --c;
    while(c > -1 && data[r][c] == 0) {
      data[r][c] = k;
      ++k;
      --c;
    }

    // go north
    ++c;
    --r;
    while(r > 0 && data[r][c] == 0) {
      data[r][c] = k;
      ++k;
      --r;
    }
  }
}


/* ALTERNATE IMPLEMENTATION */
/*
void Spiral::build() {
  int val = 1;

  // east/south
  int east = 0, south = 0;

  // west/north
  int west = data.rows();
  int north = data.cols();
  
  while(east < west && south < north) {
    // go east
    for(int i = south; i < north; ++i) {
      data[east][i] = val++;
    }
    east++;

    // go south
    for(int i = east; i < west; ++i) {
      data[i][north - 1] = val++;
    }
    north--;
    
    // go west
    if(east < west) {
      for(int i = north - 1; i >= south; --i) {
        data[west - 1][i] = val++;
      }
      west--;
    }

    // go north
    if(south < north) {
      for(int i = west - 1; i >= east; --i) {
        data[i][south] = val++;
      }
      south++;
    }
  }
}

*/