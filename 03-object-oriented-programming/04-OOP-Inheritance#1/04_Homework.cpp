#include<iostream>
using namespace std;

class Mammal{
    bool givesMilk();
    string makeSound();
    bool givesLiveBirth();
};

class Cat: Mammal{
    string makeSound();
};

class Monkey: Mammal{
    string makeSound();
};

class Whale: Mammal{
    string makeSound();
};

class Platypus: Mammal{ // but he doesn't giveLiveBirth() ?
    string makeSound();
};

int main(){
    return 0;
}
