/// Wrapper
/*
● StudentGradesInfo is coming from an open source library. Good to save time
    ○ Your team lead is afraid from hidden bugs or stopping the maintenance
    ○ What if we have 20 classes that use it and then we decided to replace or write our own!
    ○ Any change in this class => change in all of them!
● Your team lead suggested building a wrapper
    ○ The idea is create another class StudentGradesInfoWrapper
■ It provides the same public functionality as StudentGradesInfo
    ○ It has object from type StudentGradesInfo
    ○ With every call to StudentGradesInfoWrapper, just call same function in ur local object
    ○ Now all your code depends on the wrapper not on the open source code that may change
● Please also maintain 2 public methods to tell us total
    ○ User prints and total # of created students info
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

    int GetTotalPrints() const {
        return TotalPrintsCount;
	}
};

int StudentGradesInfo::TotalPrintsCount = 0;

class StudentGradesInfoWrapper {
private:
    StudentGradesInfo st;
    static int TotalStudents;
    static int TotalPrints;
public:
    StudentGradesInfoWrapper(string user_id): st(user_id) {
        TotalStudents++;
    }

	bool AddGrade(const double &grade, const string &course_name) {
	    return st.AddGrade(grade, course_name);
	}

	void PrintAllCourses() const {
        // Sadly StudentGradesInfoWrapper is not fully extensible. We can't retrieve statistics_total_prints
		// Let's redo the work
	    TotalPrints++;
	    st.PrintAllCourses();
	}

	bool GetCourseGradeInfo(int pos, pair<string, double> &result) const {
	    result = st.GetCourseResult(pos);
	    if(result.second == -1)
            return false;
        return true;
	}

	string GetStudentId() const {
	    return st.GetStudentId();
	}

	int GetTotalCoursesCount() const {
        return st.GetTotalCoursesCount();
	}

	pair<double, double> GetTotalGradesSum() const {
	    return st.GetTotalResultSum();
	}

	static int GetTotalStudents(){
        return TotalStudents;
	}

	static int GetTotalPrints(){
	   return TotalPrints;
	}
};

int StudentGradesInfoWrapper::TotalStudents = 0;
int StudentGradesInfoWrapper::TotalPrints = 0;

int main() {
	StudentGradesInfoWrapper st1("S000123");
	st1.AddGrade(70, "Math");
	st1.AddGrade(70, "programming 1");
	st1.AddGrade(85, "programming 2");

	st1.PrintAllCourses();

	pair<double, double> p = st1.GetTotalGradesSum();
	cout << p.first << "/" << p.second << "\n";

	StudentGradesInfoWrapper st2("S000129");
	st2.PrintAllCourses();
	st2.PrintAllCourses();
	st2.PrintAllCourses();

	cout << "Total Students " << StudentGradesInfoWrapper::GetTotalStudents() << "\n";
	cout << "Total Prints " << StudentGradesInfoWrapper::GetTotalPrints() << "\n";

	cout << "Bye\n";

	return 0;
}
