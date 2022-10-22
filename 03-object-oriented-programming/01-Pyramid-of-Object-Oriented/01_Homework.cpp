#include<iostream>
using namespace std;

template<typename T>
struct Date{
    int year;
    // month can be string or integer
    T month;
    int day;

    Date(){ year = day = 0; }

    void ReadDate(int _y, auto _m, int _d){
        year = _y;
        month = _m;
        day = _d;
    }

    // Setters
    void SetYear(int _y){   year = _y; }

    void SetMonth(auto _m){   month = _m; }

    void SetDay(int _d){    day = _d; }

    // Getters
    int GetYear() { return year; }
    auto GetMonth(){ return month; }
    int GetDay() { return day; }

    void PrintFullDate(char delimiter = '-') const {  cout << year << delimiter << month << delimiter << day; }

    void Print_YYYY_MM(char delimiter = '-') const {   cout << year << delimiter << month;  }

    void Print_MM_DD(char delimiter = '-') const { cout << month << delimiter << day;   }

    // Returns the length of the month represented by this date.
	int LengthOfMonth();

	// Returns the length of the year represented by this date.
	int LengthOfYear();

	// Returns a copy of this LocalDate with the specified number of days subtracted.
	Date MinusDays(int DaysToSubtract);
	Date MinusMonths(int MonthsToSubtract);
	Date MinusYears(int YearsToSubtract);
	Date MinusWeeks(int WeeksToSubtract);

	// Similarly, we can add Days. E.g. PlusDays(int DaysToAdd)

	// To allow flexible strings, user provide format,
	// e.g. yyyy.mm.dd returns (2014-07-26) and dd.mm returns (26-07)
	string ToString(string format);

	bool isEqual(Date d);
	bool isBefore(Date d);
	bool isAfter(Date d);

	bool IsLeapYear();	// google if don't know

	// These are just some methods. In reality, much more complex.

};

struct Time{

    // We can describe time struct in 2 ways:
    // Normal way: 3 integers for hours, minutes and seconds
    // Another way is 1 variable only: total number of seconds. Which can be converted to the other way

    // Although using 1 variable only saves memory, but it complicates the code.
    // Clarity should be preferred than minor efficiency improvements

};

struct DateTime{
    Date<string> date;
    Time time;

    DateTime(int _y, string _m, int _d) { date.ReadDate(_y, _m, _d); }

    void PrintDate(){
        cout << "Which Format: \n"
            << "\t1) YYYY-MM-DD\n"
            << "\t2) YYYY-MM\n"
            << "\t3) MM-DD\nEnter: ";
        int choose;
        cin >> choose;
        switch(choose){
            case 1: date.PrintFullDate(); break;
            case 2: date.Print_YYYY_MM(); break;
            case 3: date.Print_MM_DD(); break;

            default: {
                cout << "Invalid choice. TRY AGAIN!\n";
                PrintDate();
            }
        }
        return;
    }


};

////////////////////////////////////////////////////////////////
// In a debate with a college:
// Be open for different views (e.g, 2 ways for the data members)
// Defend your choices with logical reasons
// Also understand your college choices & reasons
// A lot of areas are just vague. We may not know which direction is definitely the right way
// Minor design concerns are not like big ones. System design is more risker than a class design
// Find someone with more experience to help you make decisions
// Or put time limit: discuss for an hour, then vote.
// Red flag if discussions are very lengthy with a few "action items"


int main(){
    DateTime dt(2021, "June", 10);
    dt.PrintDate();

    return 0;
}
