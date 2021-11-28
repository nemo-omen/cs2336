#include <iostream>
#include <cstdlib>
#include <string>

bool isDelimiter(const char delim, char delimList[]);
bool isNestedCorrectly(string);

int main(int argc, char *argv[]){
	
}

bool isNestedCorrectly(string) {
	const char openDelimiters [3] = {'{', '[', '('};
	const char closeDelimiters [3] = {'}', ']', ')'};

}

bool isDelimiter(const char delim, char delimList[]) {
	for(char del : delimList) {
		if(del == delim) return true;
	}
	return false;
}