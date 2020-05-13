/* array.cpp defines "C style" array operations
 * Name:	Michael Sisko
 * Date:	09/18/2019
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "array.h"
#include <fstream>

/*	This takes the value of the elements at their addresses
 *	the array, sums them together and returns the total.
 */
double sum(double *a, unsigned size) {
	double sum = 0.0;
	for (unsigned i = 0; i < size; i++, a++)
	{
		sum += *a;
	}
	return sum;
}

/*	This function reads the value from file and sets
 *	the original size of each array.
 */
void read(istream& in, double *a, unsigned size) {
	initialize(a, size);
	for (unsigned i = 0; i < size; i++, a++) {
		string getSize;
		double arraySize;
		getline(in, getSize);
		arraySize = atof( getSize.c_str() );
		*a = arraySize;
	}
}

/*	This function fills each array with the values from the file
 *	and stores them accordingly.
 */
void fill(const string& fileName, double *&a, unsigned &numValues) {
	delete [] a;
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	string getValues;
	getline(fin, getValues);
	numValues = atoi( getValues.c_str() );
	a = new double[numValues];

	read(fin, a, numValues);
	fin.close();
}

/*	This accepts an argument from the caller and resizes
 *	the array and passes the values from the old array
 *	into a temporary array, then a 'new' array is made and is
 *	passed the values from the temporary array until the
 *	breakout has been reached.
 */
void resize(double *&a, unsigned oldSize, unsigned newSize) {
	double *tempA = a;
	a = new double[newSize]();
	unsigned breakout = 0;
	newSize>oldSize? breakout=oldSize : breakout=newSize;
	for(unsigned i = 0; i < breakout; i++) {
		a[i] = tempA[i];
	}
	delete [] tempA;
}

/*	This function grabs the from array a1 and places it first
 *	in the new a3 array, and the following loop will pass array a2
 *	secondarily into the new array a3. After, both arrays a1 and a2
 *	are deleted to prevent memory leaking.
 *	This is a diagram with 'dummy' values to represent what occurs:
 *	BEFORE: 	a1 = { 1v1, 1v2, 1v3, 1v4 };		a2 = { 2v1, 2v2, 2v3 };
 *	AFTER:		a3 = { 1v1, 1v2, 1v3, 1v4, 2v1, 2v2, 2v3 };
 */
void concat(double *a1, unsigned size1, double *a2, unsigned size2, double *&a3, unsigned &size3) {
	size3 = size1 + size2;
	delete [] a3;
	a3 = new double[size3];
	for (unsigned i = 0; i < size3; i++ ) {
		i<size1? a3[i]=a1[i] : a3[i]=a2[i-size1];
	}
}

void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}

void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		

/*	This function grabs the sum from the sum function
 *	and divides it by the  amount of elements in the array
 *	and returns the average.
 */
double average(double *a, unsigned size) {
	double sum = 0.0;
	for (unsigned i = 0; i < size; i++, a++)
	{
		sum += *a;
	}
	return sum/size;
}

