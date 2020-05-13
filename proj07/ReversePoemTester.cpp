/*
 * ReversePoemTester.cpp
 *
 *  Created on: Nov 11, 2019
 *      Author: mjs96
 */

#include "ReversePoem.h"
#include "ReversePoemTester.h"

void ReversePoemTester::runTests() {
	cout << "\nTesting ReversePoem class..." << endl;
	testConstructor();
	testGetTitle();
	testGetAuthor();
	testGetBody();
	testGetBodyReversed();
	cout << "All tests passed!" << endl;
}

void ReversePoemTester::testConstructor() {
	cout << "- Testing constructor... " << flush;

	// valid filename
	ReversePoem rp0("poems/poemTest0.txt");
	cout << " 0 " << flush;

	// valid filename
	ReversePoem rp1("poems/poemTest1.txt");
	cout << " 1 " << flush;

	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetTitle() {
	cout << "- Testing getTitle()... " << flush;

	// checks title
	ReversePoem rp0("poems/poemTest0.txt");
	assert( rp0.getTitle() == "testTitle T1" );
	cout << " 0 " << flush;

	// checks title
	ReversePoem rp1("poems/poemTest1.txt");
	assert( rp1.getTitle() == "testTitle T2" );
	cout << " 1 " << flush;

	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetAuthor() {
	cout << "- Testing getAuthor()... " << flush;

	// checks author
	ReversePoem rp0("poems/poemTest0.txt");
	assert( rp0.getAuthor() == "testAuthor A1" );
	cout << " 0 " << flush;

	// checks author
	ReversePoem rp1("poems/poemTest1.txt");
	assert( rp1.getAuthor() == "testAuthor A2" );
	cout << " 1 " << flush;

	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetBody() {
	cout << "- Testing getBody()... " << flush;

	// checks body
	ReversePoem rp0("poems/poemTest0.txt");
	assert( rp0.getBody() == "L1: AAA\nL2: BBB\nL3: CCC\n" );
	cout << " 0 " << flush;

	// checks body
	ReversePoem rp1("poems/poemTest1.txt");
	assert( rp1.getBody() == "L1: DDD\nL2: EEE\nL3: FFF\nL4: GGG\nL5: HHH\n" );
	cout << " 1 " << flush;

	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetBodyReversed() {
	cout << "- Testing getBodyReversed()... " << flush;

	// checks body reversed
	ReversePoem rp0("poems/poemTest0.txt");
	assert( rp0.getBodyReversed() == "L3: CCC\nL2: BBB\nL1: AAA\n" );
	cout << " 0 " << flush;

	// checks body reversed
	ReversePoem rp1("poems/poemTest1.txt");
	assert( rp1.getBodyReversed() == "L5: HHH\nL4: GGG\nL3: FFF\nL2: EEE\nL1: DDD\n" );
	cout << " 1 " << flush;

	cout << " Passed!" << endl;
}









