#include <iostream>

using namespace std;

class integer {
	int a;
public:
	integer(int data) :a(data) {}
	integer operator+ (integer obj) {
		integer res(0);
		res.a = a + obj.a;
		return res;
	}
	friend ostream& operator<<(ostream& os, integer obj) {
		os << obj.a<<endl;
		return os;
	}
	void print() { cout << a << endl; }
};

//int main() {
//	integer obj1 = 10;
//	integer obj2(5);
//	cout << obj1;
//	integer obj3 = obj1 + obj2;
//	obj3.print();
//	cout << obj1 + obj2;
//	return 0;
//}