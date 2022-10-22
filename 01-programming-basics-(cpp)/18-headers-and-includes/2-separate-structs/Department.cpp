#include "Department.h"

void Department::PrintDepartment() {
	cout << "Department name " << name
			<< " has " << deps.size() << " Employees";
}
