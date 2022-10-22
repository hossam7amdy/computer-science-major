/// Homework 1: Explain ATM-Machine UML
/*
● Like most of ATM Machine
    ○ You can check your balance
    ○ Withdraw or deposit money
■ E.g. from separate parts
*/

/// My Answer:
/*
1- ATM Machine, has-a (One):
    1- Screen
    2- CashDispenser
    3- KeyPad
    4- DepositSlot

2- ATM Machine can EXECUTE (Zero or More) Transactions (is-a)
            1- Withdrawal
                > Uses Keypad & CashDispenser
            2- Deposit
                > Uses keypad & DepositSlot
            3- BalanceInquiry

    1- Transactions USES:
        > BankDatabase: access/modify balances.
            - BankDatabase has-a (Zero or More) Accounts.
    2- Transactions USES:
        > Screen


3- ATM Machine also USES BankDatabase to Authenticates users
*/

#include<iostream>
#include<vector>
using namespace std;

class Keypad
{

};
class DepositSlot
{

};
class CashDispenser
{

};
class Screen
{

};
class ATM
{
    Keypad keypad;
    Screen screen;
    CashDispenser cashdispenser;
    DepositSlot sepositslot;
};
class Account
{

};
class BankDatabase
{
    vector<Account> accounts;
};
class Transaction
{

};
class Deposit: public Transaction
{

};
class Withdrawal: public Transaction
{

};
class BalanceInquiry: public Transaction
{

};


int main()
{
    return 0;
}
