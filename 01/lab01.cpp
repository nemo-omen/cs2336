// Jeff Caldwell
// CS 2336
// Lab 01

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string const HEADER = "Jeff Caldwell - CS 2336 - Lab 01";

void productOfDigits(uint n, int steps);

void getSteps(uint n); 


int main () {
	cout << HEADER << "\n" << endl;

	uint numberInput;

	while(cin >> numberInput) {							
		
		productOfDigits(numberInput, 0);

	}
}


void productOfDigits(uint n, int steps) {

	uint digit, product;

	product = 1; 														// initialize product to 1 so it can
																					// multiply into any digit

	cout << n << " -> "; 										// initial output

	do {
		digit = n % 10; 											// get the last digit
		
		product *= digit; 										// multiply that digit into the product
		
		n = n / 10; 													// remove that last digit from the original number
	} while(n != 0);

		steps++; 															// increment steps

	if((product / 10) != 0) {   						// recurse if the number of digits
		productOfDigits(product, steps); 			// is greater than 1
	} else {
		cout << product << " persistence = " << steps << endl; // end of output
	}
}