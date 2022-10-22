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
        times%=Size;
        while(times--)
            right_rotation();
    }
    // 4 0 1 2 3
    // (1) 4 0 2 3
    Type pop(int idx){
        if(idx>=Size)
            throw out_of_range("Invalid Position\n");
        Type temp = this->Get(idx);
        for(int i=idx; i<Size-1; i++)
            this->Set(i, this->Get(i+1));
        Size--;
        return temp;
    }
    // 10 20 30 40 50
    // 10 30 20 40 50
    int find_transposition(Type value){
        for(int i=0; i<Size; i++){
            if(this->Get(i)==value && i == 0)
                return i;
            else if(this->Get(i) == value){
                Type temp = this->Get(i-1);
                this->Set(i-1,this->Get(i));
                this->Set(i, temp);
                return i-1;
            }
        }
        return -1;
    }

};

int main(){
	int n = 5;
	Vector<int> v(n);
	for (int i = 0; i < n; ++i)
		v.Set(i, i);

	v.print();			// 0 1 2 3 4
	v.right_rotate(5 * 1000);
	v.print();			// 0 1 2 3 4
	v.right_rotate(2);
	v.print();			// 3 4 0 1 2
	v.left_rotation();
	v.print();			// 4 0 1 2 3

	int val = v.pop(2);
	cout << val << "\n";	// 1
	v.print();			// 4 0 2 3

	cout<<v.find_transposition(3)<<"\n";	// 2
	v.print();



    return 0;
}
