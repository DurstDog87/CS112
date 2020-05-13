/*
 * ReversePoem.cpp
 *
 *  Created on: Nov 11, 2019
 *      Author: mjs96
 */

#include "ReversePoem.h"

/* Reverse Poem Constructor
 * @param:			poemFile, a string
 * Precondition:	contains file name
 * Postcondition:	myTitle no longer holds ""
 * Postcondition:	myAuthor no longer holds ""
 * Postcondition:	myBody no longer holds ""
 * Postcondition:	myBodyReversed no longer holds ""
 * AUTHORED BY:		Michael Sisko
 */
ReversePoem::ReversePoem(const string& poemFile) {
	ifstream fin( poemFile.c_str() );
	assert( fin.is_open() );

	getline(fin,myTitle);
	getline(fin,myAuthor);
	string blankLine;
	getline(fin,blankLine);

	Stack<string> p0(1);
	string currLine;
	while ( fin.good() ) {
		getline(fin,currLine);
		p0.push(currLine);
		myBody = myBody + currLine + '\n';
		if ( p0.isFull() ) {
			p0.setCapacity( p0.getCapacity()*2 );
		}
	}
	fin.close();

	while ( !p0.isEmpty() ) {
		myBodyReversed = myBodyReversed + p0.pop() + '\n';
	}
}









