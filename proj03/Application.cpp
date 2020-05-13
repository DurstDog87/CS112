/*
 * Application.cpp
 *
 *  Created on: Sep 30, 2019
 *      Author: mjs96
 */

#include "Vec.h"
#include "VecTester.h"
#include "Application.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>

using namespace std;

Application::Application() {
// Initialize Variables
	string answer = "";
	unsigned mySize;
	unsigned input;
// Prompt user for Dimension size
	cout << "Enter Vector size: ";
	cin >> mySize;
// Initialize Vectors
	Vec userInput(mySize);
	Vec finalPosition(mySize);
	while (true) {
		for (unsigned i = 0; i<mySize; i++) {
// Prompt user for Element Values
			cout << "Enter Vector element " << i+1 << ": ";
			cin >> input;
			userInput.setItem(i, input);
		}
// Checks if user wants to enter another vector
		cout << "Enter another Vector? ( y / n ): ";
		cin >> answer;
// Sums user inputs for every loop until break;
		finalPosition = finalPosition + userInput;
		if ( answer == "n" ) { break; }
	}
// Displays final position to user
	cout << "Final position: {";
	for (unsigned i = 0; i<mySize; i++) {
		cout << finalPosition.getItem(i);
		if ( i != mySize-1 ) { cout << ", "; }
	}
	cout << "}" << endl;
}
