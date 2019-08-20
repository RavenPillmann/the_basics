#include <iostream>
using namespace std;

class Singleton {
	private:
		static Singleton* object;
		Singleton();
	public:
		static Singleton* get_instance();
};

Singleton* Singleton::object = 0;

Singleton::Singleton () {}
 
Singleton* Singleton::get_instance() {
	if (object == 0) {
		object = new Singleton();
	}

	return object;
}


int main() {
	Singleton* singleton = Singleton::get_instance();

	return 0;
}