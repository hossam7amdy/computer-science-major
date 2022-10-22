#include<iostream>
using namespace std;

class ArrayBasedStack{
private:
    int *arr{ };
    int length{ };
    int capacity;
public:
    ArrayBasedStack(const int &capacity): // time O(n) - memory O(n)
        capacity(capacity){
            if(capacity>0)
                arr = new int[capacity];
    }

    void push(const int &data){
        if(length==capacity)
            return;
        arr[length++] = data;
    }
    bool is_Full(){
        return length == capacity;
    }
    bool is_Empty(){
        return !length;
    }
    int peek(){
        if(!length)
            return -1;
        return arr[length-1];
    }
    void pop(){
        if(!length)
            return;
        length--;
    }

    ~ArrayBasedStack(){ // time O(n) - memory O(1)
        delete[] arr;
    }
};

int main(){
    ArrayBasedStack stk(3);
    cout << stk.is_Empty() << "\n"; // 1
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);

    cout << stk.is_Full() << "\n"; // 1
    cout << stk.peek() << "\n"; // 30
    stk.pop();
    cout << stk.peek() << "\n"; // 20
    stk.pop();
    cout << stk.peek() << "\n"; // 10
    stk.pop();
    cout << stk.peek() << "\n"; // -1

    cout << stk.is_Full() << "\n"; // 0
    cout << stk.is_Empty() << "\n"; // 1



    cout << "NO RTE\n";

    return 0;
}
