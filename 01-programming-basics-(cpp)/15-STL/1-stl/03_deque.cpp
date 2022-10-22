#include<iostream>
#include<queue>
using namespace std;

template<class sometype>
void print_front(deque<sometype> &dq){
    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << "\n";
}

template<class sometype>
void print_back(deque<sometype> &dq){
    while(!dq.empty()){
        cout << dq.back() << " ";
        dq.pop_back();
    }
    cout << "\n";
}

deque<char> c_dq(string str){
    deque<char> c_dq;
    for(int i=0; i<(int)str.size(); i++)
        c_dq.push_back(str[i]);
    return c_dq;
}

bool is_palandirome(string str){
    deque<char> dq = c_dq(str);
    while(!dq.empty()){
        if(dq.front()!=dq.back())
            return false;
        dq.pop_front();
        dq.pop_back();
    }
    return true;
}

int main(){
    //Main feature: Flexible way to deal with first and last elements.
    string str = "HossammassoH";
    deque<char> str_q = c_dq(str);

    //print_back(str_q);
    print_front(str_q);
    cout << is_palandirome(str);


    return 0;
}
