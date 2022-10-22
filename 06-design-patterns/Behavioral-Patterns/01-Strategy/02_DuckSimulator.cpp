#include<iostream>
using namespace std;

class FlyBehavoir
{
public:
    virtual void fly() const = 0;
};
class FlyWithWings : public FlyBehavoir
{
 public:
     void fly() const override {
        cout << "I'm flying!!\n";
     }
};
class FlyNoWay : public FlyBehavoir
{
public:
    void fly() const override {
        cout << "I can't fly\n";
    }
};

class QuackBehavoir
{
public:
    virtual void quack() const = 0;
};
class Quack : public QuackBehavoir
{
public:
    void quack() const override {
        cout << "Quack\n";
    }
};
class Squeak : public QuackBehavoir
{
public:
    void quack() const override {
        cout << "squeeeeaaaak\n";
    }
};

class Duck
{
private:
    FlyBehavoir *flyBehavoir{};
    QuackBehavoir *quackBehavoir{};
public:
    void setFlyBehavoir(FlyBehavoir *behavoir){
        if(flyBehavoir)
            delete flyBehavoir;
        this->flyBehavoir = behavoir;
    }
    void setQuackBehavoir(QuackBehavoir *behavoir){
        if(quackBehavoir)
            delete quackBehavoir;
        this->quackBehavoir = behavoir;
    }
    void fly() {
        flyBehavoir->fly();
    }
    void quack() {
        quackBehavoir->quack();
    }
    void swim() {
        cout << "All ducks float, even decoys!\n";
    }
    virtual void display() const = 0;
    ~Duck(){
        if(flyBehavoir)
            delete flyBehavoir;
        if(quackBehavoir)
            delete quackBehavoir;
    }
};

class MallardDuck : public Duck
{
public:
    MallardDuck(){
        setFlyBehavoir(new FlyWithWings());
        setQuackBehavoir(new Quack());
    }
    void display() const override {
        cout << "I am a Mallard Duck\n";
    }
};
class ReadHead : public Duck
{
public:
    ReadHead(){
        setFlyBehavoir(new FlyNoWay());
        setQuackBehavoir(new Squeak());
    }
    void display() const override {
        cout << "I am a Mallard Duck\n";
    }
};

void testMallardDuck(){
    MallardDuck *duck = new MallardDuck();
    duck->fly();
    duck->quack();
    duck->swim();
    duck->display();

    delete duck;
}

void testReadHeadDuck(){
    ReadHead *duck = new ReadHead();
    duck->fly();
    duck->quack();
    duck->swim();
    duck->display();

    delete duck;
}

int main(){
    testMallardDuck();
    testReadHeadDuck();

    return 0;
}
