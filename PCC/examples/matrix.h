#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
using namespace std;

namespace Matrix {
	
	
	class Matrix {
		private:
			int _rows;
			int _cols;

			float* _data;

			void cleanup();

		public:
			Matrix();
			Matrix( int, int );		// row, columns
			Matrix( const Matrix& );		// copy constructor
			~Matrix();

			Matrix& operator=( const Matrix& m );
			Matrix& operator+( const Matrix& m );
			Matrix& operator-( const Matrix& m );
			Matrix& operator*( const Matrix& m );
			float& operator() ( int x, int y);
			float operator() ( int x, int y) const;

			float det();

			string Serialize();

			// setters
			void readFromInput();
			void readFromString( string );

			// getters
			int rows();
			int cols();
			int cols() const;
			int rows() const;

	}; // end Matrix

	// overloads
	std::ostream& operator<<( std::ostream& os, const Matrix m );
	bool operator==( Matrix, Matrix );
	bool operator!=( Matrix, Matrix );

	float det( Matrix );
	string InputToMatrixString();

} // end namespace

#endif
