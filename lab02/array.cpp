/* array.cpp defines "C style" array operations
 * Name: Michael Sisko
 * Date: 9/17/2019
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */
 
#include "array.h"

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

double average(double *a, unsigned size) {
	double sum = 0.0;
	for (unsigned i = 0; i < size; i++, a++)
	{
		sum += *a;
	}
	return sum/size;
}
