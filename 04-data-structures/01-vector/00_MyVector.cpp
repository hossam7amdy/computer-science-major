#include<iostream>
#include<algorithm>
using namespace std;

template<class Type>
class Vector{
private:
    Type * myVector = nullptr;
    int Size {0};
    int Capacity {};

    void expand_capacity() {
        // create: new array
        Capacity *= 2;
        Type * ptr = new Type[Capacity];
        // copy: old values
        for(int i=0; i<Size; ++i)
            ptr[i] = myVector[i];
        // swap: with the new
        swap(myVector, ptr);
        // Delete: created one
        delete[] ptr;
    }
public:
    Vector(int Size): Size(Size){
        if(Size<0)
            Size = 1;
        Capacity = Size * 2;
        myVector = new Type[Capacity] {};
    }
    Vector(const Vector&) = delete;
    void operator=(const Vector&) = delete;
    ~Vector(){
        delete[] myVector;
        cout << "Bye\n";
        myVector = nullptr;
    }
    Type Get(int idx) const {
        if(0>idx || idx>=Size)
            return -1;
        return myVector[idx];
    }
    void Set(int idx, Type value){
        if(0<=idx && idx<Size){
            myVector[idx] = value;
            return;
        }
        cout << "Invalid Position\n";
    }
    void print() const {
        for(int i=0; i<Size; ++i)
            cout << myVector[i] << " ";
        cout << "\n";
    }
    int Find(Type value) const {
        for(int i=0; i<Size; ++i){
            if(myVector[i]==value)
                return i;
        }
        return -1;
    }
    Type get_front() const {
        return myVector[0];
    }
    Type get_back() const {
        return myVector[Size-1];
    }
    void add_back(Type value){
        if(Size==Capacity)
            expand_capacity();

        // add: new element
        myVector[Size++] = value;
    }
    void Insert(int idx, Type value){
        if(Size==Capacity)
            expand_capacity();

        for(int i=Size-1; i>=idx; --i)
            myVector[i+1] = myVector[i];
        myVector[idx] = value;
        Size++;
    }

};

int main(){
    Vector<int> v(10);
    for(int i=0; i<5; ++i)
        v.Set(i,i+1);
    v.print();
    cout << v.Get(5) << " " << v.Get(11) << "\n";

    v.add_back(11);
    v.print();

    v.Insert(0, 10);
    v.print();

    Vector<string> v2(5);
    v2.add_back("Hossam");
    v2.add_back("Ahmed");
    v2.add_back("Emad");
    v2.print();

    return 0;
}
