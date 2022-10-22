#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

#include "Employee.h"

struct Department {
	string name;
	// can use actual struct not pointer
	vector<Employee> deps;

	void PrintDepartment();
};

#endif /* DEPARTMENT_H_ */
