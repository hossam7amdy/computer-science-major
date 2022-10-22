#include<iostream>
#include<vector>
using namespace std;

class MyClass {
private:
	int x;
	int y;
	int z;

public:
    ///This is called: Function Overloading
	void set(int x) {
		cout << "A\n";
	}
	void set(double x) {
		cout << "B\n";
	}
	void set(int x, int y) {
		cout << "C\n";
	}
	void set(int x, int y, int z) {
		cout << "D\n";
	}
	void get(int &a) {
		a = x;
		cout << "E\n";
	}
	void get(int &a, int &b) {
		a = x, b = y;
		cout << "F\n";
	}
};

int main() {
	MyClass m;
	m.set(1);
	m.set(1.5);
	m.set(1, 2);
	m.set(1, 2, 3);

	return 0;
}
