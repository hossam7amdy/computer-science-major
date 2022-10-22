/// White-Box Test
/*
● In white box testing, we care about really what happens internally.
    ○ The private variables and methods and their updates
● But how to test the class from outside?
    ○ Several approaches
    ○ One way Define friend class StudentGradesInfoWhiteBoxTester; inside the class StudentGradesInfo
■ Please follow this approach for the homework
○ Now, the tester can access all internals and do deeper testing
*/

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class StudentGradesInfoWhiteBoxTester;

class StudentGradesInfo {
private:
	string student_id;
	vector<double> grades;
	vector<string> courses_names;

	static int TotalPrintsCount; // for statistics

	const double MAX_GRADE_PER_COURSE = 100.0; // magic number

    double AdjustGrade(double grade){
		if (grade < 0)
			return 0;
        if(grade > MAX_GRADE_PER_COURSE)
            return MAX_GRADE_PER_COURSE;
        return grade;
	}

	friend class StudentGradesInfoWhiteBoxTester;

public:
	StudentGradesInfo(string id): student_id(id) { }

	bool AddGrade(double grade, string course_name) { // If already added = don't update
		//AdjustGrade(grade);

		for (int i = 0; i < (int) courses_names.size(); ++i){
            if(course_name == courses_names[i])
                return false;
		}

		courses_names.push_back(course_name);
		grades.push_back(AdjustGrade(grade));
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

class StudentGradesInfoWhiteBoxTester{
private:
    const double MAX_GRADE_PER_COURSE = 100.0;
public:
    void static TestAdjustGrade(){
        cout << __func__ << endl;
        StudentGradesInfo st1("S10101");
        assert(st1.AdjustGrade(-10)==0.0);
        assert(st1.AdjustGrade(110)==100.0);
        assert(st1.AdjustGrade(0)==0);
        assert(st1.AdjustGrade(86)==86);
    }

    void static TestAddGrade(){
        cout << __func__ << endl;
        StudentGradesInfo st1("S10101");
        assert(st1.AddGrade(121,"programming1")==true);
        assert(st1.AddGrade(70,"programming1")==false);
        assert(st1.AddGrade(-100,"programming2")==true);
        assert(st1.courses_names.size() == st1.grades.size() && st1.courses_names.size() == 2);
        assert(st1.courses_names.back() == "programming2");
        assert(st1.grades.back() == 0);
    }

    void static TestStatisticsTotalPrints(){
        cout << __func__ << endl;
        StudentGradesInfo st1("S10101");
        assert(st1.TotalPrintsCount == 0);
        st1.PrintAllCourses();
        assert(st1.TotalPrintsCount == 1);
        st1.PrintAllCourses();
        st1.PrintAllCourses();
        assert(st1.TotalPrintsCount == 3);
    }

    void TestAll(){
        TestAdjustGrade();
        TestAddGrade();
        TestStatisticsTotalPrints();
        cout << "Passed all test cases\n";
    }
};

int main() {

	StudentGradesInfoWhiteBoxTester().TestAll();

	return 0;
}
