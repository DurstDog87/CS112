/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name:
 * Date:
 */

#include "LinkedQueue.h"

LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirstPtr = myLastPtr = NULL;
}

LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirstPtr = myLastPtr = NULL;
	} else {
		myFirstPtr = new Node(original.getFirst(), NULL);
		Node * temp0 = original.myFirstPtr->myNextPtr;
		Node * temp1 = myFirstPtr;
		while (temp0 != NULL) {
			temp1->myNextPtr = new Node(temp0->myItem, NULL);
			temp1 = temp1->myNextPtr;
			temp0 = temp0->myNextPtr;
		}
		myLastPtr = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirstPtr;
	myFirstPtr = myLastPtr = NULL;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirstPtr;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}

Item LinkedQueue::getFirst() const {
	if ( isEmpty() ) {
		throw EmptyQueueException("getFirst()");
	}
	return myFirstPtr->myItem;
}

Item LinkedQueue::getLast() const {
	if ( isEmpty() ) {
		throw EmptyQueueException("getLast()");
	}
	return myLastPtr->myItem;
}

void LinkedQueue::append(const Item& it) {
	Node* myNodePtr = new Node(it,nullptr);
	if ( isEmpty() ) {
		myFirstPtr = myNodePtr;
	} else {
		myLastPtr->myNextPtr = myNodePtr;
	}
	mySize++;
	myLastPtr = myNodePtr;
}

Item LinkedQueue::remove() {
	if ( isEmpty() ) {
		throw EmptyQueueException("remove()");
	}
	Item result = myFirstPtr->myItem;
	myFirstPtr = myFirstPtr->myNextPtr;
	mySize--;
	return result;
}








