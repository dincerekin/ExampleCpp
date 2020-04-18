	// ---------- STRINGS ----------
	// The string library class provides a string object
	// You must always surround strings with "
	// Unlike the char arrays in c, the string object automatically resizes

	// The C way of making a string
	char happyArray[6] = { 'H', 'a', 'p', 'p', 'y', '\0' };

	// The C++ way
	string birthdayString = " Birthday";

	// You can combine / concatenate strings with +
	cout << happyArray + birthdayString  << endl;

	string yourName;
	cout << "What is your name? ";
	getline(cin, yourName);

	cout << "Hello "  << yourName << endl;

	double eulersConstant = .57721;
	string eulerGuess;
	double eulerGuessDouble;
	cout << "What is Euler's Constant? ";
	getline(cin, eulerGuess);

	// Converts a string into a double
	// stof() for floats
	eulerGuessDouble = stod(eulerGuess);

	if (eulerGuessDouble == eulersConstant) {
		cout << "You are right"  << endl;
	}
	else {
		cout << "You are wrong"  << endl;
	}

	// Size returns the number of characters
	cout << "Size of string "  << eulerGuess.size() << endl;

	// empty tells you if string is empty or not
	cout << "Is string empty "  << eulerGuess.empty() << endl;

	// append adds strings together
	cout << eulerGuess.append(" was your guess") << endl;

	string dogString = "dog";
	string catString = "cat";

	// Compare returns a 0 for a match, 1 if less than, -1 if greater then
	cout << dogString.compare(catString) << endl;
	cout << dogString.compare(dogString) << endl;
	cout << catString.compare(dogString) << endl;

	// assign copies a value to another string
	string wholeName = yourName.assign(yourName);
	cout << wholeName << endl;

	// You can get a substring as well by defining the starting index and the
	// number of characters to copy
	string firstName = wholeName.assign(wholeName, 0, 5);
	cout << firstName << endl;

	// find returns the index for the string your searching for starting
	// from the index defined
	int lastNameIndex = yourName.find("Banas", 0);
	cout << "Index for last name "  << lastNameIndex << endl;

	// insert places a string in the index defined
	yourName.insert(5, " Justin");
	cout << yourName << endl;

	// erase will delete 6 characters starting at index 7
	yourName.erase(6, 7);
	cout << yourName << endl;

	// replace 5 characters starting at index 6 with the string Maximus
	yourName.replace(6, 5, "Maximus");
	cout << yourName << endl;

	// ---------- VECTORS ----------

	// ---------- FUNCTIONS ----------
	// Functions allow you to reuse and better organize your code

	cout << addNumbers(1) << endl;

	// You can't access values created in functions (Out of Scope)
	// cout &lt;&lt; combinedValue &lt;&lt; endl;

	cout << addNumbers(1, 5, 6) << endl;

	cout << "The factorial of 3 is "  << getFactorial(3) << endl;


	// ---------- POINTERS ----------
	// When data is stored it is stored in an appropriately sized box based
	// on its data type

	int myAge = 39;
	char myGrade = 'A';

	cout << "Size of int "  << sizeof(myAge) << endl;
	cout << "Size of char "  << sizeof(myGrade) << endl;

	// You can reference the box (memory address) where data is stored with
	// the & reference operator

	cout << "myAge is located at "  << & myAge << endl;

	// A pointer can store a memory address
	// The data type must be the same as the data referenced and it is followed
	// by a *

	int* agePtr = & myAge;

	// You can access the memory address and the data
	cout << "Address of pointer "  << agePtr << endl;

	// * is the dereference or indirection operator
	cout << "Data at memory address "  << *agePtr << endl;

	int badNums[5] = { 4, 13, 14, 24, 34 };
	int* numArrayPtr = badNums;

	// You can increment through an array using a pointer with ++ or --
	cout << "Address "  << numArrayPtr << " Value "  << *numArrayPtr << endl;
	numArrayPtr++;
	cout << "Address "  << numArrayPtr << " Value "  << *numArrayPtr << endl;

	// An array name is just a pointer to the array
	cout << "Address "  << badNums << " Value "  << *badNums << endl;

	// When you pass a variable to a function you are passing the value
	// When you pass a pointer to a function you are passing a reference
	// that can be changed

	makeMeYoung(&myAge);

	cout << "I'm "  << myAge << " years old now"  << endl;

	// & denotes that ageRef will be a reference to the assigned variable
	int& ageRef = myAge;

	cout << "ageRef : "  << ageRef << endl;

	// It can manipulate the other variables data
	ageRef++;

	cout << "myAge : "  << myAge << endl;

	// You can pass the reference to a function
	actYourAge(ageRef);

	cout << "myAge : "  << myAge << endl;

	// When deciding on whether to use pointers or references
	// Use Pointers if you don't want to initialize at declaration, or if
	// you need to assign another variable
	// otherwise use a reference

	// ---------- CLASSES & OBJECTS ----------
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
	cout << fred.getName() << " is "  << fred.getHeight() << " cms tall and "
		 << fred.getWeight() << " kgs in weight"  << endl;

	fred.setAll(34, 12, "Fred");

	cout << fred.getName() << " is "  << fred.getHeight() << " cms tall and "
		 << fred.getWeight() << " kgs in weight"  << endl;

	// Creating an object using the constructor
	Animal tom(36, 15, "Tom");

	cout << tom.getName() << " is "  << tom.getHeight() << " cms tall and "
		 << tom.getWeight() << " kgs in weight"  << endl;

	// Demonstrate the inheriting class Dog
	Dog spot(38, 16, "Spot", "Woof");

	// static methods are called by using the class name and the scope operator
	cout << "Number of Animals "  << Animal::getNumOfAnimals() << endl;

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