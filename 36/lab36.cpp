// Jeff Caldwell
// CS 2336
// Lab 36
#include <lab36.h>
#include <iomanip>

// 4 loops

ostream& operator<<(ostream& out, const Spiral& spiral) {
  for(int i = 0; i < spiral.data.rows(); i++) {
    for(int j = 0; j < spiral.data.cols(); j++) {
      out << setw(2) << spiral.data[i][j] << " ";
    }
    out << '\n';
  }
  return out;
}

void Spiral::initialize(int north) {
  data.resize(north, north);
}

void Spiral::build() {
  int val = 1;

  // east/south
  int east = 0, south = 0;

  // west/north
  int west = data.rows();
  int north = data.cols();

  while(east < west && south < north) {
    for(int i = south; i < north; ++i) {
      data[east][i] = val++;
    }
    east++;

    for(int i = east; i < west; ++i) {
      data[i][north - 1] = val++;
    }
    north--;
    
    if(east < west) {
      for(int i = north - 1; i >= south; --i) {
        data[west - 1][i] = val++;
      }
      west--;
    }

    if(south < north) {
      for(int i = west - 1; i >= east; --i) {
        data[i][south] = val++;
      }
      south++;
    }
  }
}
