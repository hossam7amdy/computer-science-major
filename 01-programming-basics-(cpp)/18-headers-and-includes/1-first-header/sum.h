#ifndef SUM_H_
#define SUM_H_


//int global;	// CE

// Create & Use the SAME variable with EVERY #include sum.h
extern int visibile_anywere;	// Global across files

// Create a DIFFERENT variable with EVERY #include sum.h
// Don't use it - Useless & Very confusing
static int st_gl_per_include = 0;

int sum_1_n(int n);

#endif /* SUM_H_ */
