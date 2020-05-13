/*
 * List.cpp
 *
 *  Created on: Oct 8, 2019
 *      Author: mjs96
 */

#include "List.h"
#include <stdexcept>
using namespace std;

List::List() {
	myFirst = myLast = nullptr;
	mySize = 0;
}

List::Node::Node() {
	myItem = Item();
	myNext = nullptr;
}

List::Node::Node(Item it, Node* next) {
	myItem = it;
	myNext = next;
}

void List::getSize(unsigned mySize) const {

}

Item List::getFirst() {
	if (mySize == 0 || myFirst == nullptr) {
		throw underflow_error("Error, List size is 0 or myFirst = nullptr");
	} else {
		return myFirst->myItem;
	}
}

Item List::getLast() {
	if (mySize == 0 || myLast == nullptr) {
		throw underflow_error("Error, List size is 0 or myLast = nullptr");
	} else {
		return myLast->myItem;
	}
}

void List::append(const Item& it) {
	Node* newNode = new Node(it,NULL);
	if ( mySize == 0 ) {
		myFirst = newNode;
		myLast = newNode;
	} else {
		myLast->myNext = newNode;
		myLast = newNode;
	}
	mySize++;
}

List::~List() {
	delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
	myFirst = myLast = NULL; // clear myFirst and myLast (optional)
	mySize = 0;              // clear mySize (optional)
}

List::List(const List& original) {
	myFirst = myLast = NULL;		//  set pointers
	mySize = 0;						//   and size to 'empty' values
	Node* oPtr = original.myFirst;	//  start at the first node
	while (oPtr != NULL) {			//  while there are nodes to copy:
		append(oPtr->myItem);		//   append the item in that node
		oPtr = oPtr->myNext;		//   advance to next node
	}
}

List& List::operator=(const List &original) {
	if (&original != this) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
		Node* nPtr = original.myFirst;
		while (nPtr) {
			append(nPtr->myItem);
			nPtr = nPtr->myNext;
		}
	}
	return *this;
}




