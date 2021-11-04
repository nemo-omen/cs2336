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

  sort(filenames.begin(), filenames.end());
  // number of fileNames
  int F = filenames.size();

  // initial number of columns
  int C = ((windowWidth - L) / (L + 2)) + 1;
  
  // number of rows
  int R = F % C == 0 ? (F / C) : (F / C) + 1;
  
  // final number of columns
  C = F % R == 0 ? (F / R) : (F / R) + 1;

  vector<string>::pointer ptr, end;

  // cout << "F: " << F << endl;
  // cout << "L: " << L << endl;
  // cout << "R: " << R << endl;
  // cout << "C: " << C << endl;

  // outer loop controlled by r (number of rows)
  // inner loop controlled by c (number of columns)
  for(int i = 0; i < R; i++) {
    for(ptr = filenames.data() + (R * i), end = ptr + filenames.size(); ptr < end; ptr+=R) {
      cout << left << setw(L + 1) << *ptr;
    }
    // for(int j = (C * i); j < filenames.size(); j++) {
    //   cout << left << setw(L + 1) << filenames[j * R];
    // }
      cout << '\n';
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