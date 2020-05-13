/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student:	Michael Sisko (mjs96)
 * Date:	10/7/2019
 * Begun by: Joel Adams, for CS 112 at Calvin University
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

typedef double Item;

template<class Item>
class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	unsigned getRows() const;
	unsigned getColumns() const;
	Vec<Item>& operator[](unsigned index);
	const Vec<Item>& operator[](unsigned index) const;
	bool operator==(const Matrix<Item>& m2) const;
	bool operator!=(const Matrix<Item>& m2) const;
	void readFrom(istream& in);
	void writeTo(const string& fileName);
	Matrix<Item> operator+(const Matrix<Item>& m2) const;
	void readFrom( const string& fileName );
	void writeTo( ostream& out ) const;
	Matrix<Item> operator-( const Matrix<Item>& m2 );
	Matrix<Item> getTranspose();

private:
	unsigned         myRows;
	unsigned         myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

/* Default Constructor
 * @param:			None
 * Precondition:	None
 * Postcondition:	Variables initialized to 0
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}

/* Explicit Constructor
 * @param:			rows, an unsigned
 * @param:			columns, an unsigned
 * Precondition:	contains values for rows and columns
 * Postcondition:	values incorporated into myVec
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++ ) {
		myVec[i].setSize(columns);
	}
}

/* Retrieves values for rows
 * @param:			None
 * Precondition:	None
 * Postcondition:	Returns row size
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
unsigned Matrix<Item>::getRows() const {
	return myRows;
}

/* Retrieves values for columns
 * @param:			None
 * Precondition:	None
 * Postcondition:	Returns column size
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
unsigned Matrix<Item>::getColumns() const {
	return myColumns;
}

/* Overload Subscript operator
 * @param:			index, an unsigned
 * Precondition:	index contains vector position
 * Postcondition:	Returns value of element at index position
 * Postcondition:	Throw range error if index is invalid
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned index) {
	if ( myRows > index ) {
		return myVec[index];
	} else {
		throw range_error("Invalid index.");
	}
}

/* Overload Subscript operator (READ ONLY)
 * @param:			index, an unsigned
 * Precondition:	index contains vector position
 * Postcondition:	Returns value of element at index position
 * Postcondition:	Throw range error if index is invalid
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned index) const {
	if ( myRows > index ) {
		return myVec[index];
	} else {
		throw range_error("Invalid index.");
	}
}

/* Overload Equality operator
 * @param:			m2, a Matrix template
 * Precondition:	m2 contains a matrix of values
 * Postcondition:	Checks if dimensions of matrices do not match
 * Postcondition:	Otherwise returns that matrices match
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
bool Matrix<Item>::operator==(const Matrix<Item>& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

/* Overload Inequality operator
 * @param:			m2, a Matrix template
 * Precondition:	m2 contains a matrix of values
 * Postcondition:	Checks if dimensions of matrices do match
 * Postcondition:	Otherwise returns that matrices do not match
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
bool Matrix<Item>::operator!=(const Matrix<Item>& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return true;
	} else {
		return myVec != m2.myVec;
	}
}

/* Read from stream
 * @param:			in, an istream
 * Precondition:	in contains values from stream
 * Postcondition:	None
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
void Matrix<Item>::readFrom( istream& in ) {
	for ( unsigned i = 0; i < myRows; i++ ) {
		myVec[i].readFrom(in);
	}
}

/* Write or overwrite a file
 * @param:			fileName, a string
 * Precondition:	fileName contains a file name to be written to
 * Postcondition:	file is written or overwritten
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
void Matrix<Item>::writeTo(const string& fileName) {
	ofstream fout( fileName.c_str() );
	assert( fout.is_open() );

	fout << myRows << '\t' << myColumns;
	for(unsigned i = 0; i < myRows; i++) {
		fout << '\n';
		for(unsigned j = 0; j < myColumns; j++) {
			fout << myVec[i][j] << "\t";
		}
	}
	fout.close();
}

/* Overload Addition operator
 * @param:			m2, a Matrix template
 * Precondition:	m2 contains a matrix of values
 * Postcondition:	Checks if dimensions of matrices do not match
 * Postcondition:	Otherwise returns the addition of the elements
 * AUTHORED BY:		Michael Sisko
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator+(const Matrix<Item>& m2) const {
	if (myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		cout << m2.getRows() << " " << m2.getColumns() << " " << myRows << " " << myColumns << flush;
		throw invalid_argument("Matrices are not the same size.");
	} else {
		Matrix temp(myRows,myColumns);
		for( unsigned i = 0; i < myRows; i++) {
			for( unsigned j = 0; j < myColumns; j++) {
				temp[i][j] = myVec[i][j] + m2[i][j];
			}
		}
		return temp;
	}
}

/* Reads from fileName
 * @param:			fileName, a string
 * Precondition:	fileName contains a file name to be read
 * Postcondition:	values are incorporated into Matrix
 * AUTHORED BY:		John White
 */
template<class Item>
void Matrix<Item>::readFrom( const string& fileName ) {
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );
	fin >> myRows >> myColumns;
	myVec.setSize(myRows);
	for ( unsigned i = 0; i < myRows; i++ ) {
		myVec[i].setSize(myColumns);
		myVec[i].readFrom(fin);
	}
	fin.close();
}

/* Write to console
 * @param:			out, an ostream
 * Precondition:	stream contains values in matrix
 * Postcondition:	values printed to screen in proper order
 * AUTHORED BY:		John White
 */
template<class Item>
void Matrix<Item>::writeTo( ostream& out ) const {
	for ( unsigned i = 0; i < myRows; i++ ) {
		for ( unsigned j = 0; j < myColumns; j++ ) {
			out << myVec[i][j] << "\t";
		}
		out << "\n";
	}
}

/* Overload Subtraction operator
 * @param:			m2, a Matrix template
 * Precondition:	m2 contains a matrix of values
 * Postcondition:	Checks if dimensions of matrices do not match
 * Postcondition:	Otherwise returns the subtraction of the elements
 * AUTHORED BY:		John White
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator-( const Matrix<Item>& m2 ) {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		throw invalid_argument( "Matrices are not the same size." );
	} else {
		Matrix temp( myRows, myColumns );
		for ( unsigned i = 0; i < myRows; i++ ) {
			for ( unsigned j = 0; j < myColumns; j++ ) {
				temp[i][j] = myVec[i][j] - m2[i][j];
			}
		}
		return temp;
	}
}

/* Overload Addition operator
 * @param:			None
 * Precondition:	Matrix as is.
 * Postcondition:	Matrix columns -> rows and vice versa
 * AUTHORED BY:		John White
 */
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose() {
	Matrix temp( myColumns, myRows );
	for ( unsigned i = 0; i < myRows; i++ ) {
		for ( unsigned j = 0; j < myColumns; j++ ) {
			temp[j][i] = myVec[i][j];
		}
	}
	return temp;
}

#endif
