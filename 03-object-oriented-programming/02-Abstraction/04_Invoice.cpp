#include "04_Invoice.h"

Invoice::Invoice(string _name, string _number, double _price, int _quantity){
    this->name = _name;
    this->number = _number;
    this->price = _price;
    this->quantity = _quantity;
}

//getters
string Invoice::getName()  { return name; }
string Invoice::getNumber()  {return number; }
double Invoice::getPrice()  { return price; }
int Invoice::getQuantity()  {return quantity; }

//setters
void Invoice::setName(string _name) { name = _name; }
void Invoice::setNumber(string _number) {number = _number; }
void Invoice::setPrice(double _price) { price = _price; }
void Invoice::setQuantity(int _quantity) { quantity = _quantity; }

//member function
string Invoice::ToString(){
    ostringstream oss;
    oss << name << ", " << number << ", " << price << ", " << quantity;
    return oss.str();
}

void Invoice::Print(){ cout << ToString() << endl;}
double Invoice::GetTotalPrice(){ return quantity * price ;}
