/// Black-Box Test
/*
● In black box testing, we test the public functionality of a class
    ○ Focus on what not how
    ○ No care of internals

● Develop a class that test our previous class
    ○ Try the old code
    ○ Then the fixed code
*/

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class StudentGradesInfo {
private:
	string student_id;
	string student_name;
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
	StudentGradesInfo(string name, string id): student_name(name), student_id(id) { }

	bool AddGrade(double grade, string course_name) { // If already added = update grade
		AdjustGrade(grade);

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

	void PrintAllCourses() const {
		++TotalPrintsCount;

		cout << "Grades for student: " << GetStudentName() << "\n";
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

    string GetStudentName() const {
		return student_name;
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

class StudentGradesInfoBlackBoxTester{
private:
    const double MAX_GRADE_PER_COURSE = 100.0;
public:
    void TestPrintAllCourses(){
		cout << __func__ << "\n";
        StudentGradesInfo st1("Hossam", "10101");
        assert(st1.GetTotalCoursesCount() == 0);
        freopen("write.txt", "out", stdin);
        st1.PrintAllCourses();
		// This function is writing to console! How to test?
		// 1) use Freopen to direct output to file
		// 2) read file content
		// 3) compare to what you expect!
    }

    void TestGetCourseResult(){
        cout << __func__ << endl;
        StudentGradesInfo st1("Hossam", "10101");
        assert(st1.GetTotalCoursesCount() == 0);

        st1.AddGrade(88.6, "Programming1"); // 0
        st1.AddGrade(188.6, "Programming1"); // 0
        st1.AddGrade(87.6, "Programming1"); // 0

        st1.AddGrade(88.6, "Math1"); // 1
        st1.AddGrade(188.6, "Programming2"); // 2
        st1.AddGrade(87.6, "Programming OOP"); // 3

        pair<string, double> result = st1.GetCourseResult(10);
        assert(result.first == "" && result.second == -1);

        result = st1.GetCourseResult(-10);
        assert(result.first == "" && result.second == -1);

        result = st1.GetCourseResult(0);
        assert(result.second == 87.6);

        result = st1.GetCourseResult(2);
        assert(result.first == "Programming2" && result.second == MAX_GRADE_PER_COURSE);

        result = st1.GetCourseResult(3);
        assert(result.first == "Programming OOP" && result.second == 87.6);

        result = st1.GetCourseResult(4);
        assert(result.first == "" && result.second == -1);
    }

    void TestGetTotalCoursesCount(){
        cout << __func__ << endl;
        StudentGradesInfo st1("Hossam", "10101");
        assert(st1.GetTotalCoursesCount() == 0);

        st1.AddGrade(88.6, "Programming1");
        st1.AddGrade(188.6, "Programming1");
        st1.AddGrade(87.6, "Programming1");
        assert(st1.GetTotalCoursesCount() == 1);

        st1.AddGrade(88.6, "Math1");
        st1.AddGrade(188.6, "Programming2");
        st1.AddGrade(87.6, "Programming OOP");
        assert(st1.GetTotalCoursesCount() == 4);
    }

    void TestGetTotalResultSum(){
        cout << __func__ << endl;
        StudentGradesInfo st1("Hossam", "10101");
        assert(st1.GetTotalCoursesCount() == 0);

        pair<double, double> p = st1.GetTotalResultSum();
        assert(p.first <= p.second);
    }

    void TestAll(){
        TestPrintAllCourses();
        TestGetCourseResult();
        TestGetTotalCoursesCount();
        TestGetTotalResultSum();
        cout << "Passed all test cases\n";
    }
};

int main() {

	StudentGradesInfoBlackBoxTester().TestAll();

	return 0;
}
