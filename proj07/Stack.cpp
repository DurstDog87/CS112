/* Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name:
 * Date:
 */

//#include "Stack.h"

///* explicit-value constructor
// * Parameter: capacity, an unsigned value.
// * Precondition: capacity > 0.
// * Postcondition: mySize == 0 && myCapacity == capacity
// *              && myArray contains the address of a dynamic array of 'capacity' entries.
// */
//Stack::Stack(unsigned capacity) {
//   mySize = 0;
//   myCapacity = capacity;
//   myArray = new Item[capacity];
//}
//
///* copy constructor
// * Parameter: original, a Stack (const reference).
// * Postcondition: I am a copy of original.
// */
//Stack::Stack(const Stack& original) {
//	makeCopyOf(original);
//}
//
///* utility method containing code refactored from
// *  the copy constructor and operator=.
// * Parameter: original, a Stack (const reference).
// * Precondition: original.myCapacity > 0.
// * Postcondition: I am a copy of original.
// */
//void Stack::makeCopyOf(const Stack& original) {
//	myCapacity = original.myCapacity;
//	myArray = new Item[myCapacity];
//
//	for (unsigned i = 0; i < myCapacity; i++) {
//		myArray[i] = original.myArray[i];
//	}
//	mySize = original.mySize;
//}
//
///* destructor
// * Postcondition: myCapacity == 0 && mySize == 0
// *             && myArray has been deallocated.
// */
//Stack::~Stack() {
//	delete [] myArray;
//	myArray = NULL;
//	myCapacity = 0;
//	mySize = 0;
//}
//
///* assignment operator
// * Parameter: original, a Stack (const reference).
// * Postcondition: I am a copy of original
// *              && I have been returned.
// */
//Stack& Stack::operator=(const Stack& original) {
//	if (this != &original) {
//		delete [] myArray;
//		makeCopyOf(original);
//	}
//	return *this;
//}
//
//Item Stack::peekTop() const {
//    if ( isEmpty() ) {
//       throw StackException("peekTop()", "stack is empty");
//    }
//	return myArray[mySize-1];
//}
//
//void Stack::push(const Item& it) {
//    if ( isFull() ) {
//       throw StackException("push()", "stack is full");
//    }
//	myArray[mySize++] = it;
//}
//
//Item Stack::pop() {
//    if ( isEmpty() ) {
//       throw StackException("pop()", "stack is empty");
//    }
//	return myArray[--mySize];
//}
//
//unsigned Stack::getCapacity() const {
//	return myCapacity;
//}
//
//unsigned Stack::getSize() const {
//	return mySize;
//}
//
//void Stack::setCapacity(unsigned newCapacity) {
//	if (myCapacity != newCapacity) {
//		if ( newCapacity == 0 ) {
//			delete [] myArray;
//			myArray = NULL;
//			myCapacity = mySize = 0;
//		} else {
//			Item * newArray;
//			newArray = new Item[newCapacity]();
//			unsigned breakout = (myCapacity < newCapacity)? myCapacity : newCapacity;
//			for ( unsigned i = 0; i < breakout; i++) {
//				newArray[i] = myArray[i];
//			}
//			myCapacity = newCapacity;
//			delete [] myArray;
//			myArray = newArray;
//		}
//	}
//}









