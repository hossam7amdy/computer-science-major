#include<iostream>
#include<vector>
using namespace std;

class Iterator
{
public:
    virtual string next() = 0;
    virtual bool hasNext() const = 0;
};

class Menu
{
public:
    virtual Iterator *createIterator() const = 0;
};

class DinnerMenuIterator : public Iterator
{
private:
    // Make it object by reference to feel updates. Const to never change its content as printer
    const vector<string> &dinnerMenu;
    int position = 0;

public:
    DinnerMenuIterator(const vector<string> &dinnerMenu):
        dinnerMenu(dinnerMenu){
    }
    bool hasNext() const override {
        return position < (int)dinnerMenu.size();
    }
    string next() override {
        if(hasNext())
            return dinnerMenu[position++];
        return nullptr;
    }
};

class DinnerMenu : public Menu
{
private:
    vector<string> menu;
public:
    DinnerMenu() {
        addItem("Zucchini slice"), addItem("pumpkin soup"), addItem("Easy fried rice"), addItem("Classic shepherd's pie");
        addItem("Impossible quiche"), addItem("Our favourite lasagne"), addItem("Thai beef salad"), addItem("Curried sausages");
    }
    void addItem(const string &item) {
        menu.push_back(item);
    }
    Iterator *createIterator() const override {
        return new DinnerMenuIterator(menu);
    }
};

void ClientCode() {
    DinnerMenu menu;
    Iterator* dinnerMenuIterator = menu.createIterator();

    while(dinnerMenuIterator->hasNext())
        cout << dinnerMenuIterator->next() << "\n";


    cout << "\n======== adding new items ========\n";
    menu.addItem("San choy bau");
    menu.addItem("Easy butter chicken");
    menu.addItem("Basic chicken and vegetable stir-fry");
    menu.addItem("Pea & ham soup");

    while(dinnerMenuIterator->hasNext())
        cout << dinnerMenuIterator->next() << "\n";
}

int main(){
    ClientCode();

    return 0;
}
