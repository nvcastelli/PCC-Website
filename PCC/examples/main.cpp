#include <iostream>
#include "vector2.h"
using namespace std;

int add(int, int);

int main() {
	Vector2 one(2, 2);

	cout << "finally: " << endl;
	cout << "(x, y) == " << one.x[0] << ", " << one.x[1] << endl;
	//cout << "x: " << add( one.x, two.x ) << endl;
	//cout << "y: " << add( one.y, two.y ) << endl;
}