///* Matrix.cpp defines Matrix class methods.
// * Student:	Michael Sisko (mjs96)
// * Date:		10/7/2019
// * Begun by: Joel Adams, for CS 112 at Calvin University
// */
//
//#include "Matrix.h"
//
//Matrix::Matrix() {
//	myRows = myColumns = 0;
//}
//
//Matrix::Matrix(unsigned rows, unsigned columns) {
//	myRows = rows;
//	myColumns = columns;
//	myVec.setSize(rows);
//	for (unsigned i = 0; i < rows; i++ ) {
//		myVec[i].setSize(columns);
//	}
//}
//
//unsigned Matrix::getRows() const {
//	return myRows;
//}
//
//unsigned Matrix::getColumns() const {
//	return myColumns;
//}
//
//Vec<Item>& Matrix::operator[](unsigned index) {
//	if ( myRows > index ) {
//		return myVec[index];
//	} else {
//		throw range_error("Invalid index.");
//	}
//}
//
//const Vec<Item>& Matrix::operator[](unsigned index) const {
//	if ( myRows > index ) {
//		return myVec[index];
//	} else {
//		throw range_error("Invalid index.");
//	}
//}
//
//bool Matrix::operator==(const Matrix& m2) const {
//	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
//		return false;
//	} else {
//		return myVec == m2.myVec;
//	}
//}
//
//bool Matrix::operator!=(const Matrix& m2) const {
//	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
//		return true;
//	} else {
//		return myVec != m2.myVec;
//	}
//}
//
//void Matrix::readFrom( istream& in ) {
//	for ( unsigned i = 0; i < myRows; i++ ) {
//		myVec[i].readFrom(in);
//	}
//}
//
//void Matrix::writeTo(const string& fileName) {
//	ofstream fout( fileName.c_str() );
//	assert( fout.is_open() );
//
//	fout << myRows << '\t' << myColumns;
//	for(unsigned i = 0; i < myRows; i++) {
//		fout << '\n';
//		for(unsigned j = 0; j < myColumns; j++) {
//			fout << myVec[i][j] << "\t";
//		}
//	}
//	fout.close();
//}
//
//Matrix Matrix::operator+(const Matrix& m2) const {
//	if (myRows != m2.getRows() || myColumns != m2.getColumns() ) {
//		throw invalid_argument("Matrices are not the same size.");
//	} else {
//		Matrix temp(myRows,myColumns);
//		for( unsigned i = 0; i < myRows; i++) {
//			for( unsigned j = 0; j < myColumns; j++) {
//				temp[i][j] = myVec[i][j] + m2[i][j];
//			}
//		}
//		return temp;
//	}
//}
//
////8888888888888888888888888888888888888888888888888888888888888888888888888888
//
//void Matrix::readFrom( const string& fileName ) {
//	ifstream fin( fileName.c_str() );
//	assert( fin.is_open() );
//	fin >> myRows;
//	fin >> myColumns;
//	myVec.setSize(myRows);
//	for ( unsigned i = 0; i < myRows; i++ ) {
//		myVec[i].setSize(myColumns);
//		myVec[i].readFrom(fin);
//	}
//	fin.close();
//}
//
//void Matrix::writeTo( ostream& out ) const {
//	for ( unsigned i = 0; i < myRows; i++ ) {
//		myVec[i].writeTo(out);
//		out << "\n";
//	}
//}
//
//Matrix Matrix::operator-( const Matrix& m2 ) {
//	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
//		throw invalid_argument( "Unequal number of rows or columns" );
//	} else {
//		Matrix temp( myRows, myColumns );
//		for ( unsigned i = 0; i < myRows; i++ ) {
//			for ( unsigned j = 0; j < myColumns; j++ ) {
//				temp[i][j] = myVec[i][j] - m2[i][j];
//			}
//		}
//		return temp;
//	}
//}
//
//Matrix Matrix::getTranspose() {
//	Matrix temp( myColumns, myRows );
//	for ( unsigned i = 0; i < myRows; i++ ) {
//		for ( unsigned j = 0; j < myColumns; j++ ) {
//			temp[j][i] = myVec[i][j];
//		}
//	}
//	return temp;
//}
