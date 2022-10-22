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
        assert(length!=capacity);

        Array[++length] = data;
    }
    bool is_Empty(){
        return length == -1;
    }
    type top(){
        return Array[length];
    }
    void pop(){
        assert(length!=-1);
        length--;
    }
    ~Stack(){ // time O(n) - memory O(1)
        delete[] Array;
    }
};

int reverse_num(int num){
    if(num==0)
        return num;

    Stack<int> st(10);
    while(num)
        st.push(num%10), num/=10;

    int tens = 1;
    while(!st.is_Empty()){ // 1 2 3
        num = st.top() * tens + num;
        tens*=10;
        st.pop();
    }
    return num;
}

int main(){

    cout<<reverse_num(123456)<<"\n";
	cout<<reverse_num(-123456)<<"\n";

    cout << "\nNO RTE\n";

    return 0;
}
