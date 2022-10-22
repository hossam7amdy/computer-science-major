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
    type peek(){
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

string reverse_subword(string line){
    string rev_line;

    line += " ";
    Stack<char> st((int)line.size());

    for(int i=0; i<(int)line.size(); i++){
        if(line[i]==' '){
            while(!st.is_Empty()){
                rev_line += st.peek();
                st.pop();
            }
            rev_line += ' ';
        }
        else
            st.push(line[i]);
    }
    return rev_line;
}

int main(){
    string line("abc d efg xy");
    cout << (int)line.size() << "\n";

    cout << (int)reverse_subword(line).size() << "\n";

    cout << "\nNO RTE\n";

    return 0;
}
