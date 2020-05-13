/* tester.cpp tests the methods in class BST.h
 * Student Name: Michael Sisko
 * Date:         11/19/2019
 */

#include "BST_Tester.h"

int main() {
	BST_Tester bstt;
	bstt.runTests();

	cout << "\nWelcome to the BST tree height program!" << endl;

	ifstream fin1( "randomIntFileList.txt" );
	assert( fin1.is_open() );

	ofstream fout( "project09out.txt" );
	assert( fout.is_open() );

	unsigned dupliCount = 0;
	while ( fin1.good() ) {

		string fileName = "";
		getline(fin1,fileName);
		ifstream fin2( fileName.c_str() );
		assert( fin2.is_open() );

		dupliCount = 0;
		long numString = 0;
		BST<long> t0;
		t0.~BST();

		while ( fin2.good() ) {
			fin2 >> numString;
			try {
				t0.insert(numString);
			} catch ( Exception& e ) {
				dupliCount++;
			}
		}

		fout << fileName << " generates tree height: "
				<< t0.getHeight() << " and contains "
				<< dupliCount << " duplicate(s)!\n" << endl;

		fin2.close();
	}

	cout << "Operation complete, See 'project09out.txt' for results!" << endl;

	fin1.close();
	fout.close();
}









