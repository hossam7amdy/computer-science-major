#include<iostream>
#include<assert.h>
using namespace std;

template<class type>
class Stack{
private:
    type *Array{ };
    int length;
    int capacity;
public:
    Stack(const int &capacity):
        capacity(capacity), length(-1) {
            Array = new type[capacity];
    }

    void push(const type &data){
        assert(!isFull());
        Array[++length] = data;
    }
    bool isEmpty(){
        return length == -1;
    }
    bool isFull(){
        return length == capacity-1;
    }
    type top(){
        assert(!isEmpty());
        return Array[length];
    }
    type pop(){
        assert(!isEmpty());
        return Array[length--];
    }
    void Display() const {
        for(int i=length; i>=0; i--)
            cout << Array[i] << " ";
        cout << "\n";
    }
    void DisplayReversed(){
        for(int i=0; i<=length; i++)
            cout << Array[i] << " ";
        cout << "\n";
    }
    ~Stack(){ // time O(n) - memory O(1)
        delete[] Array;
    }
};

void asteroidCollision(int arr[], const int &sz){
    Stack<int> st(sz);


    for(int i=0; i<sz; i++){
        bool is_exploded = false;
        while(!st.isEmpty() && st.top()>0 && arr[i]<0){
            if(st.top() == -arr[i])
                st.pop();
            else if(st.top() < -arr[i]){
                st.pop();
                continue;
            }
            is_exploded = true;
            break;
        }
        if(!is_exploded)
            st.push(arr[i]);
    }
    st.DisplayReversed();
}


int main(){
    int arr[3] {10,2,-5};
	asteroidCollision(arr, 3);

    return 0;
}
