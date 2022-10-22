/// Code Review
/*
● Requirements
    ○ Class for a student and his grades per course
    ○ Grade max is 100 (e.g. 76.5/100)
    ○ Printing functionality or retrieve per course
    ○ Track how many times printing is called.
● Developer coded this/next

● Figure out:
    ○ 2 Coding bugs
    ○ Several OO violations or design issues
    ○ Something if we need to change, cause changes in several places
    ○ Naming inconsistency
    ○ 2 better variables naming in functions
● Suggest better declaration for
    ○ pair<string, double> GetCourseGradeInfo(int pos)
*/

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;


class StudentGradesInfo {
private:
	string student_id; // where is student name?
	string student_name;
	vector<double> grades;
	vector<string> courses_names;
	static int TotalPrintsCount;
	const double MAX_GRADE_PER_COURSE = 100.0;
    // It seems developer wants to keep track of how many times this function is called
	// Proper way to maintain = static counter inside the class

    // Several issues in this function
	// 1- It is public, although for internal usage! Move to private
	// 2- It doesn't change class variables! Make it const. Another way is just to change it to void AdjustGrade(double & grade)
	// 3- It uses a magic number:
	// A magic number is a numeric literal (for example, 8080 , 2048 ) that is used in the middle of a block of code without explanation.
	// It is considered good practice to avoid magic numbers by assigning the numbers to named constants and using the named constants instead
	// 4- Also: if requirement changed 100 to say 50, we will do a lot of code changes!
	// 5: bug, it should be double not int (in parameter and return)
	// 6: bug in if (grade < 0) => should return 0

    void AdjustGrade(double &grade){
		if (grade < 0)
			grade = 0;
        if(grade > MAX_GRADE_PER_COURSE)
            grade = MAX_GRADE_PER_COURSE;
	}

public:
	// It seems developer wants to prevent users from using empty constructor
	// Just asserting will break the program
	// Removing this constructor will disallow the default constructor!
	//StudentGradesInfo() {
	//	assert(false);
	//}

	StudentGradesInfo(string name, string id): student_name(name), student_id(id) { // user initializer list, and where the assigning of name?
	}

	bool AddGrade(double grade, string course_name) { // If already added = update grade
		AdjustGrade(grade);

        // Very big bug. A lot of run time errors will happen!
		// needed to move to end of function
		//grades.push_back(grade);

		for (int i = 0; i < (int) courses_names.size(); ++i){
            if(course_name == courses_names[i]){
                grades[i] = grade;
                return true;
            }
		}

		courses_names.push_back(course_name);
		grades.push_back(grade);
		return true;
	}

    // Make const!
	// Use variables names that are understandable!
	// Good function and variable names are key in clear code
	void PrintAllCourses() const { // const
		++TotalPrintsCount;

		cout << "Grades for student: " << GetStudentName() << "\n";
		for (int i = 0; i < GetTotalCoursesCount(); ++i){  // Use GetTotalCoursesCount for naming consistency
			pair<string, double> res = GetCourseResult(i);
			cout << "\t" << res.first << " = " << res.second << "\n";
		}
	}

	pair<string, double> GetCourseResult(int pos) const { // const =>> GetCourseResult
		if (pos < 0 || pos >= (int) grades.size())
			return make_pair("", -1);
		return make_pair(courses_names[pos], grades[pos]);
	}

    string GetStudentName() const { // const
		return student_name;
	}

	int GetTotalCoursesCount() const { // const
		return grades.size();
	}

	// Use GetTotalCoursesCount for naming consistency
	pair<double, double> GetTotalResultSum() const { // const
		double sum = 0, total = 0;
		for (int i = 0; i < (int) GetTotalCoursesCount(); ++i)
			sum += grades[i], total += MAX_GRADE_PER_COURSE;
		return make_pair(sum, total);
	}
};

int StudentGradesInfo::TotalPrintsCount = 0;

int main() {
	StudentGradesInfo st1("Mostafa", "S000123");
	st1.AddGrade(70, "Math");
	st1.AddGrade(70, "programming 1");
	st1.AddGrade(85, "programming 2");
	st1.AddGrade(90, "programming 2");

	st1.PrintAllCourses();

	pair<double, double> p = st1.GetTotalResultSum();
	cout<<p.first<<"/"<<p.second<<"\n";

	cout<<"Bye\n";

	return 0;
}
