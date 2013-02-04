#include <iostream>
using namespace std;

int main() {
	float** _data;
	int cols = 3;
	int rows = 3;
	_data = new float*[cols];
	for(int i = 0; i < cols; ++i) {
		_data[i] = new float[rows];
	}

	for(int j=0; j < rows; ++j) {
		for(int i=0; i < cols; ++i) {
			_data[i][j] = i + j;
		}
	}

	for(int j=0; j < rows; ++j) {
		cout << "[ ";
		for(int i=0; i < cols; ++i) {
			cout << "( " << i << ", " << j << ") " << _data[i][j] << ", ";
		}
		cout << " ]\n";
	}
}