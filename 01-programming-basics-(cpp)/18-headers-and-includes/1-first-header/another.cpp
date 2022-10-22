#include "sum.h"
#include <iostream>
using namespace std;

// CE: multiple definition of `total_calls_global'
// Already in sum.cpp
// int total_calls_global = 0;

void go() {

	visibile_anywere += 20;
	st_gl_per_include += 20;

	for (int i = 0; i < 3; ++i)
		sum_1_n(10);

	cout <<"st_gl_per_include= "<<st_gl_per_include << " "
		<<" visibile_anywere= "<<visibile_anywere<< "\n";
}
