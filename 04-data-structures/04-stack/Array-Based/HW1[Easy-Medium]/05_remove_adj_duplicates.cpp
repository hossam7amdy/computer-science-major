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
    ~Stack(){ // time O(n) - memory O(1)
        delete[] Array;
    }
};

string removeDuplicates(string S){
    Stack<char> st((int)S.size());

    for(int i=0; i<(int)S.size(); i++){
        if(st.isEmpty() || st.top() != S[i])
            st.push(S[i]);
        else
            st.pop();
    }
    string ret = "";
    while(!st.isEmpty())
        ret = st.pop() + ret;

    return ret;
}


int main(){

    cout << removeDuplicates("abbaca") << "\n"; // ca
    cout << removeDuplicates("azxxzy") << "\n"; // ay
    cout << removeDuplicates("abbaacca") << "\n"; // Empty

    cout << removeDuplicates("abbacaac") << "\n";	// Empty
	cout << removeDuplicates("aabacaacd") << "\n";	// bad
	cout << removeDuplicates("abcddcba") << "\n";	// Empty


    cout << "\nNO RTE\n";

    return 0;
}
