// Jeff Caldwell
// CS 2336
// Lab 31


// f = number of filenames
// l = length of filename
// c = number of columns
// r = number of rows

// total window width = 60 char
// <---------60--------->
// <---60 - l -->|<--l-->
//        |          |
//        V          V
// c = (60-l)/(l+2) + 1
// -----------------------
// 
// r = f/c (may need rounding up if f%c!=0)
// c = f/r (may need rounding up if f%r!=0)

// rightmost col has width of l

// recieve a list of files
// sort them
// 

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string ID = "Jeff Caldwell - CS 2336 - Lab 31\n\n";

void printLine(int length, ostream& os);

int longestFileName(const vector<string>& fileNames);

int main(int argc, const char** argv) {
  cout << ID;
  printLine(60, cout);

  vector<string> filenames;
  string inputLine;

  while(getline(cin, inputLine)) {
    filenames.emplace_back(inputLine);
  }

  sort(filenames.begin(), filenames.end());

  int windowWidth = 60;
  int F = filenames.size();                     // number of fileNames
  int L = longestFileName(filenames);           // length of filename
  int C = ((windowWidth - L) / (L + 2)) + 1;          // initial number of columns
  cout << "C before recalc: " << C << '\n';
  int R = F % C == 0 ? (F / C) : (F / C) + 1;   // number of rows
  C = F % R == 0 ? (F / R) : (F / R) + 1;       // final number of columns

  vector<string>::pointer ptr, end;

  cout << "F: " << F << endl;
  cout << "L: " << L << endl;
  cout << "R: " << R << endl;
  cout << "C: " << C << endl;

  // outer loop controlled by r (number of rows)
  // inner loop controlled by c (number of columns)
  for(ptr = filenames.data(), end = ptr + filenames.size(); ptr < end; ++ptr) {
        // cout << left << setw(60) << *ptr << endl;
      }
    return 0;
}


int longestFileName(const vector<string>& fileNames) {
  vector<string> copy(fileNames);
  typename vector<string>::pointer ptr;
  uint longest = 0;

  for(ptr = copy.data(); ptr < copy.data() + copy.size(); ptr++) {
    if(ptr->length() > longest) longest = ptr->length();
  }
  return longest;
}

void printLine(int length, ostream& os) {
  char ch = os.fill();
  os << setfill('-') << setw(length) << "-" << setfill(ch) << endl;
}