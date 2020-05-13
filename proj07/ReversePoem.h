/*
 * ReversePoem.h
 *
 *  Created on: Nov 11, 2019
 *      Author: mjs96
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include "Stack.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

class ReversePoem {
public:
	ReversePoem(const string& poemFile);
	// Getters return respective strings
	string getTitle() const { return myTitle; }
	string getAuthor() const { return myAuthor; }
	string getBody() const { return myBody; }
	string getBodyReversed() const { return myBodyReversed; }

private:
	// Instance variables initalized to null
	string myTitle = "";
	string myAuthor = "";
	string myBody = "";
	string myBodyReversed = "";
	friend class ReversePoemTester;
};

#endif /* REVERSEPOEM_H_ */









