#include<iostream>
#include<stack>
using namespace std;



int scoreOfParentheses(string s) {
    stack<int> st;
    for(int i=0; i<(int)s.size(); ++i){
        if(s[i] == '(')
            st.push(0);
        else if(s[i] == ')'){
            if(st.top() == 0)
                st.top() = 1;
            else{
                int sub{};
                while(st.top() != 0){
                    sub += st.top();
                    st.pop();
                }
                st.top() = 2 * sub;
            }
        }
    }
    int ans{};
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main(){
    cout << scoreOfParentheses("(()()()()()(())((())))") << endl; // 22
    cout << scoreOfParentheses("(())") << endl; // 2
    cout << scoreOfParentheses("()()") << endl; // 2
    cout << scoreOfParentheses("(()())") << endl; // 4
    cout << scoreOfParentheses("(()(()))") << endl; // 6
    cout << scoreOfParentheses("()((())())") << endl; // 7

    return 0;
}
