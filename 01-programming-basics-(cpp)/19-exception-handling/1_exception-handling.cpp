#include<iostream>
#include<vector>
using namespace std;

struct BankAccount{
    int wallet;

    BankAccount(){ wallet = 1000; }

    bool PayBill(int bill_value){
        if(bill_value<0)
            throw invalid_argument("Bill value can't be negative.\n");

        if(wallet>=bill_value){
            wallet-=bill_value;
            return true;
        }
        return false;
    }
};


int main(){
    BankAccount myacc;
    try{
    cout << myacc.PayBill(100) << endl;
    cout << myacc.PayBill(350) << endl;
    cout << myacc.PayBill(100) << endl;
    cout << myacc.PayBill(500) << endl;
    cout << myacc.PayBill(200) << endl;
    }catch(invalid_argument &e){
        cout << "Caught an exception: " << e.what() << "\n";
        //throw e; // don't want to handle
    }

    int n = 20;
    vector<int> v(n);
    cout << v.at(25);



    return 0;
}
