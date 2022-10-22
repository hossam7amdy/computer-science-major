/// Code Extension
/*
● Sadly current print has 2 issues
    ○ Print to console / Print all content!
● For some reasons, we can’t change the code
    ○ Another idea is to extend its functionality!
● Your team lead asked to develop a class that satisfy the following main
    ○ Mainly a new class that works on an object from StudentGradesInfo
    ○ It satisfies 2 critical functions for iterating on the StudentGradesInfo courses:
■ HasNext: That tell us if there is more to retrieve
■ GetNext: Return actual element in turn to retrieve
    ○ Also Reset method in case we wanna iterate from scratch again
● Develop a class that satisfies this main
*/

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class StudentGradesInfo {
private:
	string student_id;
	vector<double> grades;
	vector<string> courses_names;

	static int TotalPrintsCount; // for statistics

	const double MAX_GRADE_PER_COURSE = 100.0; // magic number

    void AdjustGrade(double &grade){
		if (grade < 0)
			grade = 0;
        if(grade > MAX_GRADE_PER_COURSE)
            grade = MAX_GRADE_PER_COURSE;
	}

public:
	StudentGradesInfo(string id):  student_id(id) { }

	bool AddGrade(double grade, string course_name) { // If already added = don't update
		AdjustGrade(grade);

		for (int i = 0; i < (int) courses_names.size(); ++i)
            if(course_name == courses_names[i])
                return false;

		courses_names.push_back(course_name);
		grades.push_back(grade);
		return true;
	}

	void PrintAllCourses() const {
		++TotalPrintsCount;

		cout << "Grades for student: " << GetStudentId() << "\n";
		for (int i = 0; i < GetTotalCoursesCount(); ++i){
			pair<string, double> res = GetCourseResult(i);
			cout << "\t" << res.first << " = " << res.second << "\n";
		}
	}

	pair<string, double> GetCourseResult(int pos) const {
		if (pos < 0 || pos >= (int) grades.size())
			return make_pair("", -1);
		return make_pair(courses_names[pos], grades[pos]);
	}

    string GetStudentId() const {
		return student_id;
	}

	int GetTotalCoursesCount() const {
		return grades.size();
	}

	pair<double, double> GetTotalResultSum() const {
		double sum = 0, total = 0;
		for (int i = 0; i < (int) GetTotalCoursesCount(); ++i)
			sum += grades[i], total += MAX_GRADE_PER_COURSE;
		return make_pair(sum, total);
	}
};

int StudentGradesInfo::TotalPrintsCount = 0;

class StudentGradesInfoPrinter{
private:
    int counter;
    const StudentGradesInfo& st;
public:
    // Make it object by reference to feel updates. Const to never change its content as printer
    StudentGradesInfoPrinter(const StudentGradesInfo& st): st(st), counter(0) {  }

    bool HasNext(){
        return (counter < st.GetTotalCoursesCount());
    }

    void ResetIterator(){
        counter = 0;
    }

    pair<string, double> GetNext(){
        return st.GetCourseResult(counter++);
    }
};

/*

You just learned 2 things:

1- Open–closed principle
"Software entities ... should be open for extension, but closed for modification."
We managed to extend the functionality of the class to controlled printing. We did not need to change original code

2- Iterator Design Pattern
- HasNext / GetNext is a general strategy to allow iterating on something
- STL has iterators on several containers

 */

int main() {
	StudentGradesInfo st1("S000123");
	StudentGradesInfoPrinter printer(st1);

	st1.AddGrade(50, "Math");
	st1.AddGrade(60, "programming 1");

	int limit = 3;
	cout << "Printing top " << limit << " Grades, if available\n";
	while (limit-- && printer.HasNext()) {
		pair<string, double> result = printer.GetNext();

		cout << "\t" << result.first << " = " << result.second << "\n";
	}

	st1.AddGrade(70, "Algorithms");
	st1.AddGrade(67, "programming 2");

	printer.ResetIterator();
	limit = 3;
	cout << "\nPrinting top " << limit << " Grades, if available\n";
	while (limit-- && printer.HasNext()) {
		pair<string, double> result = printer.GetNext();

		cout << "\t" << result.first << " = " << result.second << "\n";
	}
	return 0;
}
