#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

class IPizza
{
protected:
    string name;
    string sauce;
    string dough;
    vector<string> toppings;
public:
    const string getName() const {
        return this->name;
    }
    void prepare() {
        cout << "Preparing " + name << "\n";
    }
    void bake() {
        cout << "Baking " + name << "\n";
    }
    void cut() {
        cout << "Cutting " + name << "\n";
    }
    void box() {
        cout << "Boxing " + name << "\n";
    }
    string toString() const {
        ostringstream oss;
        oss << "--- " << name << " ---\n"
            << dough << "\n"
            << sauce + "\n";
        for(auto topp : toppings)
            oss << topp << "\n";
        return oss.str();
    }
};
class NYStyleCheesePizza : public IPizza
{
public:
    NYStyleCheesePizza() {
        name = "NY Cheese Pizza";
        dough = "NY Regular Crust";
        sauce = "NY Marinara Pizza Sauce";
        toppings.push_back("NY Fresh Mozzarella");
        toppings.push_back("NY Parmesan");
    }
};
class NYStyleVeggiePizza : public IPizza
{
public:
    NYStyleVeggiePizza() {
        name = "NY Veggie Pizza";
		dough = "NY Crust";
		sauce = "NY Marinara sauce";
		toppings.push_back("NY Shredded mozzarella");
		toppings.push_back("NY Grated parmesan");
		toppings.push_back("NY Diced onion");
		toppings.push_back("NY Sliced mushrooms");
		toppings.push_back("NY Sliced red pepper");
		toppings.push_back("NY Sliced black olives");
    }
};
class NYStyleClamPizza : public IPizza
{
public:
    NYStyleClamPizza() {
		name = "NY Clam Pizza";
		dough = "NY Thin crust";
		sauce = "NY White garlic sauce";
		toppings.push_back("NY Clams");
		toppings.push_back("NY Grated parmesan cheese");
    }
};
class NYStylePepperoniPizza : public IPizza
{
public:
    NYStylePepperoniPizza() {
		name = "NY Pepperoni Pizza";
		dough = "NY Crust";
		sauce = "NY Marinara sauce";
		toppings.push_back("NY Sliced Pepperoni");
		toppings.push_back("NY Sliced Onion");
		toppings.push_back("NY Grated parmesan cheese");
    }
};

class ChicagoStyleCheesePizza : public IPizza
{
public:
    ChicagoStyleCheesePizza() {
        name = "Chicago Style Cheese Pizza";
        dough = "Chicago Style Regular Crust";
        sauce = "Chicago Style Marinara Pizza Sauce";
        toppings.push_back("Chicago Style Fresh Mozzarella");
        toppings.push_back("Chicago Style Parmesan");
    }
};
class ChicagoSyleVeggiePizza : public IPizza
{
public:
    ChicagoSyleVeggiePizza() {
        name = "Chicago Style Veggie Pizza";
		dough = "Chicago Style Crust";
		sauce = "Chicago Style Marinara sauce";
		toppings.push_back("Chicago Style Shredded mozzarella");
		toppings.push_back("Chicago Style Grated parmesan");
		toppings.push_back("Chicago Style Diced onion");
		toppings.push_back("Chicago Style Sliced mushrooms");
		toppings.push_back("Chicago Style Sliced red pepper");
		toppings.push_back("Chicago Style Sliced black olives");
    }
};
class ChicagoSyleClamPizza : public IPizza
{
public:
    ChicagoSyleClamPizza() {
		name = "Chicago Style Clam Pizza";
		dough = "Chicago Style Thin crust";
		sauce = "Chicago Style White garlic sauce";
		toppings.push_back("Chicago Style Clams");
		toppings.push_back("Chicago Style Grated parmesan cheese");
    }
};
class ChicagoSylePepperoniPizza : public IPizza
{
public:
    ChicagoSylePepperoniPizza() {
		name = "Chicago Style Pepperoni Pizza";
		dough = "Chicago Style Crust";
		sauce = "Chicago Style Marinara sauce";
		toppings.push_back("Chicago Style Sliced Pepperoni");
		toppings.push_back("Chicago Style Sliced Onion");
		toppings.push_back("Chicago Style Grated parmesan cheese");
    }
};

class PizzaStore
{
public:
    IPizza *orderPizza(const string &name) {
        IPizza *pizza = createPizza(name);

        if(pizza == nullptr){
            cout << "Wrong Type!!\n";
            return nullptr;
        }

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }
    virtual IPizza *createPizza(const string &type) = 0;
};

class NYPizzaStore : public PizzaStore
{
public:
    IPizza *createPizza(const string &type) {
        IPizza *pizza = nullptr;

        if(type == "Cheese")
            pizza = new NYStyleCheesePizza();
        else if(type == "Veggie")
            pizza = new NYStyleVeggiePizza();
        else if(type == "Clam")
            pizza = new NYStyleClamPizza();
        else if(type == "Pepperoni")
            pizza = new NYStylePepperoniPizza();

        return pizza;
    }
};

class ChicagoPizzaStore : public PizzaStore
{
public:
    IPizza *createPizza(const string &type) {
        IPizza *pizza = nullptr;

        if(type == "Cheese")
            pizza = new ChicagoStyleCheesePizza();
        else if(type == "Veggie")
            pizza = new ChicagoSyleVeggiePizza();
        else if(type == "Clam")
            pizza = new ChicagoSyleClamPizza();
        else if(type == "Pepperoni")
            pizza = new ChicagoSylePepperoniPizza();

        return pizza;
    }
};

void NYClientCode() {
    cout << "--- Testing NY Code ---\n";
    PizzaStore *store = new NYPizzaStore();

    IPizza *pizza = store->orderPizza("Pepperoni");
    cout << "\nWe ordered a " << pizza->getName() << "\n";
    cout << pizza->toString();

    delete store;
}

void ChicagoClientCode() {
    cout << "\n--- Testing Chicago Code ---\n";
    PizzaStore *store = new ChicagoPizzaStore();

    IPizza *pizza = store->orderPizza("Cheese");
    cout << "\nWe ordered a " << pizza->getName() << "\n";
    cout << pizza->toString();

    delete store;
}

int main(){
    NYClientCode();
    ChicagoClientCode();

    return 0;
}
