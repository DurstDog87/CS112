/*
 * List.h
 *
 *  Created on: Oct 8, 2019
 *      Author: mjs96
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>

typedef double Item;

class List {
public:
	List();
	unsigned getSize() const { return mySize; }
	void getSize(unsigned mySize) const;
	Item getFirst();
	Item getLast();
	void append(const Item& it);
	List(const List& original);
	List& operator=(const List& original);
	~List();
private:
	unsigned mySize;
	struct Node {
		Node();
		Node(Item it, Node* next);
		Item myItem;
		Node* myNext;
	};
	Node* myFirst;
	Node* myLast;

	friend class ListTester;
};

#endif /* LIST_H_ */
