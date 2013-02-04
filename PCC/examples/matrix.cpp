#include <iostream>
#include <string>
#include "matrix.h"
using namespace Matrix;

	///////////////////////////////////////////////
	//			MATRIX DEFINITIONS				 //
	///////////////////////////////////////////////

/**
	Default Constructor
*/
Matrix::Matrix() 
{
	_rows = 1;
	_cols = 1;

	_data = new float*[_cols];
	for(int i = 0; i < _cols; ++i) {
		_data[i] = new float[_rows];
	}
}

/**
	Construct a matrix with specific dimensions.
	@param 	x	rows
	@param	y	cols
*/
Matrix::Matrix( int x, int y )
 : _rows(y), _cols(x) 
 {
	_rows = y;
	_cols = x;

	_data = new float*[_cols];
	for(int i = 0; i < _cols; ++i) {
		_data[i] = new float[_rows];
	}
}

/**
	A copy constructor
*/
Matrix::Matrix( const Matrix& m ) 
{
	this = m;
}

/**
	Destructor
*/
Matrix::~Matrix() 
{
	cleanup();
}

	///////////////////////////////////////////////
	//				MATRIX::METHODS						//
	///////////////////////////////////////////////
int Matrix::rows() { return _rows; }
int Matrix::cols() { return _cols; }
const int Matrix::rows() { return _rows; } 
const int Matrix::cols() { return _cols; }

void Matrix::cleanup()
{
	for(int i = 0; i < _cols; ++i) {
    	delete [] _data[i];
	}

	delete [] _data;
}
/**
	Output the Matrix in a human readable format
						  ^-(hopefully)
*/
void Matrix::print( ostream& os ) const
{
	for(int j=0; j < _rows; ++j) {
		os << "[ ";
		for(int i=0; i < _cols; ++i) {
			os << "( " << _data[i][j] << " ) ";
		}
		os << "]\n";
	}
}


	///////////////////////////////////////////////
	//				MATRIX::OVERLOADS						//
	///////////////////////////////////////////////
/**
	Getting Elements
*/
float& Matrix::operator() ( int x, int y ) 
{	
	try {
		if(x >= _rows || y >= _cols )
			{ throw 'e'; }
	}
	catch(...) { cout << "\n*** ERROR: Index out of bounds ***\n"; }

	return _data[x][y]; 
}

float Matrix::operator() ( int x, int y ) const
{	
	try {
		if(x >= _rows || y >= _cols )
			{ throw 'e'; }
	}
	catch(...) { cout << "\n*** ERROR: Index out of bounds ***\n"; }

	return _data[x][y]; 
}

/**
	Assignment Operator
*/
Matrix& Matrix::operator=( const Matrix& m ) 
{
	_cols = m.cols();
	_rows = m.rows();
	cleanup();

	for(int j = 0; j < _rows; ++j) {
		for(int i = 0; i < _cols; ++i) {
			_data[i][j] = m(i, j);
		}
	}

	return *this;
}

/**
	Addition Operator
*/
Matrix& Matrix::operator+( const Matrix& m ) 
{
	//////////////////////////////////////////////
	// never EVER trust the user.
	try {
		if( _cols != m.cols() || _rows != m.rows() ) 
			{ throw 'e'; }
	}
	catch(...) { 
		cout << "\n*** ERROR: Addition for matrices of different dimensions is undefined. ****\n"; 
	}
	//////////////////////////////////////////////

	for(int j = 0; j < _rows; ++j) {
		for(int i = 0; i < _cols; ++i) {
			_data[i][j] += m(i, j);
		}
	}

	return *this;
}

/**
	Subtraction Operator
*/
Matrix& Matrix::operator-( const Matrix& m ) 
{
	//////////////////////////////////////////////
	// never EVER trust the user.
	try {
		if( _cols != m.cols() || _rows != m.rows() ) 
			{ throw 'e'; }
	}
	catch(...) { 
		cout << "\n*** ERROR: Subtraction for matrices of different dimensions is undefined. ***\n"; 
	}
	//////////////////////////////////////////////
	
	for(int j = 0; j < _rows; ++j) {
		for(int i = 0; i < _cols; ++i) {
			_data[i][j] -= m(i, j);
		}
	}

	return *this;
}

/** TODO
	Multiplcation Operator
	defined only if the number of columns m in A is equal to the number of rows m in B.
*/
Matrix& Matrix::operator*( const Matrix& m ) 
{
	//////////////////////////////////////////////
	// never EVER trust the user.
	try {
		if( _cols != (m.rows()) ) 
			{ throw 'e'; }
	}
	catch(...) { 
		cout << "\n*** ERROR: LHS columns must equal RHS rows ***\n"; 
	}
	//////////////////////////////////////////////

	return *this;
}

	//////////////////////////////////////////////
	//				UTILITY METHODS					  //
	//////////////////////////////////////////////