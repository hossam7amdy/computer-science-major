#include<iostream>
#include<list>
using namespace std;

struct WeatherInfo{
    int temperature{35};
    int windSpeed{10};
    int pressure{15};
};

class IObserver
{
public:
    virtual ~IObserver(){};
    virtual void update(const WeatherInfo &info) = 0;
    virtual void removeMeFromTheList() = 0;
};

class ISubject
{
public:
    virtual ~ISubject(){};
    virtual void registerObserver(IObserver *observer) = 0;
    virtual void removeObserver(IObserver *observer) = 0;
    virtual void notifyObservers() = 0;
};

class WeatherStation : public ISubject
{
private:
    WeatherInfo info;
    list<IObserver*> observers;
public:
    void registerObserver(IObserver *observer) override {
        if(observer)
            this->observers.push_back(observer);
    }
    void removeObserver(IObserver *observer) override {
        this->observers.remove(observer);
    }
    void notifyObservers() override {
        for(auto observer : observers)
            observer->update(info);
    }
    void setTemperature(const int &temperature){
        this->info.temperature = temperature;
        notifyObservers();
    }
    void setWindSpeed(const int &windSpeed){
        this->info.windSpeed = windSpeed;
        notifyObservers();
    }
    void setPressure(const int &pressure){
        this->info.pressure = pressure;
        notifyObservers();
    }
};

class UserInterface : public IObserver
{
    WeatherInfo info;
    ISubject &weatherStation;
public:
    UserInterface(ISubject &weatherStation):
        weatherStation(weatherStation) {
            weatherStation.registerObserver(this);
        }
    void update(const WeatherInfo &info) {
        this->info = info;
        display();
    }
    void removeMeFromTheList() override {
        weatherStation.removeObserver(this);
    }
    void display() {
        cout << "\n --- SCREEN ---\n";
        cout << "Today's Temperature: " << info.temperature
             << "\n with Wind Speed at: " << info.windSpeed
             << "\n and Pressure: " << info.pressure << "\n";
    }
};

class Logger : public IObserver
{
    WeatherInfo info;
    ISubject &weatherStation;
public:
    Logger(ISubject &weatherStation):
        weatherStation(weatherStation) {
            weatherStation.registerObserver(this);
        }
    void update(const WeatherInfo &info) {
        this->info = info;
        log();
    }
    void removeMeFromTheList() {
        weatherStation.removeObserver(this);
    }
    void log() {
        cout << "\n--------- LOGGING -----------\n";
        cout << "Today's Temperature: " << info.temperature
             << "\n with Wind Speed at: " << info.windSpeed
             << "\n and Pressure: " << info.pressure << "\n";
    }
};

class AlertSystem : public IObserver
{
    WeatherInfo info;
    ISubject &weatherStation;
public:
    AlertSystem(ISubject &weatherStation):
        weatherStation(weatherStation) {
            weatherStation.registerObserver(this);
        }
    void update(const WeatherInfo &info) {
        this->info = info;
        alert();
    }
    void removeMeFromTheList() override {
        weatherStation.removeObserver(this);
    }
    void alert() {
        if(info.temperature > 30)
            cout << "\n--- No need for Coat ---\n";
        else
            cout << "\n--- Please take your Coat ---\n";

        cout << "Today's Temperature: " << info.temperature
             << "\n with Wind Speed at: " << info.windSpeed
             << "\n and Pressure: " << info.pressure << "\n";
    }
};

void testWeatherStation() {
    WeatherStation *station = new WeatherStation;

    IObserver *o1 = new UserInterface(*station);
    IObserver *o2 = new Logger(*station);
    IObserver *o3 = new AlertSystem(*station);
    IObserver *o4;
    IObserver *o5;

    station->setTemperature(45);
    station->setPressure(35);
    station->setWindSpeed(55);

    o4 = new UserInterface(*station);
    station->setTemperature(35);
    o4->removeMeFromTheList();

    o5 = new Logger(*station);
    station->setPressure(150);


    delete station;
    delete o1;
    delete o2;
    delete o3;
    delete o4;
    delete o5;
}

int main(){
    testWeatherStation();

    cout << "NO RTE\n";
    return 0;
}
