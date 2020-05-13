/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name:	Michael Sisko
 * Date:			Sep 30, 2019
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include "Vec.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

#include <cassert>
using namespace std;

Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

Vec::Vec(unsigned size) {
	mySize = size;
	(size > 0)? myArray = new Item[size]() :
			myArray = NULL;
}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if ( original.mySize > 0 ) {
		myArray = new Item[mySize]();
		for ( unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = NULL;
	}
}

Vec::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

Vec& Vec::operator=(const Vec& original) {
	if ( mySize != original.mySize ) {
		if ( mySize > 0) {
			delete [] myArray;
			mySize = 0;
			myArray = NULL;
		}
		if ( original.mySize > 0 )  {
			myArray = new Item[original.mySize]();
		}
		mySize = original.mySize;
	}
	for ( unsigned i = 0; i < mySize; i++) {
		myArray[i] = original.myArray[i];
	}
	return *this;
}

unsigned Vec::getSize() const {
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it) {
	if ( mySize > index ) {
		myArray[index] = it;
	} else {
		throw range_error("Invalid Index.");
	}
}

Item Vec::getItem(unsigned index) const {
	if ( mySize > index ) {
		return myArray[index];
	} else {
		throw range_error("Invalid Index.");
	}
}

void Vec::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if ( newSize == 0 ) {
			delete [] myArray;
			mySize = 0;
			myArray = NULL;
		} else {
			Item * newArray;
			newArray = new Item[newSize]();
			unsigned breakout = (mySize < newSize)? mySize : newSize;
			for ( unsigned i = 0; i < breakout; i++) {
				newArray[i] = myArray[i];
			}
			mySize = newSize;
			delete [] myArray;
			myArray = newArray;
		}
	}
}

bool Vec::operator==(const Vec& v2) const {
	if ( mySize == v2.mySize ) {
		for ( unsigned i = 0; i < mySize; i++ ) {
			if ( myArray[i] != v2.myArray[i] ) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void Vec::writeTo(ostream& out) const {
	for ( unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << endl;
	}
}

void Vec::readFrom(istream& in) {
	if ( mySize > 0 ) {
		for ( unsigned i = 0; i < mySize; i++) {
			in >> myArray[i];
		}
	} else {
		myArray = NULL;
	}
}

// This function takes index as an argument
// and checks for bad index passes such as
// index == mySize or index > mySize
// WRITTEN BY: Michael Sisko
Item& Vec::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("Vec subscript: bad index passed");
	}
	return myArray[index];
}

// This function takes index as an argument
// and checks for bad index passes such as
// index == mySize or index > mySize
// WRITTEN BY: Michael Sisko
const Item& Vec::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("Vec subscript: bad index passed");
	}
	return myArray[index];
}

// This function checks the equality of vector sizes
// then it checks the individual element equality
// WRITTEN BY: Michael Sisko
bool Vec::operator!=(const Vec& v2) const {
	if ( mySize == v2.mySize ) {
		for ( unsigned i = 0; i < mySize; i++ ) {
			if ( myArray[i] != v2.myArray[i] ) {
				return true;
			}
		}
		return false;
	}
	return true;
}

// This function adds individual elements together and puts them in
// vector temp.
// WRITTEN BY: Michael Sisko
Vec Vec::operator+(const Vec& v2) const {
	if (mySize != v2.mySize) {
		throw std::invalid_argument("Vectors are not the same size.");
	}
	Vec temp(mySize);
	for( unsigned i=0; i<mySize; i++) {
		temp.setItem(i, myArray[i] + v2.getItem(i));
	}
	return temp;
}

// This function subtracts individual elements and puts them in
// vector temp.
// WRITTEN BY: Jared Mulder
Vec Vec::operator-(const Vec& v2) const {
	if (mySize != v2.mySize) {
		throw std::invalid_argument("Vectors are not the same size.");
	}
	Vec temp(mySize);
	for( unsigned i=0; i<mySize; i++) {
		temp.setItem(i, myArray[i] - v2.getItem(i));
	}
	return temp;
}

// This function multiplies individual elements together
// and puts them in vector temp.
// WRITTEN BY: Jared Mulder
unsigned Vec::operator*(const Vec& v2) {
	if (mySize != v2.mySize) {
		throw invalid_argument("vectors are different sizes");// WRITTEN BY:
	}
	Vec temp(mySize);

	for (unsigned i = 0; i < mySize; ++i) {
		temp.setItem(i, myArray[i] * v2.myArray[i]);
	}
	double sum;
	for (unsigned i = 0; i < mySize; ++i) {
		sum += temp.getItem(i);
	}
	return sum;
}

// This function reads from the files "vecTest1.txt"
// and "vecTest2.txt"
// WRITTEN BY: Michael Sisko
void Vec::readFrom(const string& fileName) {
	delete [] myArray;
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	fin >> mySize;
	myArray = new Item[mySize]();

	for(unsigned i = 0; i < mySize; i++) {
		fin >> myArray[i];
	}
	fin.close();
}

// This function writes to the files "vecTest1.txt"
// and "vecTest2.txt"
// WRITTEN BY: Jared Mulder
void Vec::writeTo(const string& fileName) {
	ofstream fout( fileName.c_str() );
	assert( fout.is_open() );

	fout << mySize;
	for(unsigned i = 0; i < mySize; i++) {
		fout << '\n' << myArray[i];
	}
	fout.close();
}
