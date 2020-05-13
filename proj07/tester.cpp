/* tester.cpp is a "driver" to run the tests in the StackTester class.
 * Joel Adams, for CS 112 at Calvin University.
 */

#include "StackTester.h"
#include "ReversePoemTester.h"
#include "ReversePoem.h"

#include <iostream>
using namespace std;

int main() {
	StackTester st;
	st.runTests();
	ReversePoemTester rpt;
	rpt.runTests();

	cout << "\nEnter the name of the poem file: ";
	string poemFile;
	cin >> poemFile;

	ReversePoem reversePoem(poemFile);
	cout << '\n' << reversePoem.getTitle() << "\n"
			<< reversePoem.getAuthor() << "\n"
			<< "\n*** Top-To-Bottom ***\n\n"
			<< reversePoem.getBody()
			<< "\n*** Bottom-To-Top ***\n\n"
			<< reversePoem.getBodyReversed()
			<< flush;
}









