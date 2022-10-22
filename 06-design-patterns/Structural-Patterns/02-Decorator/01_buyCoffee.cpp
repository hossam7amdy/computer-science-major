#include<iostream>
using namespace std;

class IBeverage
{
private:
    string description {"Unknown Beverage"};
public:
    IBeverage(){ }
    IBeverage(const string &description):
        description(description){
    }
    virtual string getDescription() {
        return description;
    }
    virtual float getCost() = 0;
};

class HouseBlend : public IBeverage
{
public:
    HouseBlend():
        IBeverage("House Blend Coffee"){
    }
    string getDescription() override {
        return IBeverage::getDescription();
    }
    float getCost() override {
        return 1.49;
    }
};
class DarkRoast : public IBeverage
{
public:
    DarkRoast():
        IBeverage("Dark Roast Coffee"){
    }
    string getDescription() override {
        return IBeverage::getDescription();
    }
    float getCost() override {
        return 2.00;
    }
};
class Decaf : public IBeverage
{
public:
    Decaf():
        IBeverage("Decaf Coffee"){
    }
    string getDescription() override {
        return IBeverage::getDescription();
    }
    float getCost() override {
        return 2.25;
    }
};
class Espresso : public IBeverage
{
public:
    Espresso():
        IBeverage("Espresso Coffee"){
    }
    string getDescription() override {
        return IBeverage::getDescription();
    }
    float getCost() override {
        return 4.00;
    }
};

class ICondimentDecorator : public IBeverage
{
public:
    string getDescription() override = 0;
};
class Soy : public ICondimentDecorator
{
private:
    IBeverage *beverage{};
public:
    Soy(IBeverage *beverage):
        beverage(beverage) {
    }
    string getDescription() override {
        return beverage->getDescription() + " + Soy";
    }
    float getCost() override {
        return beverage->getCost() + 0.20;
    }
};
class Milk : public ICondimentDecorator
{
private:
    IBeverage *beverage{};
public:
    Milk(IBeverage *beverage):
        beverage(beverage){
    }
    string getDescription() override {
        return beverage->getDescription() + " + Milk";
    }
    float getCost() override {
        return beverage->getCost() + 0.10;
    }
};
class Whip : public ICondimentDecorator
{
private:
    IBeverage *beverage;
public:
    Whip(IBeverage *beverage):
        beverage(beverage){
    }
    string getDescription() override {
        return beverage->getDescription() + " + Whip";
    }
    float getCost() override {
        return beverage->getCost() + 0.10;
    }
};
class Mocha : public ICondimentDecorator
{
private:
    IBeverage *beverage;
public:
    Mocha(IBeverage *beverage):
        beverage(beverage){
    }
    string getDescription() override {
        return beverage->getDescription() + " + Mocha";
    }
    float getCost() override {
        return beverage->getCost() + 0.15;
    }
};

void testBuyCoffee() {
    IBeverage *beverage = new Espresso();

    beverage = new Soy(beverage);
    beverage = new Milk(beverage);
    beverage = new Mocha(beverage);
    beverage = new Whip(beverage);

    cout << "Enjoy your " << beverage->getDescription()
         << " it costs you $" << beverage->getCost() << "\n";
}

int main(){
    testBuyCoffee();

    return 0;
}
