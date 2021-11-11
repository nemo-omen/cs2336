// Jeff Caldwell
// CS 2336
// Lab 36
#include <lab36.h>

// 4 loops

ostream& operator<<(ostream& out, const Spiral& spiral) {
  for(int i = 0; i < spiral.data.rows(); i++) {
    for(int j = 0; j < spiral.data.cols(); j++) {
      out << spiral.data[i][j] << " ";
    }
    out << '\n';
  }
  return out;
}

void Spiral::initialize(int n) {
  data.resize(n, n);
}

void Spiral::build() {

}
