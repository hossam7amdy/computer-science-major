#include<iostream>
#include<vector>
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
    void right_rotation(){
        Type temp = myVector[Size-1];
        for(int i=Size-2; i>=0; --i)
            myVector[i+1] = myVector[i];
        myVector[0] = temp;
    }
    void left_rotation(){
        Type temp = myVector[0];
        for(int i=0; i<Size-1; ++i)
            myVector[i] = myVector[i+1];
        myVector[Size-1] = temp;
    }
    // 0 1 2 3 4
    // 3 4 0 1 2
    void right_rotate(int times){

        if(times==Size)
            return;

        if(times<2){
            right_rotation();
            return;
        }

        vector<Type> temp;
        for(int i=times; i<Size; i++)
            temp.push_back(this->Get(i));

        for(int i=0; i<times; i++)
            temp.push_back(this->Get(i));

        for(int i=0; i<Size; i++)
            this->Set(i,temp[i]);
    }

};

int main(){
    int n = 5;
    Vector<int> v(n);
    for(int i=0; i<n; i++)
        v.Set(i,i);

    v.right_rotate(2);
    v.print();


    return 0;
}
