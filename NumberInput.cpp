#include "stdafx.h" // for VS only, comment if you are using another compiler
#include <iostream>
#include <string>

// get number only from user
void getUserNumber(double &value) {
	char buffer[256]; // char buffer to get the users input
	std::fill_n(buffer, 256, NULL); // fill the buffer with nulls
	std::cin >> buffer; // get the user's input as an array of char
	bool period = false; // if there is a period in the number i.e. decimal point, it will turn true
	std::string num; // number as a string

	for (char& c : buffer) { // iterate through the input buffer
		if (c == '.' && !period) { // if there is a decimal point ...
			period = true; // ... change the period variable to true ...
			num += c; // ... and add it to the number string
		}
		if (isdigit(c)) // if the character is a digit ... 
			num += c; // ... add it to the string
	}
	if (num == std::string(buffer)) { // if the string number is the same as the buffer ...
		std::string::size_type sz; // alias of size_t
		value = std::stod(num, &sz); // ... set the value to the number value of the number string ...
	}
	else getUserNumber(value); // ... else, call the function again until we return a number
}

// EXAMPLE

int main() {
	double value; // number variable
	getUserNumber(value); // call the function that will set the number variable to the user's number
	std::cout << "Your number is " << value << "\n\n"; // print it
}