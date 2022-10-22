/// Homework 1: Extended Company Payroll
/*
● We need to extend the previous company payroll
    ○ In practice, we may need to verify invoices. Sometimes an:
■ invoice is out-of-date relative to some deals with suppliers
■ Computed taxes doesn’t utilize some advantages in the country
    ○ So there are several validation rules
■ In future, more rules might be added (we need generic code)
■ You don’t need to care about validation rules logic
    ○ A Validator Group consists of a subset the available validation rules
■ E.g. Mandatory-Validator has a very few validation rules to be fast
■ Based on configuration, a specific Validator Group is in use
    ○ An invoice must pass all validation rules in a validator group
*/

#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Payable
{
public:
    virtual double GetAmountToPay() const = 0;
    virtual ~Payable()
    {

    }
};

class StaffMember: public Payable
{
private:
    string name;
    string address;
public:
};

class Employee: public StaffMember
{
private:
    string day_to_pay;
public:
};

class HourlyEmployee: public Employee
{
private:
    int total_worked_hours;
    double salary_per_hour;
public:
    virtual double GetAmountToPay() const override
    {
        cout << "HourlyWorker\n";
        return total_worked_hours * salary_per_hour;
    }
};

class SalariedEmployee: public Employee
{
private:
    double monthly_salary;
public:
    virtual double GetAmountToPay() const override
    {
        cout << "SalariedEmployee\n";
        return monthly_salary;
    }
};

class CommisionSalariedEmployee: public SalariedEmployee
{
private:
    double commition_rate;
public:
    virtual double GetAmountToPay() const
    {
        cout << "CommitionSalariedEmoployee\n";
        return (SalariedEmployee::GetAmountToPay() * commition_rate) + SalariedEmployee::GetAmountToPay();
    }
};

class Volunteer: public StaffMember
{
private:
    double curr_payment;
public:
    virtual double GetAmountToPay() const override
    {
        cout << "Volunteered\n";
        return curr_payment;
    }
};

class Item
{
private:
    string item_name;
    double price;
    int quantity;
public:
    double getPrice() const
    {
        return price * quantity;
    }
};
class Book: public Item
{
private:
    string auther_name;
};
class Food: public Item
{
private:
    string expire_date;
};

class Invoice: public Payable
{
private:
    vector<Item*> items;
public:
    virtual double GetAmountToPay() const
    {
        double sum = 0;
        for(const auto &item : items)
            sum += item->getPrice();
        return sum;
    }
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
