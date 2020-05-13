/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student: Michael Sisko (mjs96)
 * Date: 10/1/2019
 * Begun by: Joel Adams, for CS 112 at Calvin University
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

typedef double Item;

class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	unsigned getRows() const;
	unsigned getColumns() const;
	Vec<Item>& operator[](unsigned index);
	const Vec<Item>& operator[](unsigned index) const;
	bool operator==(const Matrix& m2) const;

private:
    unsigned         myRows;
    unsigned         myColumns;
    Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

#endif
