/*
 * PalindromeDetectorTester.cpp
 *
 *  Created on: Nov 12, 2019
 *      Author: mjs96
 */

#include "Palindrome.h"
#include "PalindromeTester.h"

void PalindromeTester::runTests() {
	cout << "Testing class Palindrome..." << endl;
	testPalindrome();
	cout << "All tests passed!\n" << endl;
}

void PalindromeTester::testPalindrome() {
	cout << "- testing detectPalindromes... " << flush;

	Palindrome p0("pTestIn.txt","pTestOut.txt");
	p0.detectPalindromes();
	string outLine;
	ifstream fin( "pTestOut.txt" );
	cout << " 0 " << flush;

	// empty case
	getline(fin,outLine);
	assert( outLine == "");
	cout << " 1 " << flush;

	// actual palindromes
	getline(fin,outLine);
	assert( outLine == "Madam, I'm Adam. ***");
	cout << " 2a " << flush;
	getline(fin,outLine);
	assert( outLine == "A man, a plan, a canal, Panama! ***");
	cout << " 2b " << flush;
	getline(fin,outLine);
	assert( outLine == "Never Odd Or Even! ***");
	cout << " 2c " << flush;

	// non-palindromes
	getline(fin,outLine);
	assert( outLine == "King, are you glad you are king?");
	cout << " 3a " << flush;
	getline(fin,outLine);
	assert( outLine == "Night after night");
	cout << " 3b " << flush;
	getline(fin,outLine);
	assert( outLine == "Fall leaves after leaves fall");
	cout << " 3c " << flush;
	fin.close();

	cout << " Passed!" << endl;
}









