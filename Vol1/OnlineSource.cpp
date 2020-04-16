// This is a comment
/*
 * Multi-line comment
 */

 // Tells the compiler iostream library which contains the function cout
#include &lt;iostream&gt;

// Allows us to use vectors
#include &lt;vector&gt;

// Allows us to use strings
#include &lt;string&gt;

// Allow us to work with files
#include &lt;fstream&gt;

// Allows functions in the std namespace to be used without their prefix
// std::cout becomes cout
using namespace std;

// ---------- FUNCTIONS ----------
// The function has return type, function name and attributes with
// their data types
// The attribute data types must match the value passed in
// This data is passed by value
// You can define default values to attributes as long as they come last
// This is known as a function prototype
int addNumbers(int firstNum, int secondNum = 0) {
	int combinedValue = firstNum + secondNum;

	return combinedValue;
}

// An overloaded function has the same name, but different attributes
int addNumbers(int firstNum, int secondNum, int thirdNum) {
	return firstNum + secondNum + thirdNum;
}

// A recursive function is one that calls itself

int getFactorial(int number) {
	int sum;
	if (number == 1) sum = 1;
	else sum = (getFactorial(number - 1) * number);
	return sum;

	// getFactorial(2) [Returns 2] * 3
	// getFactorial(1) [Returns 1] * 2 &lt;This value goes above&gt;
	// 2 * 3 = 6
}

// Doesn't have a return type so use void
// Since I'm getting a pointer use int*
// Refer to the referenced variable with *age
void makeMeYoung(int* age) {
	cout& lt; &lt; "I used to be " & lt; &lt; *age& lt; &lt; endl;
	*age = 21;
}

// A function that receives a reference can manipulate the value globally
void actYourAge(int& amp; age) {
	age = 39;
}

// ---------- END OF FUNCTIONS ----------

// ---------- CLASSES ----------
// classes start with the name class

class Animal
{
	// private variables are only available to methods in the class
private:
	int height;
	int weight;
	string name;

	// A static variable shares the same value with every object in the class
	static int numOfAnimals;

	// Public variables can be accessed by anything with access to the object
public:
	int getHeight() { return height; }
	int getWeight() { return weight; }
	string getName() { return name; }
	void setHeight(int cm) { height = cm; }
	void setWeight(int kg) { weight = kg; }
	void setName(string dogName) { name = dogName; }

	// Declared as a prototype
	void setAll(int, int, string);

	// Declare the constructor
	Animal(int, int, string);

	// Declare the deconstructor
	~Animal();

	// An overloaded constructor called when no data is passed
	Animal();

	// protected members are available to members of the same class and
	// sub classes

	// Static methods aren't attached to an object and can only access
	// static member variables
	static int getNumOfAnimals() { return numOfAnimals; }

	// This method will be overwritten in Dog
	void toString();
};

int Animal::numOfAnimals = 0;

// Define the protoype method setAll
void Animal::setAll(int height, int weight, string name) {
	// This is used to refer to an object created of this class type
	this - &gt; height = height;
	this - &gt; weight = weight;
	this - &gt; name = name;
	Animal::numOfAnimals++;
}

// A constructor is called when an object is created
Animal::Animal(int height, int weight, string name) {
	this - &gt; height = height;
	this - &gt; weight = weight;
	this - &gt; name = name;
}

// The destructor is called when an object is destroyed
Animal::~Animal() {
	cout& lt; &lt; "Animal " & lt; &lt; this - &gt; name& lt; &lt; " destroyed" & lt; &lt; endl;
}

// A constructor called when no attributes are passed
Animal::Animal() {
	numOfAnimals++;
}

// This method prints object info to screen and will be overwritten
void Animal::toString() {
	cout& lt; &lt; this - &gt; name& lt; &lt; " is " & lt; &lt; this - &gt; height& lt; &lt; " cms tall and "
		& lt; &lt; this - &gt; weight& lt; &lt; " kgs in weight" & lt; &lt; endl;
}

// We can inherit the variables and methods of other classes
class Dog : public Animal {
private:
	string sound = "Woof";
public:
	void getSound() { cout& lt; &lt; sound& lt; &lt; endl; }

