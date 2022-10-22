#include<iostream>
using namespace std;

class FourWheels
{

};

class Engine
{

};

class Car: public Engine, public FourWheels
{

};

/*
Car "has an Engine and FourWheels"
its a composition not inherit relationship.
*/

/// Dr's NOTE
/*
The semantic is wrong. There is no clear and strong has-a relationship. Never do that in inheritance
A car is not an Engine. The car is not 4 wheels. Sometimes we can stack things like inheritance and it works for now (and be a big mess later)
The right relationship is composition. The car has an engine and 4-wheels
Prefer composition over inheritance most of the time, even if inheritance makes more sense unless it really should be an inheritance. Think twice.
*/

int main() {


	return 0;
}
