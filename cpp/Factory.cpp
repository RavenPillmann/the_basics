#include <iostream>
#include <string>
using namespace std;

class ToyFactory {
	public:
		static ToyFactory *make_toy(int choice);
		virtual void do_action() {
			cout << "Nothing" << endl;
		};	
};


class Car: public ToyFactory {
	public:
		void do_action() {
			cout << "Vroom vroom" << endl;
		}
};

class Ball: public ToyFactory {
	public:
		void do_action() {
			cout << "Bounce" << endl;
		}
};


ToyFactory* ToyFactory::make_toy (int choice) {
	switch (choice) {
		case 0: {
			return new Car();
		} case 1: {
			return new Ball();
		} default: {
			return new Ball();
		}
	};
}


int main() {
	ToyFactory* car = ToyFactory::make_toy(0);
	ToyFactory* ball = ToyFactory::make_toy(1);

	car->do_action();
	ball->do_action();

	return 0;
}