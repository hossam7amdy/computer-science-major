#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

class Zone
{
protected:
    string displayName;
    int offSet;
public:
    string getDisplayName() const {
        return this->displayName;
    }
    int getOffSet() const {
        return this->offSet;
    }
};
class ZoneUSEastern : public Zone
{
public:
    ZoneUSEastern(){
        displayName = "US/Eastern";
        offSet = -5;
    }
};
class ZoneUSCentral : public Zone
{
public:
    ZoneUSCentral(){
        displayName = "US/Central";
        offSet = -6;
    }
};
class ZoneUSMountain : public Zone
{
public:
    ZoneUSMountain(){
        displayName = "US/Mountain";
        offSet = -7;
    }
};
class ZoneUSPacific : public Zone
{
public:
    ZoneUSPacific(){
        displayName = "US/Pacific";
        offSet = -8;
    }
};

class ZoneFactory
{
public:
    Zone *CreateZone(const string &zoneId) {
        Zone *zone = nullptr;

        if(zoneId == "US/Eastern")
            zone = new ZoneUSEastern();
        else if(zoneId == "US/Central")
            zone = new ZoneUSCentral();
        else if(zoneId == "US/Mountain")
            zone = new ZoneUSMountain();
        else if(zoneId == "US/Pacific")
            zone = new ZoneUSPacific();

        return zone;
    }
};

class Calendar
{
protected:
    Zone *zone = nullptr;
public:
    void print() {
        if(zone == nullptr){
            cout << "Invalid type!!\n";
            return;
        }
        cout << "--- " << zone->getDisplayName() << " Calendar ---\n"
             << "Offset from GMT: " << zone->getOffSet() << "\n";
    }

    virtual void CreateCalendar(const vector<string> &appointments) = 0;
};

class PacificCalendar : public Calendar
{
public:
    PacificCalendar(ZoneFactory *zoneFactory) {
        zone = zoneFactory->CreateZone("US/Pacific");
    }

    void CreateCalendar(const vector<string> &appointments) override {
        cout << "--- Making The Calendar ---\n";
        for(auto app : appointments)
            cout << app << "\n";
    }
};

void CalendarTestDrive() {
    ZoneFactory *zoneFactory = new ZoneFactory();
    Calendar *calendar = new PacificCalendar(zoneFactory);
    vector<string> appts = {"appt 1", "appt 2"};
    calendar->CreateCalendar(appts);
    calendar->print();

    delete zoneFactory;
    delete calendar;
}

int main(){
    CalendarTestDrive();

    return 0;
}
