#include<iostream>
#include<list>
using namespace std;

class IObserver
{
public:
    virtual ~IObserver(){};
    virtual void update(const int &message) = 0;
};

class ISubject
{
public:
    virtual ~ISubject(){};
    virtual void registerObserver(IObserver *observer) = 0;
    virtual void removeObserver(IObserver *observer) = 0;
    virtual void notifyObservers() = 0;
};

class Subject : public ISubject
{
private:
    int value;
    list<IObserver*> observers;
public:
    virtual ~Subject() {
        cout << "Goodbye, I was the Subject.\n";
    }
    void registerObserver(IObserver *observer) override {
        this->observers.push_back(observer);
    }
    void removeObserver(IObserver *observer) override {
        observers.remove(observer);
    }
    void notifyObservers() override {
        for(auto observer : observers)
            observer->update(value);
    }
    void setValue(const int &value) {
        this->value = value;
        notifyObservers();
    }
    void HowManyObserver() {
        cout << "There are " << (int)observers.size() << " observers in the list.\n";
    }
};

class Observer : public IObserver
{
private:
    int message{};
    Subject &subject;
public:
    Observer(Subject &subject):
        subject(subject){
            subject.registerObserver(this);
    }
    void update(const int &message) override {
        this->message = message;
        display();
    }
    void removeMeFromTheList() {
        subject.removeObserver(this);
    }
    void display() {
        cout << "My value is: " << message << "\n";
    }
};

void testObserver() {
    Subject *subject = new Subject;

    Observer *observer1 = new Observer(*subject);
    Observer *observer2 = new Observer(*subject);
    Observer *observer3 = new Observer(*subject);
    Observer *observer4 = new Observer(*subject);
    Observer *observer5 = new Observer(*subject);

    subject->HowManyObserver();
    subject->setValue(10);

    subject->removeObserver(observer1);
    delete observer1;

    subject->HowManyObserver();
    subject->setValue(12);
}

int main(){
    testObserver();

    return 0;
}
