/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Michael Sisko
 * Date:         11/19/2019
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
using namespace std;

template<class Item>

class BST {
public:
	BST();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;
	void insert( const Item& it );
	bool contains( const Item& it ) const;
	void traverseInorder();
	void traversePreorder();
	void traversePostorder();
	unsigned getHeight() const;

private:
	struct Node {
		Node(const Item& it);
		virtual ~Node();
		void nodeInsert( const Item& it );
		bool nodeContains( const Item& it ) const;
		void traverseInorder();
		void traversePreorder();
		void traversePostorder();
		virtual void processItem();
		unsigned nodeGetHeight() const;

		Item myItem;
		Node* myLeft;
		Node* myRight;
	};

	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

template<class Item>
BST<Item>::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

template<class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

template<class Item>
BST<Item>::Node::Node(const Item& it) {
	myItem = it;
	myLeft = NULL;
	myRight = NULL;
}

template<class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

template<class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

template<class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

template<class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

template<class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

template<class Item>
void BST<Item>::Node::processItem() {
	cout << ' ' << myItem;
}

template<class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

/* BST Insertion Method
 * @param:			it, an Item
 * Precondition:	none
 * Postcondition:	myRoot creates a new Node containing 'it'
 * Postcondition:	myRoot calls nodeInsert for 'it'
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
void BST<Item>::insert( const Item& it ) {
	if ( myRoot == nullptr ) {
		myRoot = new Node(it);
	} else {
		myRoot->nodeInsert(it);
	}
	myNumItems++;
}


/* BST Node Insertion Method
 * @param:			it, an Item
 * Precondition:	none
 * Postcondition:	myLeft creates a new Node containing 'it'
 * Postcondition:	myLeft recursively calls nodeInsert for 'it'
 * Postcondition:	myRight creates a new Node containing 'it'
 * Postcondition:	myRight recursively calls nodeInsert for 'it'
 * Postcondition:	nodeInsert() throws an Exception
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
void BST<Item>::Node::nodeInsert( const Item& it ) {
	if ( it < myItem ) {
		if ( myLeft == nullptr ) {
			myLeft = new Node(it);
		} else {
			myLeft->nodeInsert(it);
		}
	} else if ( it > myItem ) {
		if ( myRight == nullptr ) {
			myRight = new Node(it);
		} else {
			myRight->nodeInsert(it);
		}
	} else {
		throw Exception("Node::insert()","item is preexisting!");
	}
}


/* BST Contains Method
 * @param:			it, an Item
 * Precondition:	none
 * Postcondition:	returns false if no items exist
 * Postcondition:	myRoot calls nodeContains for 'it'
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
bool BST<Item>::contains(const Item& it) const {
	if ( myRoot == nullptr ) {
		return false;
	} else {
		return myRoot->nodeContains(it);
	}
}


/* BST Node Insertion Method
 * @param:			it, an Item
 * Precondition:	none
 * Postcondition:	if myLeft is empty, returns false
 * Postcondition:	myLeft recursively calls nodeContains for 'it'
 * Postcondition:	if myRight is empty, returns false
 * Postcondition:	myRight recursively calls nodeContains for 'it'
 * Postcondition:	if 'it' is equal to myItem, returns true
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
bool BST<Item>::Node::nodeContains( const Item& it ) const {
	if ( it < myItem ) {
		if ( myLeft == nullptr ) {
			return false;
		}
		return myLeft->nodeContains(it);
	} else if (it > myItem ) {
		if ( myRight == nullptr ) {
			return false;
		}
		return myRight->nodeContains(it);
	} else {
		return true;
	}
}

/* BST Height Getter Method
 * @param:			none
 * Precondition:	none
 * Postcondition:	returns 0 if no items exist
 * Postcondition:	myRoot calls nodeGetHeight() otherwise
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
unsigned BST<Item>::getHeight() const {
	unsigned static height = 1;
	if ( myRoot == nullptr ) {
		return 0;
	} else {
		height = myRoot->nodeGetHeight();
	}
	return height;
}

/* BST Node Height Getter Method
 * @param:			none
 * Precondition:	none
 * Postcondition:	if myLeft !empty, recursively calls nodeGetHeight()
 * Postcondition:	if myRight !empty, recursively calls nodeGetHeight()
 * Postcondition:	returns the greater value, leftHgt or rightHgt
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
unsigned BST<Item>::Node::nodeGetHeight() const {
	unsigned leftHgt, rightHgt;
	leftHgt = rightHgt = 0;
	if (myLeft != nullptr) {
		leftHgt = myLeft->nodeGetHeight();
	}
	if (myRight != nullptr) {
		rightHgt = myRight->nodeGetHeight();
	}
	return (leftHgt > rightHgt? ++leftHgt : ++rightHgt);
}

#endif /*BST_H_*/









