#include<iostream>
using namespace std;

class Duck
{
public:
    virtual void fly() const = 0;
    virtual void quack() const = 0;
    virtual void swim() {
        cout << "All ducks float, even decoys!\n";
    }
    virtual void display() const = 0;
};

class Drone
{
public:
    virtual void beeb() const = 0;
    virtual void spin_rotors() const = 0;
    virtual void taking_off() const = 0;
    virtual void display() const = 0;
};
class SuperDrone : public Drone
{
public:
    void beeb() const override{
        cout << "Beeb beeb beeb ... \n";
    }
    void spin_rotors() const override {
        cout << "Rotors are spinning .... ";
    }
    void taking_off() const override {
        cout << "Taking off\n";
    }
    void display() const override {
        cout << "I am a super Drone weeeee!!\n";
    }
};

class DroneAdaper : public Duck
{
private:
    Drone *drone{};
public:
    DroneAdaper(Drone *drone){
        this->drone = drone;
    }
    void quack() const override {
        drone->beeb();
    }
    void fly() const override {
        drone->spin_rotors();
        drone->taking_off();
    }
    void display() const override {
        drone->display();
    }
};

void testDuck(Duck *duck){
    duck->display();
    duck->fly();
    duck->quack();
}

void DuckSimulator(){
    Drone *drone = new SuperDrone();
    Duck *droneAdapter = new DroneAdaper(drone);

    testDuck(droneAdapter);

    delete drone;
    delete droneAdapter;
    cout << "==================\n";
}

int main(){
    DuckSimulator();

    return 0;
}
