// Jeff Caldwell
// CS 2336
// Lab 31

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


int main(int argc, const char** argv) {
  cout << ID;

  printLine(60, cout);

  vector<string> filenames;
  string inputLine;

  while(getline(cin, inputLine)) {
    filenames.emplace_back(inputLine);
  }

  sort(filenames.begin(), filenames.end());

  vector<string>::pointer ptr, end;

  // outer loop controlled by r (number of rows)
  // inner loop controlled by c (number of columns)
  for(ptr = filenames.data(), end = ptr + filenames.size(); 
      ptr < end;
      ++ptr) {
        cout << left << setw(60) << *ptr << endl;
      }
    return 0;
}



void printLine(int length, ostream& os) {
  char ch = os.fill();
  os << setfill('-') << setw(length) << "-" << setfill(ch) << endl;
}