#include<iostream>
using namespace std;

class LuckyNumber{
private:
    int number;

public:
    LuckyNumber();

    void SetNum(int number);
    void print();
};

LuckyNumber::LuckyNumber(){ number = rand()/10+100;}

void LuckyNumber::SetNum(int number){ this->number = number; }
void LuckyNumber::print(){ cout << number << endl; }

int main(){
    LuckyNumber LN;

    LN.print();
    LN.print();
    LN.SetNum(21);
    LN.print();

    // WOW Same addresses: 000000000061fde0
    printf("Function address :%p\n", &LuckyNumber::print);
    printf("Function address :%p\n", &LuckyNumber::SetNum);

    // So the hole struct reserve just one address in the memory? INTERESTING!

    ///Dr's Note:
    /*
	 * Each object variables will have different address in memory!
	 *
	 * However, function are common procedures
	 * So only one function is loaded in memory with common address
	 */

    return 0;
}
