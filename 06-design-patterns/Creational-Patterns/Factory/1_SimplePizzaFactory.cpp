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
class CheesePizza : public IPizza
{
public:
    CheesePizza() {
        name = "Cheese Pizza";
        dough = "Regular Crust";
        sauce = "Marinara Pizza Sauce";
        toppings.push_back("Fresh Mozzarella");
        toppings.push_back("Parmesan");
    }
};
class VeggiePizza : public IPizza
{
public:
    VeggiePizza() {
        name = "Veggie Pizza";
		dough = "Crust";
		sauce = "Marinara sauce";
		toppings.push_back("Shredded mozzarella");
		toppings.push_back("Grated parmesan");
		toppings.push_back("Diced onion");
		toppings.push_back("Sliced mushrooms");
		toppings.push_back("Sliced red pepper");
		toppings.push_back("Sliced black olives");
    }
};
class ClamPizza : public IPizza
{
public:
    ClamPizza() {
		name = "Clam Pizza";
		dough = "Thin crust";
		sauce = "White garlic sauce";
		toppings.push_back("Clams");
		toppings.push_back("Grated parmesan cheese");
    }
};
class PepperoniPizza : public IPizza
{
public:
    PepperoniPizza() {
		name = "Pepperoni Pizza";
		dough = "Crust";
		sauce = "Marinara sauce";
		toppings.push_back("Sliced Pepperoni");
		toppings.push_back("Sliced Onion");
		toppings.push_back("Grated parmesan cheese");
    }
};

class SimplePizzaFactory
{
public:
    IPizza *createPizza(const string &type) {
        IPizza *pizza = nullptr;

        if(type == "Cheese")
            pizza = new CheesePizza();
        else if(type == "Veggie")
            pizza = new VeggiePizza();
        else if(type == "Clam")
            pizza = new ClamPizza();
        else if(type == "Pepperoni")
            pizza = new PepperoniPizza();

        return pizza;
    }
};

class PizzaStore
{
private:
    SimplePizzaFactory *factory = nullptr;
    IPizza *pizza = nullptr;
public:
    PizzaStore(SimplePizzaFactory *factory):
        factory(factory){
    }

    IPizza *orderPizza(const string &name) {
        this->pizza = factory->createPizza(name);

        if(this->pizza == nullptr){
            cout << "Wrong Type!!\n";
            return nullptr;
        }

        this->pizza->prepare();
        this->pizza->bake();
        this->pizza->cut();
        this->pizza->box();

        return pizza;
    }
};

void ClientCode() {
    SimplePizzaFactory *factory = new SimplePizzaFactory();
    PizzaStore *store = new PizzaStore(factory);

    IPizza *pizza = store->orderPizza("Pepperoni");
    cout << "\nWe ordered a " << pizza->getName() << "\n";
    cout << pizza->toString();

    pizza = store->orderPizza("Cheese");
    cout << "\nWe ordered a " << pizza->getName() << "\n";
    cout << pizza->toString();

    pizza = store->orderPizza("Clam");
    cout << "\nWe ordered a " << pizza->getName() << "\n";
    cout << pizza->toString();

    pizza = store->orderPizza("Pepperoni");
    cout << "\nWe ordered a " << pizza->getName() << "\n";
    cout << pizza->toString();

    delete factory;
    delete store;
}

int main(){
    ClientCode();

    return 0;
}
