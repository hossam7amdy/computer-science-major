#include<iostream>
using namespace std;

/*
● Consider following enhancements
● 1) Provide Copy Constructor
● 2) In get method, make sure no out of index access
● 3) provide set method to change array content
● 4) method to get array length
*/

class MyVector{
private:
    int *arr;
    int len = 100;
public:
    MyVector(int len, int default_value = 0){
        this->len = len;
        this->arr = new int[len];

        for(int i=0; i<len; i++)
            this->arr[i] = default_value;
    }

    MyVector(const MyVector &v){
        this->len = v.len;
        this->arr = new int[len];

        for(int i=0; i<len; i++)
            this->arr[i] = v.arr[i];
    }

    ~MyVector(){
        cout << "Done\n";
        delete[] this->arr;
    }

    void SetValue(int pos, int value=0){
        if(0>pos || pos>=len)
           cout << "Invalid Position\n";
        else
            arr[pos] = value;
    }

    const int GetValue(int pos){
        if(pos>=len || pos<0){
            cout << "Invalid Position\n";
            return -1;
        }
        return this->arr[pos];
    }

    // Breaks Data-Hiding concept. User has access to private data and can corrupt the system
    // To solve this I used const!
    const int& GetLen(){
        return this->len;
    }
};

int main(){
	MyVector v(10, 12345);

	cout<<v.GetValue(4)<<"\n";

	// User access array length and set to zero!
    // CE: binding reference discards qualifiers
	// So we are save
	int &l = v.GetLen();

	l = 0;

	cout<<v.GetValue(4)<<"\n";


    return 0;
}
