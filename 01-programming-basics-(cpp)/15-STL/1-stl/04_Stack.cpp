#include<iostream>
#include<stack>
using namespace std;

template<class sometype>
void print(stack<sometype> &st){ //notice if you don't use the reference you just play with a copy.
    while(!st.empty()){                  //And the queue will remain the same after printing, so be careful.
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    //Main feature: Last IN First OUT (reverse of the queue)
    stack<string> st;

    st.push("Torad");
    st.push("Mohamed");
    st.push("Elsayed");
    st.push("Hamdy");
    st.push("Hossam");
    print(st);
    cout << "\nsize = " << st.size();



    return 0;
}
