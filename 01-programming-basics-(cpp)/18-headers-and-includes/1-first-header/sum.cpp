#include "sum.h"

#include <iostream>
using namespace std;


// File scope. Visible in the file one, BUT no other .cpp can use the same name
int total_calls_global = 0;		// Don't use

// File scope. Visible in the file one AND same var name can be used in other .cpp files
static int total_calls_st_global = 0;

// Definition of extern. Visible from any #include sum.h
int visibile_anywere = 0;

int sum_1_n(int n) {
	++total_calls_global;
	++total_calls_st_global;
	++visibile_anywere;
	++st_gl_per_include;

	cout<<"total_calls_global= "<<total_calls_global
		<<" total_calls_st_global= "<<total_calls_st_global
		<<" st_gl_per_include= "<<st_gl_per_include << " "
		<<" visibile_anywere= "<<visibile_anywere<< "\n";

	int sum = 0;

	for (int i = 0; i < n; ++i)
		sum += i;

	return sum;
}

