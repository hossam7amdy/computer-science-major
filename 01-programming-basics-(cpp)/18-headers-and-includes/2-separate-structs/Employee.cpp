#include "Employee.h"

// Important to see the complete implementation later
#include "Department.h"


Employee* emp_glob = new Employee("mostafa");

Employee::Employee(string name_) {
	name = name_;
}

void Employee::Print() {

	cout << "I am " << name << "\n";

	cout << "I work in the following departments: \n";

	for (Department* d : deps)
		d->PrintDepartment();
}

// but we did not include cout and string?
//		visible from the .h file
