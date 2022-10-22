#include<iostream>
#include<fstream> // Read and write from a text
using namespace std;



int main(){
    ///reading and writing in the same file, we can switch also.
    bool append = true;
    auto status = ios::in | ios::out | ios::app;
    if(!append)
        status = ios::in | ios::out | ios::trunc; //overwrite

    string path = "C:\\Users\\hossa\\Downloads\\Hossam\\Computer Science\\Mastering C++ (Udemy)\\00 My Code\\18_Files-and-Streams\\test1.txt";
    fstream file_handler(path.c_str(), status);

    if(file_handler.fail()){
        cout << "Error can't read from this file.\n";
        return 0;
    }
    string st, sec;
    file_handler >> st >> sec;
    cout << st << " " << sec;

    file_handler.clear();

    file_handler << "Torad\n";

    file_handler.close();

    return 0;
}