	// Declare the constructor
	Dog(int, int, string, string);

	// Declare the default constructor and call the default superclass
	// constructor
	Dog() : Animal() {};

	// Overwrite toString
	void toString();
};

// Dog constructor passes the right attributes to the superclass
// constructor and then handles the attribute bark that remains
Dog::Dog(int height, int weight, string name, string bark) :
	Animal(height, weight, name) {
	this - &gt; sound = bark;
}

// toString method overwritten
void Dog::toString() {
	// Because the attributes were private in Animal they must be retrieved
	// by called the get methods
	cout& lt; &lt; this - &gt; getName()& lt; &lt; " is " & lt; &lt; this - &gt; getHeight()& lt; &lt;
	" cms tall and " & lt; &lt; this - &gt; getWeight()& lt; &lt; " kgs in weight and says " & lt; &lt;
	this - &gt; sound& lt; &lt; endl;
}

// ---------- END OF CLASSES ----------

// This is where execution begins. Attributes can be sent to main
int main() {
	// cout outputs text and a carriage return with endl
	// Statements must end with a semicolon
	// Strings must be surrounded by "
	// &lt;&lt; sends the text via standard output to the screen
	cout& lt; &lt; "Hello Internet" & lt; &lt; endl;

	// ---------- VARIABLES / DATA TYPES ----------
	// Variables start with a letter and can contain letters, numbers and _
	// They are case sensitive

	// A value that won't change is a constant
	// Starts with const and it should be uppercase
	const double PI = 3.1415926535;

	// chars can contain 1 character that are surrounded with ' and is one byte in size
	char myGrade = 'A';

	// bools have the value of (true/1) or (false/0)
	bool isHappy = true;

	// ints are whole numbers
	int myAge = 39;

	// floats are floating point numbers accurate to about 6 decimals
	float favNum = 3.141592;

	// doubles are floating point numbers accurate to about 15 digits
	double otherFavNum = 1.6180339887;

	// You can output a variable value like this
	cout& lt; &lt; "Favorite Number " & lt; &lt; favNum& lt; &lt; endl;

	// Other types include
	// short int : At least 16 bits
	// long int : At least 32 bits
	// long long int : At least 64 bits
	// unsigned int : Same size as signed version
	// long double : Not less then double

	// You can get the number of bytes for a data type with sizeof

	cout& lt; &lt; "Size of int " & lt; &lt; sizeof(myAge)& lt; &lt; endl;
	cout& lt; &lt; "Size of char " & lt; &lt; sizeof(myGrade)& lt; &lt; endl;
	cout& lt; &lt; "Size of bool " & lt; &lt; sizeof(isHappy)& lt; &lt; endl;
	cout& lt; &lt; "Size of float " & lt; &lt; sizeof(favNum)& lt; &lt; endl;
	cout& lt; &lt; "Size of double " & lt; &lt; sizeof(otherFavNum)& lt; &lt; endl;

	int largestInt = 2147483647;

	cout& lt; &lt; "Largest int " & lt; &lt; largestInt& lt; &lt; endl;

	// ---------- ARITHMETIC ----------
	// The arithmetic operators are +, -, *, /, %, ++, --

	cout& lt; &lt; "5 + 2 = " & lt; &lt; 5 + 2 & lt; &lt; endl;
	cout& lt; &lt; "5 - 2 = " & lt; &lt; 5 - 2 & lt; &lt; endl;
	cout& lt; &lt; "5 * 2 = " & lt; &lt; 5 * 2 & lt; &lt; endl;
	cout& lt; &lt; "5 / 2 = " & lt; &lt; 5 / 2 & lt; &lt; endl;
	cout& lt; &lt; "5 % 2 = " & lt; &lt; 5 % 2 & lt; &lt; endl;

	int five = 5;
	cout& lt; &lt; "5++ = " & lt; &lt; five++& lt; &lt; endl;
	cout& lt; &lt; "++5 = " & lt; &lt; ++five& lt; &lt; endl;
	cout& lt; &lt; "5-- = " & lt; &lt; five--& lt; &lt; endl;
	cout& lt; &lt; "--5 = " & lt; &lt; --five& lt; &lt; endl;

	// Shorthand assignment operators
	// a += b == a = a + b
	// There is also -=, *=, /=, %=

	// Order of Operation states * and / is performed before + and -

	cout& lt; &lt; "1 + 2 - 3 * 2 = " & lt; &lt; 1 + 2 - 3 * 2 & lt; &lt; endl;
	cout& lt; &lt; "(1 + 2 - 3) * 2 = " & lt; &lt; (1 + 2 - 3) * 2 & lt; &lt; endl;

	// ---------- CASTING ----------
	// You convert from one data type to another by casting
	// char, int, float, double

	cout& lt; &lt; "4 / 5 = " & lt; &lt; 4 / 5 & lt; &lt; endl;
	cout& lt; &lt; "4 / 5 = " & lt; &lt; (float)4 / 5 & lt; &lt; endl;

	// ---------- IF STATEMENT ----------
	// Executes different code depending upon a condition

	// Comparison operators include ==, !=, &gt;, &lt;, &gt;=, &lt;=
	// Will return true (1) if the comparison is true, or false (0)

	// Logical operators include &amp;&amp;, ||, !
	// Used to test 2 or more conditionals

	int age = 70;
	int ageAtLastExam = 16;
	bool isNotIntoxicated = true;

	if ((age & gt; = 1) & amp; &amp; (age & lt; 16)) {
		cout& lt; &lt; "You can't drive" & lt; &lt; endl;
	}
	else if (!isNotIntoxicated) {
		cout& lt; &lt; "You can't drive" & lt; &lt; endl;
	}
	else if (age& gt; = 80 & amp; &amp; ((age & gt; 100) || ((age - ageAtLastExam) & gt; 5))) {
		cout& lt; &lt; "You can't drive" & lt; &lt; endl;
	}
	else {
		cout& lt; &lt; "You can drive" & lt; &lt; endl;
	}

	// ---------- SWITCH STATEMENT ----------
	// switch is used when you have a limited number of possible options

	int greetingOption = 2;

	switch (greetingOption) {
	case 1:
		cout & lt; &lt; "bonjour" & lt; &lt; endl;
		break;

	case 2:
		cout & lt; &lt; "Hola" & lt; &lt; endl;
		break;

	case 3:
		cout & lt; &lt; "Hallo" & lt; &lt; endl;
		break;

	default:
		cout& lt; &lt; "Hello" & lt; &lt; endl;
	}

	// ---------- TERNARY OPERATOR ----------
	// Performs an assignment based on a condition
	// variable = (condition) ? if true : if false

	int largestNum = (5 & gt; 2) ? 5 : 2;

	cout& lt; &lt; "The biggest number is " & lt; &lt; largestNum& lt; &lt; endl;

	// ---------- ARRAYS ----------
	// Arrays store multiple values of the same type

	// You must provide a data type and the size of the array
	int myFavNums[5];

	// You can declare and add values in one step
	int badNums[5] = { 4, 13, 14, 24, 34 };

	// The first item in the array has the label (index) of 0
	cout& lt; &lt; "Bad Number 1: " & lt; &lt; badNums[0] & lt; &lt; endl;

	// You can create multidimensional arrays
	char myName[5][5] = { {'D','e','r','e','k'},{'B','a','n','a','s'} };

	cout& lt; &lt; "2nd Letter in 2nd Array: " & lt; &lt; myName[1][1] & lt; &lt; endl;

	// You can change a value in an array using its index
	myName[0][2] = 'e';

	cout& lt; &lt; "New Value " & lt; &lt; myName[0][2] & lt; &lt; endl;

	// ---------- FOR LOOP ----------
	// Continues to execute code as long as a condition is true

	for (int i = 1; i & lt; = 10; i++) {
		cout& lt; &lt; i& lt; &lt; endl;
	}

	// You can also cycle through an array by nesting for loops
	for (int j = 0; j & lt; 5; j++) {
		for (int k = 0; k & lt; 5; k++) {
			cout& lt; &lt; myName[j][k];
		}

		cout& lt; &lt; endl;
	}

	// ---------- WHILE LOOP ----------
	// Use a while loop when you don't know ahead of time when a loop will end

	// Generate a random number between 1 and 100
	int randNum = (rand() % 100) + 1;

	while (randNum != 100) {
		cout& lt; &lt; randNum& lt; &lt; ", ";

		// Used to get you out of the loop
		randNum = (rand() % 100) + 1;
	}

	cout& lt; &lt; endl;

	// You can do the same as the for loop like this
	// Create an index to iterate out side the while loop
	int index = 1;

	while (index& lt; = 10) {
		cout& lt; &lt; index& lt; &lt; endl;

		// Increment inside the loop
		index++;
	}

	// ---------- DO WHILE LOOP ----------
	// Used when you want to execute what is in the loop at least once

	// Used to store a series of characters
	string numberGuessed;
	int intNumberGuessed = 0;

	do {
		cout& lt; &lt; "Guess between 1 and 10: ";

		// Allows for user input
		// Pass the source and destination of the input
		getline(cin, numberGuessed);

		// stoi converts the string into an integer
		intNumberGuessed = stoi(numberGuessed);
		cout& lt; &lt; intNumberGuessed& lt; &lt; endl;

		// We'll continue looping until the number entered is 4
	} while (intNumberGuessed != 4);

	cout& lt; &lt; "You Win" & lt; &lt; endl;

	// ---------- STRINGS ----------
	// The string library class provides a string object
	// You must always surround strings with "
	// Unlike the char arrays in c, the string object automatically resizes

	// The C way of making a string
	char happyArray[6] = { 'H', 'a', 'p', 'p', 'y', '\0' };

	// The C++ way
	string birthdayString = " Birthday";

	// You can combine / concatenate strings with +
	cout& lt; &lt; happyArray + birthdayString & lt; &lt; endl;

	string yourName;
	cout& lt; &lt; "What is your name? ";
	getline(cin, yourName);

	cout& lt; &lt; "Hello " & lt; &lt; yourName& lt; &lt; endl;

	double eulersConstant = .57721;
	string eulerGuess;
	double eulerGuessDouble;
	cout& lt; &lt; "What is Euler's Constant? ";
	getline(cin, eulerGuess);

	// Converts a string into a double
	// stof() for floats
	eulerGuessDouble = stod(eulerGuess);

	if (eulerGuessDouble == eulersConstant) {
		cout& lt; &lt; "You are right" & lt; &lt; endl;
	}
	else {
		cout& lt; &lt; "You are wrong" & lt; &lt; endl;
	}

	// Size returns the number of characters
	cout& lt; &lt; "Size of string " & lt; &lt; eulerGuess.size()& lt; &lt; endl;

	// empty tells you if string is empty or not
	cout& lt; &lt; "Is string empty " & lt; &lt; eulerGuess.empty()& lt; &lt; endl;

	// append adds strings together
	cout& lt; &lt; eulerGuess.append(" was your guess")& lt; &lt; endl;

	string dogString = "dog";
	string catString = "cat";

	// Compare returns a 0 for a match, 1 if less than, -1 if greater then
	cout& lt; &lt; dogString.compare(catString)& lt; &lt; endl;
	cout& lt; &lt; dogString.compare(dogString)& lt; &lt; endl;
	cout& lt; &lt; catString.compare(dogString)& lt; &lt; endl;

	// assign copies a value to another string
	string wholeName = yourName.assign(yourName);
	cout& lt; &lt; wholeName& lt; &lt; endl;

	// You can get a substring as well by defining the starting index and the
	// number of characters to copy
	string firstName = wholeName.assign(wholeName, 0, 5);
	cout& lt; &lt; firstName& lt; &lt; endl;

	// find returns the index for the string your searching for starting
	// from the index defined
	int lastNameIndex = yourName.find("Banas", 0);
	cout& lt; &lt; "Index for last name " & lt; &lt; lastNameIndex& lt; &lt; endl;

	// insert places a string in the index defined
	yourName.insert(5, " Justin");
	cout& lt; &lt; yourName& lt; &lt; endl;

	// erase will delete 6 characters starting at index 7
	yourName.erase(6, 7);
	cout& lt; &lt; yourName& lt; &lt; endl;

	// replace 5 characters starting at index 6 with the string Maximus
	yourName.replace(6, 5, "Maximus");
	cout& lt; &lt; yourName& lt; &lt; endl;

	// ---------- VECTORS ----------
	// Vectors are like arrays, but their size can change

	vector& lt; int& gt; lotteryNumVect(10);

	int lotteryNumArray[5] = { 4, 13, 14, 24, 34 };

	// Add the array to the vector starting at the beginning of the vector
	lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray + 3);

	// Insert a value into the 5th index
	lotteryNumVect.insert(lotteryNumVect.begin() + 5, 44);

	// at gets the value in the specified index
	cout& lt; &lt; "Value in 5 " & lt; &lt; lotteryNumVect.at(5)& lt; &lt; endl;

	// push_back adds a value at the end of a vector
	lotteryNumVect.push_back(64);

	// back gets the value in the final index
	cout& lt; &lt; "Final Value " & lt; &lt; lotteryNumVect.back()& lt; &lt; endl;

	// pop_back removes the final element
	lotteryNumVect.pop_back();

	// front returns the first element
	cout& lt; &lt; "First Element " & lt; &lt; lotteryNumVect.front()& lt; &lt; endl;

	// back returns the last element
	cout& lt; &lt; "Last Element " & lt; &lt; lotteryNumVect.back()& lt; &lt; endl;

	// empty tells you if the vector is empty
	cout& lt; &lt; "Vector Empty " & lt; &lt; lotteryNumVect.empty()& lt; &lt; endl;

	// size returns the total number of elements
	cout& lt; &lt; "Number of Vector Elements " & lt; &lt; lotteryNumVect.size()& lt; &lt; endl;

	// ---------- FUNCTIONS ----------
	// Functions allow you to reuse and better organize your code

	cout& lt; &lt; addNumbers(1)& lt; &lt; endl;

	// You can't access values created in functions (Out of Scope)
	// cout &lt;&lt; combinedValue &lt;&lt; endl;

	cout& lt; &lt; addNumbers(1, 5, 6)& lt; &lt; endl;

	cout& lt; &lt; "The factorial of 3 is " & lt; &lt; getFactorial(3)& lt; &lt; endl;

	// ---------- FILE I/O ----------
	// We can read and write to files using text or machine readable binary

	string steveQuote = "A day without sunshine is like, you know, night";

	// Create an output filestream and if the file doesn't exist create it
	ofstream writer("stevequote.txt");

	// Verify that the file stream object was created
	if (!writer) {
		cout& lt; &lt; "Error opening file" & lt; &lt; endl;

		// Signal that an error occurred
		return -1;
	}
	else {
		// Write the text to the file
		writer& lt; &lt; steveQuote& lt; &lt; endl;

		// Close the file
		writer.close();
	}

	// Open a stream to append to whats there with ios::app
	// ios::binary : Treat the file as binary
	// ios::in : Open a file to read input
	// ios::trunc : Default
	// ios::out : Open a file to write output
	ofstream writer2("stevequote.txt", ios::app);

	if (!writer2) {
		cout& lt; &lt; "Error opening file" & lt; &lt; endl;

		// Signal that an error occurred
		return -1;
	}
	else {
		writer2& lt; &lt; "\n- Steve Martin" & lt; &lt; endl;
		writer2.close();
	}

	char letter;

	// Read characters from a file using an input file stream
	ifstream reader("stevequote.txt");

	if (!reader) {
		cout& lt; &lt; "Error opening file" & lt; &lt; endl;
		return -1;
	}
	else {
		// Read each character from the stream until end of file
		for (int i = 0; !reader.eof(); i++) {
			// Get the next letter and output it
			reader.get(letter);
			cout& lt; &lt; letter;
		}

		cout& lt; &lt; endl;
		reader.close();
	}

	// ---------- EXCEPTION HANDLING ----------
	// You can be prepared for potential problems with exception handling

	int number = 0;

	try {
		if (number != 0) {
			cout& lt; &lt; 2 / number & lt; &lt; endl;
		}
		else throw(number);
	}
	catch (int number) {
		cout& lt; &lt; number& lt; &lt; " is not valid input" & lt; &lt; endl;
	}

	// ---------- POINTERS ----------
	// When data is stored it is stored in an appropriately sized box based
	// on its data type

	int myAge = 39;
	char myGrade = 'A';

	cout& lt; &lt; "Size of int " & lt; &lt; sizeof(myAge)& lt; &lt; endl;
	cout& lt; &lt; "Size of char " & lt; &lt; sizeof(myGrade)& lt; &lt; endl;

	// You can reference the box (memory address) where data is stored with
	// the &amp; reference operator

	cout& lt; &lt; "myAge is located at " & lt; &lt; &amp; myAge& lt; &lt; endl;

	// A pointer can store a memory address
	// The data type must be the same as the data referenced and it is followed
	// by a *

	int* agePtr = &amp; myAge;

	// You can access the memory address and the data
	cout& lt; &lt; "Address of pointer " & lt; &lt; agePtr& lt; &lt; endl;

	// * is the dereference or indirection operator
	cout& lt; &lt; "Data at memory address " & lt; &lt; *agePtr& lt; &lt; endl;

	int badNums[5] = { 4, 13, 14, 24, 34 };
	int* numArrayPtr = badNums;

	// You can increment through an array using a pointer with ++ or --
	cout& lt; &lt; "Address " & lt; &lt; numArrayPtr& lt; &lt; " Value " & lt; &lt; *numArrayPtr& lt; &lt; endl;
	numArrayPtr++;
	cout& lt; &lt; "Address " & lt; &lt; numArrayPtr& lt; &lt; " Value " & lt; &lt; *numArrayPtr& lt; &lt; endl;

	// An array name is just a pointer to the array
	cout& lt; &lt; "Address " & lt; &lt; badNums& lt; &lt; " Value " & lt; &lt; *badNums& lt; &lt; endl;

	// When you pass a variable to a function you are passing the value
	// When you pass a pointer to a function you are passing a reference
	// that can be changed

	makeMeYoung(&amp; myAge);

	cout& lt; &lt; "I'm " & lt; &lt; myAge& lt; &lt; " years old now" & lt; &lt; endl;

	// &amp; denotes that ageRef will be a reference to the assigned variable
	int& amp; ageRef = myAge;

	cout& lt; &lt; "ageRef : " & lt; &lt; ageRef& lt; &lt; endl;

	// It can manipulate the other variables data
	ageRef++;

	cout& lt; &lt; "myAge : " & lt; &lt; myAge& lt; &lt; endl;

	// You can pass the reference to a function
	actYourAge(ageRef);

	cout& lt; &lt; "myAge : " & lt; &lt; myAge& lt; &lt; endl;

	// When deciding on whether to use pointers or references
	// Use Pointers if you don't want to initialize at declaration, or if
	// you need to assign another variable
	// otherwise use a reference

	// ---------- CLASSES &amp; OBJECTS ----------
	// Classes are the blueprints for modeling real world objects
	// Real world objects have attributes, classes have members / variables
	// Real world objects have abilities, classes have methods / functions
	// Classes believe in hiding data (encapsulation) from outside code

	// Declare a Animal type object
	Animal fred;

	// Set the values for the Animal
	fred.setHeight(33);
	fred.setWeight(10);
	fred.setName("Fred");

	// Get the values for the Animal
	cout& lt; &lt; fred.getName()& lt; &lt; " is " & lt; &lt; fred.getHeight()& lt; &lt; " cms tall and "
		& lt; &lt; fred.getWeight()& lt; &lt; " kgs in weight" & lt; &lt; endl;

	fred.setAll(34, 12, "Fred");

	cout& lt; &lt; fred.getName()& lt; &lt; " is " & lt; &lt; fred.getHeight()& lt; &lt; " cms tall and "
		& lt; &lt; fred.getWeight()& lt; &lt; " kgs in weight" & lt; &lt; endl;

	// Creating an object using the constructor
	Animal tom(36, 15, "Tom");

	cout& lt; &lt; tom.getName()& lt; &lt; " is " & lt; &lt; tom.getHeight()& lt; &lt; " cms tall and "
		& lt; &lt; tom.getWeight()& lt; &lt; " kgs in weight" & lt; &lt; endl;

	// Demonstrate the inheriting class Dog
	Dog spot(38, 16, "Spot", "Woof");

	// static methods are called by using the class name and the scope operator
	cout& lt; &lt; "Number of Animals " & lt; &lt; Animal::getNumOfAnimals()& lt; &lt; endl;

	spot.getSound();

	// Test the toString method that will be overwritten
	tom.toString();
	spot.toString();

	// We can call the superclass version of a method with the class name
	// and the scope operator
	spot.Animal::toString();

	// When a function finishes it must return an integer value
	// Zero means that the function ended with success
	return 0;
}

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
#include <iostream>
using namespace std;

