/*
*	The adapter design pattern uses a desired interface to interact with legacy software/nondesired interfaces.
*	In this example, assume that we have a legacyRectangle class with an interface we don't want, and that we have
* 	a desired interface as well.
*/
#include <iostream>
using namespace std;

// Desired interface

class Rectangle {
	public:
		virtual void get_dimensions() = 0;	
};


class OldRectangle {
	private:
		int x_1;
		int x_2;
		int y_1;
		int y_2;
	public:
		OldRectangle(int _x_1, int _x_2, int _y_1, int _y_2) {
			x_1 = _x_1;
			x_2 = _x_2;
			y_1 = _y_1;
			y_2 = _y_2;
		}

		void old_get_dimensions() {
			cout << x_1 << " " << x_2 << " " << y_1 << " " << y_2 << endl;
		}
};


class NewRectangle: public Rectangle, public OldRectangle {
	public:
		NewRectangle(int _x_1, int _x_2, int _y_1, int _y_2) : OldRectangle(_x_1, _x_2, _y_1, _y_2) {}

		void get_dimensions() {
			cout << "This is new" << endl;
			old_get_dimensions();
		}
};


int main() {
	Rectangle* rect = new NewRectangle(1, 2, 3, 4);
	rect->get_dimensions();
	
	return 0;
}