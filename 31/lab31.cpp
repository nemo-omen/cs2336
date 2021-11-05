// Jeff Caldwell
// CS 2336
// Lab 31

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string ID = "Jeff Caldwell - CS 2336 - Lab 31\n\n";

void printLine(int length, ostream& os);

int main(int argc, const char** argv) {
  vector<string>::pointer ptr, end;
  vector<string> filenames;
  string inputLine;
  int windowWidth = 60;
  uint L = 0;

  cout << ID;
  printLine(windowWidth, cout);

  // read lines from input
  // and compare along the way to assign
  // highest length to L
  while(getline(cin, inputLine)) {
    filenames.emplace_back(inputLine);
    if (L < inputLine.length()) L = inputLine.length();
  }

  // sort filenames before formatting/printing
  sort(filenames.begin(), filenames.end());

  // number of fileNames
  int F = filenames.size();

  // initial number of columns
  int C = ((windowWidth - L) / (L + 2)) + 1;
  
  // number of rows
  int R = F % C == 0 ? (F / C) : (F / C) + 1;
  
  // final number of columns
  C = F % R == 0 ? (F / R) : (F / R) + 1;


  // outer loop controlled by r (number of rows)
  // inner loop controlled by c (number of columns)
  for(int i = 0; i < R; i++) {
    for(ptr = filenames.data() + i, end = ptr + (R * C); ptr < end; ptr+=R) {

      // add 2 to formatted width to match provided output
      // - TODO: double check formulae to make sure vals correct
      cout << left << setw(L + 2) << *ptr;
    }
      cout << '\n';
  }
    return 0;
}

void printLine(int length, ostream& os) {
  char ch = os.fill();
  os << setfill('-') << setw(length) << "-" << setfill(ch) << endl;
}

/* NOTES */


// F = number of filenames
// L = length of filename
// C = number of columns
// R = number of rows

// total window width = 60 char
// <---------60--------->
// <---60 - l -->|<--l-->
//        |          |
//        V          V
// C = (60-L)/(L+2) + 1
// -----------------------
// 
// R = F/C (may need rounding up if f%c!=0)
// C = F/R (may need rounding up if f%r!=0)

// rightmost col has width of l