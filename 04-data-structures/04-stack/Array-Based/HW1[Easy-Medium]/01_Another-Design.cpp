#include<iostream>
using namespace std;

class ArrayBasedStack{
private:
    int *Array{ };
    int added_elements{ };
    int capacity;
public:
    ArrayBasedStack(const int &capacity): // time O(n) - memory O(n)
        capacity(capacity){
            if(capacity>0)
                Array = new int[capacity];
    }

    bool push(const int &data){ // time O(n) - memory O(1)
        if(added_elements==capacity)
            return false;

        for(int i=added_elements; i>=0; i--)
            Array[i+1] = Array[i];

        Array[0] = data;
        added_elements++;
        return true;
    }
    bool is_Full(){
        return added_elements == capacity;
    }
    bool is_Empty(){
        return !added_elements;
    }
    int peek(){
        if(!added_elements)
            return -1;
        return Array[0];
    }
    bool pop(){ // time O(n) - memory O(1)
        if(!added_elements)
            return false;

        for(int i=0; i<added_elements-1; i++)
            Array[i] = Array[i+1];

        added_elements--;
        return true;
    }
    void Display(){ // time O(n) - memory O(1)
        for(int i=0; i<added_elements; i++)
            cout << Array[i] << " ";
        cout << "\n";
    }

    ~ArrayBasedStack(){ // time O(n) - memory O(1)
        delete[] Array;
    }
};

int main(){
    ArrayBasedStack stk(3);
    cout << stk.is_Empty() << "\n"; // 1
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);

    stk.Display(); // 30 20 10

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