// Virtual Methods and Polymorphism
// Polymorpism allows you to treat subclasses as their superclass and yet
// call the correct overwritten methods in the subclass automatically

class Animal {
public:
	void getFamily() { cout << "We are Animals" << endl; }

	// When we define a method as virtual we know that Animal
	// will be a base class that may have this method overwritten
	virtual void getClass() { cout << "I'm an Animal" << endl; }
};

class Dog : public Animal {
public:
	void getClass() { cout << "I'm a Dog" << endl; }
};

class GermanShepard : public Dog {
public:
	void getClass() { cout << "I'm a German Shepard" << endl; }
	void getDerived() { cout << "I'm an Animal and Dog" << endl; }
};

void whatClassAreYou(Animal* animal) {
	animal->getClass();
}

int main() {
	Animal* animal = new Animal;
	Dog* dog = new Dog;

	// If a method is marked virtual or not doesn't matter if we call the method
	// directly from the object
	animal->getClass();
	dog->getClass();

	// If getClass is not marked as virtual outside functions won't look for
	// overwritten methods in subclasses however
	whatClassAreYou(animal);
	whatClassAreYou(dog);

	Dog spot;
	GermanShepard max;

	// A base class can call derived class methods as long as they exist
	// in the base class
	Animal* ptrDog = &spot;
	Animal* ptrGShepard = &max;

	// Call the method not overwritten in the super class Animal
	ptrDog->getFamily();

	// Since getClass was overwritten in Dog call the Dog version
	ptrDog->getClass();

	// Call to the super class
	ptrGShepard->getFamily();

	// Call to the overwritten GermanShepard version
	ptrGShepard->getClass();

	return 0;
}

