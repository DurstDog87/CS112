/* tester.cpp drives the testing of the Queue classes.
 * Joel Adams, for CS 112 at Calvin University.
 */

 #include "ArrayQueueTester.h"
 #include "PalindromeTester.h"
 
 int main() {
 	ArrayQueueTester aqt;
 	aqt.runTests();
 	PalindromeTester pdt;
 	pdt.runTests();

 	string fileNameIn;
	string fileNameOut;
 	cout << "Welcome to the Palindrome tester!" << endl;

 	cout << "Please enter an input file: " << flush;
 	cin >> fileNameIn;
 	cout << "Please enter an output file: " << flush;
 	cin >> fileNameOut;

 	Palindrome p0(fileNameIn, fileNameOut);
 	p0.detectPalindromes();

 	cout << "Operation Complete! please see: " << fileNameOut;
 	cout << " for the results!" << endl;
 }









