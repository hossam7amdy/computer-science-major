#include <iostream>
using namespace std;

/*
● Develop a function that do reverse for the string. Function is:
● string reverse_str(const string & str);
    ○ Don’t try to change str content or you will get compilation error
*/

string reverse_str(const string & str){
    string reversed = "";
    for(int i=(int)str.size(); i>=0; i--)
        reversed += str[i-1];
    return reversed;
}


int main() {
    cout << reverse_str("Hossam Hamdy");

	return 0;
}
