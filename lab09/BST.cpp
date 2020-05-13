/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Michael Sisko
 * Date:         11/19/2019
 */

#include "BST.h"

BST::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
	myItem = it;
	myLeft = NULL;
	myRight = NULL;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

void BST::Node::processItem() {
	cout << ' ' << myItem;
}

void BST::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

void BST::insert( const Item& it ) {
	if ( myRoot == nullptr ) {
		Node* myNode = new Node(it);
		myRoot = myNode;
	} else {
		myRoot->insert(it);
	}
	myNumItems++;
}

void BST::Node::insert( const Item& it ) {
	if ( it < myItem ) {
		if ( myLeft == nullptr ) {
			Node* myNode = new Node(it);
			myLeft = myNode;
		} else {
			myLeft->insert(it);
		}
	} else if ( it > myItem ) {
		if ( myRight == nullptr ) {
			Node* myNode = new Node(it);
			myRight = myNode;
		} else {
			myRight->insert(it);
		}
	} else {
		throw Exception("Node::insert()","item is preexisting!");
	}
}

bool BST::contains(const Item& it) const {
	if ( myRoot == nullptr ) {
		return false;
	} else {
		myRoot->contains(it);
	}
}

bool BST::Node::contains( const Item& it ) const {
	if ( it < myItem ) {
		if ( myLeft == nullptr ) {
			return false;
		}
		myLeft->contains(it);
	}
	else if (it > myItem ) {
		if ( myRight == nullptr ) {
			return false;
		}
		myRight->contains(it);
	}
	else {
		return true;
	}
}









