#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes. These are used so the meat of functions can be placed after main().
int addNumbers(int, int);
int addNumbers(int,int,int);
int getFactorial(int);
void makeMeYoung(int*);

int main() {
	// ARITHMETIC
		// operators are +, -, *, /, %, ++, --

	cout << "5 + 2 = " << 5 + 2 << endl;
	cout << "5 - 2 = " << 5 - 2 << endl;
	cout << "5 * 2 = " << 5 * 2 << endl;
	cout << "5 / 2 = " << 5 / 2 << endl;
	cout << "5 % 2 = " << 5 % 2 << endl;

	int five = 5;
	cout << "5++ = " << five++ << endl;
	cout << "++5 = " << ++five << endl;
	cout << "5-- = " << five-- << endl;
	cout << "--5 = " << --five << endl << endl;

		// Shorthand assignment operators
			// a += b is equivalent to a = a + b
			// There is also -=, *=, /=, %=

		// Outputting to console.
	printf("Hello World!\n"); // C style
	cout << "Hello " << "World!" << endl << endl; // C++ style, use this.


		// Declaring variable.
	int myAge = 69;
	cout << "myAge = " << myAge << endl;
	cout << "sizeof(myAge) = " << sizeof(myAge) << endl << endl;

		// Data types:
			// short, int, float, double, bool, char, string, void.
		// Data type modifiers:
			// unsigned, const, static.

		// Setting integers in hexadecimal.
	int hex_integer = 0xFF;
	cout << "hex_integer: " << hex_integer << endl;
	cout << "hex_integer (std::hex)" << std::hex << hex_integer << endl; // Displaying integers in hexadecimal format.
	cout << "hex_integer (std::dec)" << std::dec << hex_integer << endl; // Displaying integers in decimal format (default).
	cout << "hex_integer (std::oct)" << std::oct << hex_integer << endl; // Displaying integers in octal format.

		// Typecasting.
	cout << "4 / 5 = " << 4 / 5 << endl;
	cout << "(float) 4 / 5 = " << (float)4 / 5 << endl << endl;

	// ARRAYS
		// Constructing.
	int myFavNums[5] = { 4, 13, 14, 24, 34 };
	int myFavNumsMulti[3][3] = { {4, 13, 14}, {4, 13, 14},{14, 24, 34 } };

		// Indexing.
	cout << "myFavNums[0] = " << myFavNums[0] << endl;
	cout << "myFavNumsMulti[0] = " << myFavNumsMulti[0][0] << endl;

		// Assigning
	myFavNums[0] = 69;
	myFavNumsMulti[0][0] = 69;
	cout << "myFavNums[0] = " << myFavNums[0] << endl;
	cout << "myFavNumsMulti[0] = " << myFavNumsMulti[0][0] << endl;

	// CONTROL FLOW
		// If statement.
	if (true) {}
	else if (false) {}
	else {}

		// Switch statement.
	switch (myAge) {
	case 10: cout << "myAge is 10!" << endl; break;
	case 20: cout << "myAge is 20!" << endl; break;
	case 69: cout << "myAge is 69!" << endl; break;
	default: cout << "myAge is not listed!" << endl << endl; break;
	}

	cout << endl;

		// Conditional assignment.
	bool logical_statement = true;
	string value_if_true = "true";
	string value_if_false = "false";
	string condional_assignment = logical_statement ? value_if_true : value_if_false;

		// For statement.
	for (int i = 0; i <= 10; ++i) { //use preincrement (++i) over post-incrment (i++) in for loops).
		continue; //skip to next iteration of loop.
		break; //break out of loop.
	}

		// While statement.
	int condition = 0;
	while (condition < 5) {
		cout << "condition = " << condition << endl;
		condition++;
	}

	cout << endl;

		// Do-while statement.
	condition = 0;
	do {
		cout << "condition = " << condition << endl;
		condition++;
	} while (condition < 5);

	cout << endl;

	// EXCEPTION HANDLING
		// Use this when trying to execute code that may raise an error.
		// Only use this when the error is the result of something external to this program.
	int number = 0;
	try {
		if (number != 0) {
			cout << 2 / number << endl;
		}
		else throw(number);
	}
	catch (int number) {
		cout << number << " is not valid input" << endl << endl;
	}

	// FILE I/O
		// We can read and write to files using text or machine readable binary.
	string steveQuote = "A day without sunshine is like, you know, night";

		// Create an output filestream and if the file doesn't exist create it.
	ofstream writer("stevequote.txt");

		// Verify that the file stream object was created.
	if (!writer) {
		cout << "Error opening file" << endl;
		// Signal that an error occurred.
		return -1;
	}
	else {
		// Write the text to the file.
		writer << steveQuote << endl;

		// Close the file.
		writer.close();
	}

		// Open a stream to append to whats there with ios::app
		// ios::binary : Treat the file as binary
		// ios::in : Open a file to read input
		// ios::trunc : Default
		// ios::out : Open a file to write output
	ofstream writer2("stevequote.txt", ios::app);

	if (!writer2) {
		cout << "Error opening file" << endl;
		// Signal that an error occurred.
		return -1;
	}
	else {
		writer2 << "- Steve Martin" << endl;
		writer2.close();
	}
	char letter;

		// Read characters from a file using an input file stream.
	ifstream reader("stevequote.txt");

	if (!reader) {
		cout << "Error opening file" << endl;
		return -1;
	}
	else {
		// Read each character from the stream until end of file.
		for (int i = 0; !reader.eof(); i++) {
			// Get the next letter and output it.
			reader.get(letter);
			cout << letter;
		}
		cout << endl;
		reader.close();
	}

	// STRINGS

	// VECTORS

	return 0;
}

// FUNCTIONS
		// Declaring.
int addNumbers(int firstNum, int secondNum = 0) { //secondNum is an optional parameter with default value 0.
	int combinedValue = firstNum + secondNum;

	return combinedValue;
}

		// An overloaded function has the same name, but different attributes.
int addNumbers(int firstNum, int secondNum, int thirdNum) {
	return firstNum + secondNum + thirdNum;
}

		// A recursive function is one that calls itself.
int getFactorial(int number) {
	int sum;
	if (number == 1) sum = 1;
	else sum = (getFactorial(number - 1) * number);
	return sum;
}


void makeMeYoung(int* age) { // Since I'm getting a pointer use int*.
	cout << "I used to be " << *age << endl; // Refer to the referenced variable with *age.
	*age = 21;
}

		// A function that receives a reference can manipulate the value globally.
void actYourAge(int& age) {
	age = 39;
}

// CLASSES