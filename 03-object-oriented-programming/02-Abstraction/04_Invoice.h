#include<sstream>
#include<string>
#include<iostream>
using namespace std;

#ifndef 04_INVOICE_H_INCLUDED
#define 04_INVOICE_H_INCLUDED

class Invoice{
private:
    string name;
    string number;
    double price;
    int quantity;

public:
    Invoice(string _name, string _number, double _price, int _quantity);

    //getters
    string getName();
    string getNumber();
    double getPrice();
    int getQuantity();

    //setters
    void setName(string _name);
    void setNumber(string _number);
    void setPrice(double _price);
    void setQuantity(int _quantity);

    //member function
    string ToString();
    void Print();
    double GetTotalPrice();
};

#endif // 04_INVOICE_H_INCLUDED
