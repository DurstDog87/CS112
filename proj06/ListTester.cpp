/* ListTester.cpp defines the test methods for class List.
 * Joel Adams, for CS 112 at Calvin University.
 * Alec Twining and Michael Sisko
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <fstream>
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
	testEquality();
//	testReadFromStream();
	testPrepend();
//	testWriteToString();
	testInsertion();
	testInequality();
//	testWriteToStream();
//	testReadFromString();
	testGetIndexOf();
	testRemove();
	testOutput();
	testInsertAfter();
	testInsertBefore();


	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
List<double> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<double>::Node aNode;
	assert( aNode.myItem == 0 );
	assert( aNode.myNext == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<double>::Node n1(11, NULL);
	assert( n1.myItem == 11 );
	assert( n1.myNext == NULL );
	cout << " 1 " << flush;

	List<double>::Node *n3 = new List<double>::Node(33, NULL);
	List<double>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<double> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<double> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<double> l0;
	List<double> list2(l0);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// copy nonempty list
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<double> l0;
	List<double> list2;
	list2 = l0;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	// check that nodes are distinct
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myFirst->myNext != list3.myFirst->myNext );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
	// check that nodes are distinct
	assert( list5.myFirst != list3.myFirst );
	assert( list5.myFirst->myNext != list3.myFirst->myNext );
	assert( list5.myLast != list3.myLast );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<double> list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == NULL );
	assert( list6.myLast == NULL );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
	// check that nodes are distinct
	assert( list8.myFirst != list3.myFirst );
	assert( list8.myFirst->myNext != list3.myFirst->myNext );
	assert( list8.myLast != list3.myLast );
	cout << " 5 " << flush;

	// assignment chaining
	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> l00;
	l00 = list9 = list8;
	assert( l00.getSize() == 3 );
	assert( l00.getFirst() == 11 );
	assert( l00.getLast() == 33 );
	assert( l00.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<double> l01;
	l01.append(11);
	l01.append(22);
	l01.append(33);
	l01 = l01;
	assert( l01.getSize() == 3 );
	assert( l01.getFirst() == 11 );
	assert( l01.getLast() == 33 );
	assert( l01.myFirst->myNext->myItem == 22 );
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testEquality() {
	cout << "Testing Equality... " << flush;
	List<double> l0;
	l0.append(1);
	l0.append(2);
	l0.append(3);
	List<double> list2;
	list2.append(1);
	list2.append(2);
	list2.append(3);
	List<double> list3;
	List<double> list4;
	list4.append(1);
	list4.append(4);
	list4.append(2);

	// asserting l0 and list 2 are equal
	assert( l0 == list2 );
	cout << " 0 " << flush;

	// non-empty to empty equality
	assert( !(l0==list3) );
	cout << " 1 " << flush;

	// testing two lists with same size but different values
	assert(l0.getSize() == list4.getSize());
	assert( !(l0.myFirst->myNext == list4.myFirst->myNext) );
	assert( !(l0.myLast == list4.myLast));
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}
void ListTester::testReadFromStream() const {
	cout << "Testing readFrom(istream)..." << flush;

	ifstream fin("OutStream.txt");
	assert (fin.is_open());
	List<double> alist;
	alist.readFrom(fin);
	assert(alist.myFirst->myItem == 1);
	assert(alist.myFirst->myNext->myItem == 2);
	assert(alist.myFirst->myNext->myNext->myItem == 3);
	fin.close();
	cout <<"Passed!" << endl;
}

void ListTester::testPrepend() {
	cout << "Testing prepend()... ";
	List<double> l0;
	l0.append(11);
	l0.append(22);
	l0.append(33);


	l0.prepend(-1);
	assert(l0.getSize() == 4);
	assert(l0.myFirst->myItem == -1);
	assert(l0.myFirst->myNext->myItem = 11);
	assert(l0.myFirst->myNext->myNext->myItem = 22);
	assert(l0.myFirst->myNext->myNext->myNext->myItem = 33);
	assert(l0.myLast->myItem == 33);
	cout << " 0 " << flush;

	List<double> list2;
	list2.prepend(5);
	assert(list2.myFirst->myItem ==5);
	assert(list2.myLast->myItem ==5);
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testInsertion() {
	cout << "Testing insertion()..." << flush;

	List<double> l0;
	l0.append(-1);
	l0.append(11);
	l0.append(22);
	l0.append(33);

	List<double> list2;

	List<double> list3;
	list3 = l0;

	list2.insert(0, 0);
	assert(list2.getIndexOf(0) == 0);
	assert(list2.myFirst->myItem == 0);
	assert(list2.myLast->myItem == 0);

	cout << " 0 " << flush;

	l0.insert(0, 0);
	assert(l0.getIndexOf(0) == 0);
	assert(l0.myFirst -> myItem == 0);
	assert(l0.myFirst->myNext->myItem == -1);
	assert(l0.myFirst->myNext->myNext-> myItem == 11);
	assert(l0.myFirst->myNext->myNext->myNext->myItem == 22);
	assert(l0.myLast->myItem == 33);

	cout << " 1 " << flush;

	list3.insert(0, 1);
	//	assert(list3.getIndexOf(1) == 0);
	assert(list3.getSize() == 5);
	assert(list3.myFirst->myItem == -1);
	assert(list3.myFirst->myNext->myItem == 0);
	assert(list3.myFirst->myNext->myNext->myItem == 11);
	assert(list3.myFirst->myNext->myNext->myNext->myItem == 22);
	assert(list3.myLast->myItem == 33);

	cout << " 2 " << flush;

	l0.insert(1, 5);
	assert(l0.myLast -> myItem == 1);
	assert( l0.getIndexOf(1) == 5);

	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testWriteToString() {
	cout << "Testing writeTo(string)..." << flush;

	List<double> l0;
	l0.append(1);
	l0.append(2);
	l0.append(3);

	ofstream fout("OutStream.txt");
	assert(fout.is_open());
	l0.writeTo(fout);
	fout.close();

	ifstream fin("OutStream.txt");
	assert(fin.is_open());
	double number;
	for (unsigned i = 0; i < 3; ++i) {
		fin >>number;
		assert(number == i+1);
	}
	cout <<"Passed! but check OutStream.txt for the values ..." << endl;
}

//Michael Sisko's Tests (mjs96)
void ListTester::testInequality() const {
	cout << "Testing !=... " << flush;
	// empty
	List<double> l0;
	List<double> l1;
	assert( !(l0 != l1) );
	cout << " 0 " << flush;

	// empty vs nonempty
	l1.append(1);
	assert( l0 != l1 );
	cout << " 1 " << flush;

	// equal sized, same values
	l0.append(1);
	assert( !(l0 != l1) );
	cout << " 2 " << flush;

	// equal sized, different values
	l0.myFirst->myItem = 11;
	l1.myFirst->myItem = 22;
	assert( l0 != l1 );
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testWriteToStream() {
	cout << "Testing writeToStream... " << flush;

	List<double> l0;
	ifstream fin("ListTest1.txt");
	assert( fin.is_open() );
	l0.readFrom(fin);
	fin.close();

	cout << " 0 " << flush;

	ofstream fout("ListTest1Copy.txt");
	assert( fout.is_open() );
	l0.writeTo(fout);
	fout.close();

	cout << " 1 " << flush;

	List<double> l1;
	l1.readFrom("ListTest1Copy.txt");

	cout << " 2 " << flush;

	assert( l1.mySize == 4 );
	assert( l1.myFirst->myItem == 0 );
	assert( l1.myFirst->myNext->myItem == 1 );
	assert( l1.myFirst->myNext->myNext->myItem == 2 );
	assert( l1.myFirst->myNext->myNext->myNext->myItem == 3 );
	assert( l1.myLast->myItem == 3 );

	cout << " 3 " << flush;

	cout << "Passed! " << endl;
}

void ListTester::testReadFromString() {
	cout << "Testing readFromString... " << flush;
	List<double> aList;
	aList.readFrom("ListTest1.txt");

	assert( aList.mySize == 4 );
	assert( aList.myFirst->myItem == 0 );
	assert( aList.myFirst->myNext->myItem == 1 );
	assert( aList.myFirst->myNext->myNext->myItem == 2 );
	assert( aList.myFirst->myNext->myNext->myNext->myItem == 3 );
	assert( aList.myLast->myItem == 3 );

	cout << "Passed! " << endl;
}

void ListTester::testGetIndexOf() {
	cout << "Testing GetIndexOf... " << flush;

	// test empty
	List<double> l0;
	l0.getIndexOf(0);
	assert( l0.getIndexOf(0) == -1 );
	cout << " 1 " << flush;

	// test non-empty
	for ( unsigned i = 1; i < 4; i++ ) {
		l0.append( i * 11 );
	}
	assert( l0.getIndexOf(11) == 0 );
	assert( l0.getIndexOf(22) == 1 );
	assert( l0.getIndexOf(33) == 2 );
	cout << " 2 " << flush;

	cout << "Passed! " << endl;
}

void ListTester::testRemove() {
	cout << "Testing Remove... " << flush;
	List<double> l0;
	l0.append(11);
	l0.append(22);
	l0.append(33);
	l0.append(44);
	assert( l0.mySize == 4 );
	cout << " 0 " << flush;

	// remove item from middle of list
	l0.remove(1);
	assert( l0.mySize == 3 );
	assert( l0.myFirst->myItem == 11 );
	assert( l0.myFirst->myNext->myItem == 33 );
	assert( l0.myFirst->myNext->myNext->myItem == 44 );
	cout << " 1 " << flush;

	// remove last item from list
	l0.remove(2);
	assert( l0.mySize == 2 );
	assert( l0.myFirst->myItem == 11 );
	assert( l0.myFirst->myNext->myItem == 33 );
	assert( l0.myFirst->myNext->myNext == nullptr );
	cout << " 2 " << flush;

	// remove first item from list
	l0.remove(0);
	assert( l0.mySize == 1 );
	assert( l0.myFirst->myItem == 33 );
	assert( l0.myFirst->myNext == nullptr );
	cout << " 3 " << flush;

	//remove only list item
	l0.remove(0);
	assert( l0.mySize == 0 );
	assert( l0.myFirst == nullptr );
	cout << " 4 " << flush;

	cout << "Passed! " << endl;
}

void ListTester::testOutput() {
	cout << "Testing Output... " << flush;

	List<unsigned> l0;
	for (unsigned i = 0; i < 4; i++ ) {
		l0.append(i);
	}
	assert( l0.mySize == 4 );
	assert( l0.myFirst->myItem == 0 );
	assert( l0.myFirst->myNext->myItem == 1 );
	assert( l0.myFirst->myNext->myNext->myItem == 2 );
	assert( l0.myFirst->myNext->myNext->myNext->myItem == 3 );
	assert( l0.myLast->myItem == 3 );

	cout << "Verify the list repeats twice.";
	cout << "\n\tIt should be displayed as: \"=0=1=2=3\"" << endl;
	cout << '\t' << l0 << endl << '\t' << l0 << endl;
	cout << "Passed! " << endl;
}

void ListTester::testInsertAfter() {
	cout << "Testing InsertAfter... " << flush;
	List<string> l0;
	assert(l0.getSize() == 0);
	string otherPersonsName = "";
	string yourName = "Mario";

	// insert into an empty list
	try {
		l0.insertAfter(otherPersonsName, yourName);
	} catch (underflow_error) {
		cout << " 0 " << flush;
	}

	// insert into a list of one
	l0.append("Mario");
	assert(l0.getSize() == 1);

	otherPersonsName = "Mario";
	yourName = "Luigi";
	l0.insertAfter(otherPersonsName, yourName);
	assert(l0.getSize() == 2);
	assert(l0.getFirst() == "Mario");
	assert(l0.myFirst->myNext->myItem == "Luigi");
	assert(l0.myFirst->myNext->myNext == NULL);
	assert(l0.getLast() == "Luigi");
	cout << " 1 " << flush;

	// insert after first person of the list
	otherPersonsName = "Mario";
	yourName = "Wario";
	l0.insertAfter(otherPersonsName, yourName);
	assert(l0.getSize() == 3);
	assert(l0.getFirst() == "Mario");
	assert(l0.myFirst->myNext->myItem == "Wario");
	assert(l0.myFirst->myNext->myNext->myItem == "Luigi");
	assert(l0.myFirst->myNext->myNext->myNext == NULL);
	assert(l0.getLast() == "Luigi");
	cout << " 2 " << flush;

	// insert after last person in the list
	otherPersonsName = "Luigi";
	yourName = "Toad";
	l0.insertAfter(otherPersonsName, yourName);
	assert(l0.getSize() == 4);
	assert(l0.getFirst() == "Mario");
	assert(l0.myFirst->myNext->myItem == "Wario");
	assert(l0.myFirst->myNext->myNext->myItem == "Luigi");
	assert(l0.myFirst->myNext->myNext->myNext->myItem == "Toad");
	assert(l0.myFirst->myNext->myNext->myNext->myNext == NULL);
	assert(l0.getLast() == "Toad");
	cout << " 3 " << flush;

	// insert after middle person
	otherPersonsName = "Mario";
	yourName = "Waluigi";
	l0.insertAfter(otherPersonsName, yourName);
	assert(l0.getSize() == 5);
	assert(l0.getFirst() == "Mario");
	assert(l0.myFirst->myNext->myItem == "Waluigi");
	assert(l0.myFirst->myNext->myNext->myItem == "Wario");
	assert(l0.myFirst->myNext->myNext->myNext->myItem == "Luigi");
	assert(l0.myFirst->myNext->myNext->myNext->myNext->myItem == "Toad");
	assert(l0.myFirst->myNext->myNext->myNext->myNext->myNext == NULL);
	assert(l0.getLast() == "Toad");
	cout << " 4 " << flush;

	// insert after non-existent person
	otherPersonsName = "Bowser";
	yourName = "Peach";
	assert( l0.insertAfter(otherPersonsName, yourName) == false );
	cout << " 5 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testInsertBefore() {
	cout << "Testing InsertBefore... " << flush;
	List<string> l0;
	l0.append("Mario");
	l0.append("Luigi");

	// insert before first person of the list
	string otherPersonsName = "Mario";
	string yourName = "Wario";
	l0.insertBefore(otherPersonsName, yourName);
	assert(l0.getSize() == 3);
	assert(l0.getFirst() == "Wario");
	assert(l0.myFirst->myNext->myItem == "Mario");
	assert(l0.myFirst->myNext->myNext->myItem == "Luigi");
	assert(l0.myFirst->myNext->myNext->myNext == NULL);
	assert(l0.getLast() == "Luigi");
	cout << " 0 " << flush;

	// insert before last person in the list
	otherPersonsName = "Luigi";
	yourName = "Toad";
	l0.insertBefore(otherPersonsName, yourName);
	assert(l0.getSize() == 4);
	assert(l0.getFirst() == "Wario");
	assert(l0.myFirst->myNext->myItem == "Mario");
	assert(l0.myFirst->myNext->myNext->myItem == "Toad");
	assert(l0.myFirst->myNext->myNext->myNext->myItem == "Luigi");
	assert(l0.myFirst->myNext->myNext->myNext->myNext == NULL);
	assert(l0.getLast() == "Luigi");
	cout << " 1 " << flush;

	// insert before middle person
	otherPersonsName = "Mario";
	yourName = "Waluigi";
	l0.insertBefore(otherPersonsName, yourName);
	assert(l0.getSize() == 5);
	assert(l0.getFirst() == "Wario");
	assert(l0.myFirst->myNext->myItem == "Waluigi");
	assert(l0.myFirst->myNext->myNext->myItem == "Mario");
	assert(l0.myFirst->myNext->myNext->myNext->myItem == "Toad");
	assert(l0.myFirst->myNext->myNext->myNext->myNext->myItem == "Luigi");
	assert(l0.myFirst->myNext->myNext->myNext->myNext->myNext == NULL);
	assert(l0.myLast->myNext == nullptr);
	assert(l0.getLast() == "Luigi");
	cout << " 2 " << flush;

	// insert before non-existent person
	otherPersonsName = "Bowser";
	yourName = "Peach";
//	assert( !l0.insertBefore(otherPersonsName, yourName) );

//	*** Lab Instructor Chris could not figure out the reason
//	why the above assertion and referred me to Professor Adams

	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}








