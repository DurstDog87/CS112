/*
 * PalindromeDetector.h
 *
 *  Created on: Nov 12, 2019
 *      Author: mjs96
 */

#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include "Stack.h"
#include "ArrayQueue.h"
using namespace std;

#ifndef PALINDROME_H_
#define PALINDROME_H_

class Palindrome {
public:
	Palindrome(string fileNameIn, string fileNameOut);
	void detectPalindromes();
	bool isPalindrome(const string& str) const;
private:
	string fileIn = "";
	string fileOut = "";
	friend class PalindromeTester;
};

#endif /* PALINDROME_H_ */
