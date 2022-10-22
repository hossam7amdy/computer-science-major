#include<iostream>
#include<fstream> // Read and write from a text
using namespace std;



int main(){
    ///Read a hole file be getline function.
    string path = "C:\\Users\\hossa\\Downloads\\Hossam\\Computer Science\\Mastering C++ (Udemy)\\00 My Code\\18_Files-and-Streams\\test1.txt";
    fstream file_handler(path.c_str());

    if(file_handler.fail()){
        cout << "Error can't read from this file.\n";
        return 0;
    }
    string line;

    while(getline(file_handler, line))
        cout << line << "\n";

    file_handler.close();

    return 0;
}
