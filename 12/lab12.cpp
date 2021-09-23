// Jeff Caldwell
// CS 2336
// Lab 12

#include <iostream>
#include <iomanip>

using namespace std;

ostream& insertComma(unsigned long num, ostream& os){
    if (num < 1000){
        os << num;
    } else {
        insertComma(num / 1000, os);
        char ch = os.fill();
        os << ',' << setfill('0') << setw(3) << num % 1000;
        os.fill(ch);    
    }
    return os;
}