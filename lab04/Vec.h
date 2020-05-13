/* Vec.h provides a simple vector class named Vec.
 * Student Name:	Michael Sisko
 * Date:			Sep 30, 2019
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cassert>
using namespace std;

template<class Item>
class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec<Item>(const Vec<Item>& original);
	Vec<Item>& operator=(const Vec<Item>& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec<Item>& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	const Item& operator[](unsigned index) const;
	Item& operator[](unsigned index);
	bool operator!=(const Vec<Item>& v2) const;
	void readFrom(const string& fileName);
	void writeTo(const string& fileName);
	Vec<Item> operator+(const Vec<Item>& v2) const;
	Vec<Item> operator-(const Vec<Item>& v2) const;
	unsigned operator*(const Vec<Item>& v2);
	virtual ~Vec();

private:
	unsigned mySize = 0;
	Item * 	 myArray = NULL;
	friend class VecTester;
};

template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	(size > 0)? myArray = new Item[size]() :
			myArray = NULL;
}

template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
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

template<class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
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

template<class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if ( mySize > index ) {
		myArray[index] = it;
	} else {
		throw range_error("Invalid Index.");
	}
}

template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if ( mySize > index ) {
		return myArray[index];
	} else {
		throw range_error("Invalid Index.");
	}
}

template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
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

template<class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
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

template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for ( unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << endl;
	}
}

template<class Item>
void Vec<Item>::readFrom(istream& in) {
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
template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("Vec subscript: bad index passed");
	}
	return myArray[index];
}

template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("Vec subscript: bad index passed");
	}
	return myArray[index];
}

// This function checks the equality of vector sizes
// then it checks the individual element equality
// WRITTEN BY: Michael Sisko
template<class Item>
bool Vec<Item>::operator!=(const Vec& v2) const {
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
template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v2) const {
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
template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v2) const {
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
template<class Item>
unsigned Vec<Item>::operator*(const Vec<Item>& v2) {
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
template<class Item>
void Vec<Item>::readFrom(const string& fileName) {
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
template<class Item>
void Vec<Item>::writeTo(const string& fileName) {
	ofstream fout( fileName.c_str() );
	assert( fout.is_open() );

	fout << mySize;
	for(unsigned i = 0; i < mySize; i++) {
		fout << '\n' << myArray[i];
	}
	fout.close();
}

#endif /*VEC_H_*/
