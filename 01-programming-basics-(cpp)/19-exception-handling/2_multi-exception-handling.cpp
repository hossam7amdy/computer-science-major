#include<iostream>
using namespace std;

int* CreateMobileArray(int n){
    if(n<=0)
        throw 7;
    if(n>1000)
        throw runtime_error("To big length for an array.\n");

    int* arr = new int[n];
    return arr;
}

int main(){
    int* p = nullptr;
    try{
        p = CreateMobileArray(1000000000);
    } catch(int &error_code){
        cout << "Error code: " << error_code << endl;
    } catch(runtime_error &e){
        cout << "Runtime error: " << e.what();
    } catch(...){
        cout << "Unknown Error.\n";
    }

    if(p!=nullptr){
        delete[] p;
        p = nullptr;
    }

    return 0;
}
