#include <iostream>
#include "sum.h"
#include "another.h"
using namespace std;

int main() {
	// There are THREE (not 2) copies of st_gl_per_include
	// main.cpp, sum.cpp and another.cpp

	visibile_anywere += 40;
	st_gl_per_include += 40;

	for (int i = 0; i < 3; ++i)
		sum_1_n(10);

	go();

	cout <<"st_gl_per_include= "<<st_gl_per_include << " "
		<<" visibile_anywere= "<<visibile_anywere<< "\n";

	return 0;
}