#include &lt;iostream&gt;
using namespace std;

// Polymorpism allows you to treat subclasses as their superclass and yet
// call the correct overwritten methods in the subclass automatically

class Animal {
public:
	virtual void makeSound() { cout& lt; &lt; "The Animal says grrrr" & lt; &lt; endl; }

	// The Animal class could be a capability class that exists
	// only to be derived from by containing only virtual methods
	// that do nothing
};

class Cat : public Animal {
public:
	void makeSound() { cout& lt; &lt; "The Cat says meow" & lt; &lt; endl; }
};

class Dog : public Animal {
public:
	void makeSound() { cout& lt; &lt; "The Dog says woof" & lt; &lt; endl; }
};

// An abstract data type is a class that acts as the base to other classes
// They stand out because its methods are initialized with zero
// A pure virtual method must be overwritten by subclasses

class Car {
public:
	virtual int getNumWheels() = 0;
	virtual int getNumDoors() = 0;
};

class StationWagon : public Car {
public:
	int getNumWheels() { cout& lt; &lt; "Station Wagon has 4 Wheels" & lt; &lt; endl; }
	int getNumDoors() { cout& lt; &lt; "Station Wagon has 4 Doors" & lt; &lt; endl; }
	StationWagon() { }
	~StationWagon();
};

int main() {
	Animal* pCat = new Cat;
	Animal* pDog = new Dog;

	pCat - &gt; makeSound();
	pDog - &gt; makeSound();

	// Create a StationWagon using the abstract data type Car
	Car* stationWagon = new StationWagon();

	stationWagon - &gt; getNumWheels();

	return 0;
}