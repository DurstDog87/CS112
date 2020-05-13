///*
// * List.cpp
// *
// *  Created on: Oct 8, 2019
// *      Author: mjs96
// */
//
//#include "List.h"
//#include <stdexcept>
//using namespace std;
//
//List::List() {
//	myFirst = myLast = nullptr;
//	mySize = 0;
//}
//
//List::Node::Node() {
//	myItem = Item();
//	myNext = nullptr;
//}
//
//List::Node::Node(Item it, Node* next) {
//	myItem = it;
//	myNext = next;
//}
//
//void List::getSize(unsigned mySize) const {
//}
//
//Item List::getFirst() {
//	if (mySize == 0 || myFirst == nullptr) {
//		throw underflow_error("Error, List size is 0 or myFirst = nullptr");
//	} else {
//		return myFirst->myItem;
//	}
//}
//
//Item List::getLast() {
//	if (mySize == 0 || myLast == nullptr) {
//		throw underflow_error("Error, List size is 0 or myLast = nullptr");
//	} else {
//		return myLast->myItem;
//	}
//}
//
//void List::append(const Item& it) {
//	Node* newNode = new Node( it, nullptr );
//	if ( mySize == 0 ) {
//		myFirst = newNode;
//	} else {
//		myLast->myNext = newNode;
//	}
//	myLast = newNode;
//	mySize++;
//}
//
//List::~List() {
//	delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == nullptr)
//	myFirst = myLast = nullptr; // clear myFirst and myLast (optional)
//	mySize = 0;              // clear mySize (optional)
//}
//
//List::List(const List& original) {
//	myFirst = myLast = nullptr;		//  set pointers
//	mySize = 0;						//   and size to 'empty' values
//	Node* oPtr = original.myFirst;	//  start at the first node
//	while (oPtr != nullptr) {			//  while there are nodes to copy:
//		append(oPtr->myItem);		//   append the item in that node
//		oPtr = oPtr->myNext;		//   advance to next node
//	}
//}
//
//List& List::operator=(const List& original) {
//	if (&original != this) {
//		delete myFirst;
//		myFirst = myLast = nullptr;
//		mySize = 0;
//		Node* nPtr = original.myFirst;
//		while (nPtr != nullptr) {
//			append(nPtr->myItem);
//			nPtr = nPtr->myNext;
//		}
//	}
//	return *this;
//}
//
//bool List::operator!=(const List& l2) const {
//	if ( mySize == l2.getSize() ) {
//		Node* myNode = myFirst;
//		Node* l2Node = l2.myFirst;
//		while ( myNode != nullptr) {
//			if ( myNode->myItem != l2Node->myItem ) {
//				return true;
//			}
//			myNode = myNode->myNext;
//			l2Node = l2Node->myNext;
//		}
//		return false;
//	} else {
//		return true;
//	}
//}
//
//void List::writeTo( ostream& out ) {
//	Node* myNode = myFirst;
//	for ( unsigned i = 0; i < mySize; i++ ) {
//		out << myNode->myItem << '\n';
//		myNode = myNode->myNext;
//	}
//}
//
// void List::readFrom( const string& fileName ) {
// 	Node* myNode = myFirst;
// 	ifstream fin( fileName.c_str() );
// 		assert( fin.is_open() );
// 		while ( !(fin.eof()) ) {
// 			fin >> myNode->myItem;
// 			myNode = myNode->myNext;
// 		}
// 		fin.close();
// }
//
//int List::getIndexOf( const Item& it ) {
//	Node* myNode = myFirst;
//	int index = 0;
//	if ( mySize > 0 ) {
//		while ( it != myNode->myItem ) {
//			if ( myNode == nullptr ) {
//				throw range_error( "Cannot get index for empty list.");
//			} else {
//				myNode = myNode->myNext;
//				index++;
//			}
//		}
//		return index;
//	} else {
//		return -1;
//	}
//}
//
//int List::remove( unsigned index ) {
//	Node* myNode = myFirst;
//	for ( unsigned i = 0; i < index; i++ ) {
//		if ( i == index ) {
//			delete myNode;
//			myNode = nullptr;
//		} else {
//			myNode = myNode->myNext;
//		}
//	}
//	return myNode->myItem;
//}
//







