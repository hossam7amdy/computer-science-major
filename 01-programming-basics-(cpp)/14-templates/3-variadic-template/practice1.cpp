#include<iostream>
using namespace std;

//Parameter pack
template<typename ... SomeArgs>
void func1(SomeArgs ...args){
    int sz = sizeof...(args);
    cout << "size of args = " << sz <<"\n";
}
 //Parameter Pack with extra variable=(could be of any type).
template<typename SomeArgs, typename ...OtherArgs>
void func2(SomeArgs a, OtherArgs ...args){
    int sz = sizeof...(args);
    cout << a << " " << "size of args = " << sz << "\n";
}



int main(){
    string str = "Hossam";

    func1(1,2,3,4,5,6,7,8);
    func2(str,3,4,5);
    func2("Ahmed",str,3,4,5);
    return 0;
}
