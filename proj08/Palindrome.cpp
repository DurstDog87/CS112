/*
 * Palindrome.cpp
 *
 *  Created on: Nov 12, 2019
 *      Author: mjs96
 */

#include "Stack.h"
#include "Palindrome.h"

/* Palindrome Constructor
 * @param:			fileNameIn, a string
 * @param:			fileNameOut, a string
 * Precondition:	fileIn and fileOut are empty strings
 * Postcondition:	fileIn holds value of fileNameIn
 * Postcondition:	fileOut holds value of fileNameOut
 * AUTHORED BY:		Michael Sisko
 */
Palindrome::Palindrome( string fileNameIn, string fileNameOut  ) {
	fileIn = fileNameIn;
	fileOut = fileNameOut;
}

/* Palindrome Detector
 * @param:			none
 * Precondition:	none
 * Postcondition:	fileIn has been evaluated
 * Postcondition:	fileOut has been written to
 * AUTHORED BY:		Michael Sisko
 */
void Palindrome::detectPalindromes() {
	ifstream fin( fileIn.c_str() );
	assert( fin.is_open() );
	ofstream fout( fileOut.c_str() );
	assert( fout.is_open() );
	string currLine;
	while ( fin.good() ) {
		getline(fin,currLine);
		fout << currLine;
		if ( isPalindrome(currLine) ) {
			fout << " ***";
		}
		fout << '\n';
	}
	fin.close();
	fout.close();
}

/* Bool isPalindrome()
 * @param:			str, a string
 * Precondition:	str holds a line of fileIn
 * Postcondition:	str has been evaluated
 * Postcondition:	returns true or false
 * AUTHORED BY:		Michael Sisko
 */
bool Palindrome::isPalindrome(const string& str) const {
	if ( str.length() == 0 ) {
		return false;
	}
	Stack<char> s0(1);
	ArrayQueue<char> aq0(1);
	for (unsigned i=0; i < str.length(); ++i) {
		if ( isalpha(str[i]) ) {
			try {
				s0.push( tolower(str[i]) );
				aq0.append( tolower(str[i]) );
			} catch (StackException& se) {
				s0.setCapacity(2*s0.getCapacity());
				aq0.setCapacity(2*aq0.getCapacity());
				s0.push( tolower( str[i] ) );
				aq0.append( tolower( str[i] ) );
			}
		}
	}
	while ( !s0.isEmpty() ) {
		char s0char = s0.pop();
		char aq0char = aq0.remove();
		if ( s0char != aq0char ) {
			return false;
		}
	}
	return true;
}

