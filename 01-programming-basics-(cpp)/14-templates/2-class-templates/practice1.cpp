#include<iostream>
using namespace std;

//create a struct (class)
template<class T>
struct Queue{
    T arr[100];
    int len;

    Queue(){ len = 0; }

    void add_end(T val){
        arr[len++] = val;
    }

    template<typename N>
    void sum_and_add(N val1, N val2){
        arr[len++] = val1 + val2;
    }

    void print(){
        for(int i=0; i<len; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main(){
    Queue<string> q_str;
    q_str.add_end("Hossam");
    q_str.add_end("Hamdy");
    q_str.sum_and_add<string>("Ahmed", "Hamdy"); //
    q_str.print();

    Queue<int> q_nums;
    q_nums.add_end(2);
    q_nums.add_end(3);
    q_nums.add_end(4);
    q_nums.sum_and_add<double>(2.5, 5.6);
    q_nums.print();

    return 0;
}
