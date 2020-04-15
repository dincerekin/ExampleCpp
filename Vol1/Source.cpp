#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	// Outputting to console.
	printf("Hello World!\n"); // C style
	cout << "Hello " << "World!" << endl; // C++ style

	// Declaring variable.
	int myAge = 69;

	cout << myAge << endl;
	cout << "sizeof(integer)" << sizeof(myAge) << endl;

	//Data types
	//short, int, float, double, bool, char, string, void,

	//Typecasting
	cout << "4 / 5 = " << 4 / 5 << endl;
	cout << "(float) 4 / 5 = " << (float) 4 / 5 << endl;



//CONTROL FLOW
	//If statements
	if (true) {}
	else if(false){}
	else{}

	//Switch statements
	switch (myAge) {
	case 10: cout << "myAge is 10!" << endl; break;
	case 20: cout << "myAge is 20!" << endl; break;
	case 69: cout << "myAge is 69!" << endl; break;
	default: cout << "myAge is not listed!" << endl; break;
	}


	return 0;
}