/// Homework 3: Company Payroll
/*
● We need to represent a company and its payroll:
    ○ Working people: either volunteers or employees
    ○ Employees could be hourly based or salaried based.
■ Also a commision salaried employee takes extra money as ratio of the sales he did
    ○ Also there are invoices, each invoice has set of items (books, Food, etc)
■ Each item has its own details (e.g. book author name)
    ○ The payroll should determine and pay money for whatever payable such as employee or invoice
● Assume after a few months later we needed:
    ○ A labourer Employee which is a Hourly Employee
    ○ No new functions and variables at the moment
    ○ Should you add a new class for labourer or just use the HourlyEmployee as an object?
*/

#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Payable
{
public:
    virtual double GetAmountToPay() const
    {
        throw invalid_argument("Not Implemented. Do Override\n");
    }

    virtual ~Payable()
    {

    }
};

class StaffMember: public Payable
{
private:
    int id;
    string name;
public:
    StaffMember(const string& name, const int& id): name(name), id(id)
    {

    }
    virtual double GetAmountToPay() const override
    {
        throw invalid_argument("Not Implemented. Do Override\n");
    }

    virtual string ToString() const
    {
        ostringstream oss;
        oss << "Emp name: " << name << " his salary = " << GetAmountToPay();
        return oss.str();
    }

    virtual ~StaffMember(){ }
};

class Employee: public StaffMember
{

};

class SalariedEmployee: public Employee
{
private:
    double salary;
public:




};
class HourlyEmployee: public Employee
{

};

class CommisionSalariedEmployee: public SalariedEmployee
{

};

class Volunteer: public StaffMember
{

};

class Item
{

};
class Book: public Item
{

};
class Food: public Item
{

};

class Invoice: public Payable
{
private:
    vector<Item*> items;
};

class Payroll
{
private:
    vector<Payable*> payables;
public:

};

int main()
{
    return 0;
}
