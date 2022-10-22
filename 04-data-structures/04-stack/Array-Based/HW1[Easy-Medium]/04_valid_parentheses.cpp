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
        capacity(capacity), length(-1), Array(new type[capacity]) {
            assert(capacity>=0);
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
    void Display(){
        for(int i=0; i<length; i++)
            cout << Array[i] << " ";
        cout << "\n";
    }
    ~Stack(){ // time O(n) - memory O(1)
        delete[] Array;
    }
};

char get_open_match(char ch){
    if(ch == ')')
        return '(';
    else if(ch == ']')
        return '[';
    return '{';
}

bool valid_parentheses(string str){
    int sz = (int)str.size();
    Stack<char> st(sz);

    for(int i=0; i<sz; i++){
        char ch = str[i];

        if(ch == '(' || ch == '[' || ch == '{')
            st.push(ch);
        else if(st.isEmpty() || get_open_match(ch) != st.pop())
            return false;
    }
    return st.isEmpty();
}

int main(){
    cout<< valid_parentheses("()")<<"\n";
	cout<< valid_parentheses("()()")<<"\n";
	cout<< valid_parentheses("(()())")<<"\n";
	cout<< valid_parentheses("{}{}")<<"\n";
	cout<< valid_parentheses("(((())))")<<"\n";
	cout<< valid_parentheses("([])")<<"\n";
	cout<< valid_parentheses("()[]{}")<<"\n";
	cout<< valid_parentheses("{[]}")<<"\n";


	cout<< valid_parentheses("(]")<<"\n";
	cout<< valid_parentheses("())")<<"\n";
	cout<< valid_parentheses("(][)")<<"\n";
	cout<< valid_parentheses("(]")<<"\n";
	cout<< valid_parentheses("([)]")<<"\n";


    cout << "\nNO RTE\n";

    return 0;
}
