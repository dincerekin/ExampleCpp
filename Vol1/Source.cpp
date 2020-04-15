#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	// Outputting to console.
	printf("Hello World!\n"); // C style
	cout << "Hello " << "World!" << endl << endl; // C++ style

	// Declaring variable.
	int myAge = 69;
	cout << "myAge = " << myAge << endl;
	cout << "sizeof(myAge) = " << sizeof(myAge) << endl << endl;

	//Data types
		//short, int, float, double, bool, char, string, void,

	//Typecasting
	cout << "4 / 5 = " << 4 / 5 << endl;
	cout << "(float) 4 / 5 = " << (float)4 / 5 << endl << endl;

//ARRAYS
	//Constructing
	int myFavNums[5] = { 4, 13, 14, 24, 34 };
	int myFavNumsMulti[3][3] = { {4, 13, 14}, {4, 13, 14},{14, 24, 34 }};

	//Indexing
	cout << "myFavNums[0] = " << myFavNums[0] << endl;
	cout << "myFavNumsMulti[0] = " << myFavNumsMulti[0][0] << endl;

	//Assigning
	myFavNums[0] = 69;
	myFavNumsMulti[0][0] = 69;
	cout << "myFavNums[0] = " << myFavNums[0] << endl;
	cout << "myFavNumsMulti[0] = " << myFavNumsMulti[0][0] << endl;

//

//CONTROL FLOW
	//If statement
	if (true) {}
	else if (false) {}
	else {}

	//Switch statement
	switch (myAge) {
	case 10: cout << "myAge is 10!" << endl; break;
	case 20: cout << "myAge is 20!" << endl; break;
	case 69: cout << "myAge is 69!" << endl; break;
	default: cout << "myAge is not listed!" << endl << endl; break;
	}

	//Conditional assignment
	bool logical_statement = true;
	string value_if_true = "true";
	string value_if_false = "false";
	string condional_assignment = logical_statement ? value_if_true : value_if_false;

	//For statement

	//While statement

	//Do-while statement


	return 0;
}