/// Homework 3: Payment Services
/*
● Craigslist website (classified-ads) is adding new feature for customers payment.
    ○ There are a lot of API to use. Each API has fees in some style
■ E.g. 1 dollar per 25 payments
■ The rules might change from time to time
■ New APIs with new fees might be available on web
■ All APIs provide similar functionalities, but different interfaces
    ○ At the moment, developers want to support to payment methods: PayPal and Stripe
■ In future, more could be added if they are cheaper
    ○ The site code to pay something shouldn’t depend on specific API.
■ Otherwise, a lot of code has to be changed with every a change in the selected API
*/

#include<iostream>
#include<vector>
using namespace std;

// PayPalCreditCard and PayPalOnlinePaymentAPI are NOT our code. They are Paypal API.
// We have to use them to be able to call PayPal service


class PayPalCreditCard {
public:
	string name;
	string address;
	string id;
	string expire_date;
	int ccv;
};

class PayPalOnlinePaymentAPI {
public:
	void SetCardInfo(const PayPalCreditCard* const card) {
	}
	bool MakePayment(double money) {
		return true;
	}
};

class StripeUserInfo {
public:
	string name;
	string address;
};

class StripeCardInfo {
public:
	string id;
	string expire_date;
};

class StripePaymentAPI {
public:
	bool static WithDrawMoney(StripeUserInfo user,
							  StripeCardInfo card,
							  double money) {
		return true;
	}
};

class TransactionInfo {
public:
	double required_money_amount;
	string name;
	string address;
	string id;
	string expire_date;
	int ccv;
};

class Craigslist {
	public:
	bool Pay(TransactionInfo) {
		//TODO: generic (no nothing about Paypal)
	}
};


int main()
{
	return 0;
}
