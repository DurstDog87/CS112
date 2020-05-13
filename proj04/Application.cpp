/* Application.cpp applies tested methods.
 * Student:	Michael Sisko (mjs96)
 * Date:	10/7/2019
 * Begun by: Joel Adams, for CS 112 at Calvin University
 */

#include "Matrix.h"
#include "MatrixTester.h"
#include "Application.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>

using namespace std;

Application::Application() {
	int command = -1;
	string fileName = "";

	while ( command != 0 )
	{
		cout << "\nMATRIX MANAGER\n" << endl;
		cout << "\tTo ADD, \tplease press 1 " << endl;
		cout << "\tTo SUBTRACT, \tplease press 2 " << endl;
		cout << "\tTo TRANSPOSE, \tplease press 3 " << endl;
		cout << "\tTo QUIT, \tplease press 0 " << endl;
		cout << "Please type a command followed by the 'Enter' key:\n";

		cin >> command;

		if ( command == 1 ) {
			cout << "Please enter a fileName." << endl;
			cin >> fileName;
			Matrix<double> m1;
			m1.readFrom(fileName.c_str() );
			cout << "Matrix 1:" << endl;
			m1.writeTo(cout);

			cout << "Please enter another fileName." << endl;
			cin >> fileName;
			Matrix<double> m2;
			m2.readFrom(fileName.c_str() );
			cout << "Matrix 2:" << endl;
			m2.writeTo(cout);

			Matrix<double> m3( m1.getRows(), m1.getColumns() );
			m3 = m1 + m2;
			cout << "New Added Matrix:" << endl;
			m3.writeTo(cout);

		} else if ( command == 2 ) {
			cout << "Please enter a fileName." << endl;
			cin >> fileName;
			Matrix<double> m1;
			m1.readFrom(fileName.c_str() );
			cout << "Matrix 1:" << endl;
			m1.writeTo(cout);

			cout << "Please enter another fileName." << endl;
			cin >> fileName;
			Matrix<double> m2;
			m2.readFrom(fileName.c_str() );
			cout << "Matrix 2:" << endl;
			m2.writeTo(cout);

			Matrix<double> m3( m1.getRows(), m1.getColumns() );
			m3 = m2 - m1;
			cout << "New Subtracted Matrix:" << endl;
			m3.writeTo(cout);

		} else if ( command == 3 ) {
			cout << "Please enter a fileName." << endl;
			cin >> fileName;
			Matrix<double> m1;
			m1.readFrom(fileName.c_str() );
			cout << "Matrix 1:" << endl;
			m1.writeTo(cout);

			Matrix<double> m3( m1.getRows(), m1.getColumns() );
			m3 = m1.getTranspose();
			cout << "New Transposed Matrix:" << endl;
			m3.writeTo(cout);

		} else {
			if ( command != 0 ) { cout << "Invalid command." << endl; }
		}
	}
	cout << "End of session. Thank you!" << endl;
}
