#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> dailyTemperatures(vector<int> temperatures) {
    const int sz{(int)temperatures.size()};
    vector<int> answer(sz);

    stack<int> st;
    for(int i = 0; i < sz; ++i){
        while(!st.empty() && temperatures[i] > temperatures[st.top()]){
            temperatures[st.top()] = temperatures[i];
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
        temperatures[st.top()] = -1;
        st.pop();
    }
    return temperatures;
}

int main(){
    vector<int> v { dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73}) };

    for(const auto &item : v)
        cout << item << " ";

    return 0;
}
