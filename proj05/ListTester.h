/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin University.
 * Students: Alec Twining and Michael Sisko
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testWriteToString();
	void testReadFromStream() const ;
	void testPrepend() ;
	void testInsertion();
	void testWriteToStream();
	void testInequality() const;
	void testReadFromString();
	void testGetIndexOf();
	void testRemove();

};

#endif /*LISTTESTER_H_*/






