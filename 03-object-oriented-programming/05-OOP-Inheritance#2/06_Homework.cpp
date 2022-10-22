#include<iostream>
#include<string>
using namespace std;

class DecorationgString: public string
{
private:
    using string::string;
public:

    // using std::string::operator=;
    void decorate()
    {
        string s = *this;
        s = "<<[[" + s + "]]>>";

        //*this = s;
        this->assign(s);

        // You can't just use: *this = str;
		// as this is = assignment operator (later to study)
		// The default assignment operator = now is for DecoratedString not std::string
		// If you want it possible, add also using std::string::operator=;
    }
};

int main()
{
    DecorationgString str("I am learning CS");

    str.decorate();
    cout << str << endl;
    cout << (str == "<<[[I am learning CS]]>>");
    return 0;
}
