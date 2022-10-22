#include<iostream>
#include<algorithm>
using namespace std;

//Non-Type parameters for templates.
template<class T, int SIZE>
struct Queue{
    T arr[SIZE];
    int pos;

    Queue(){ pos = 0; }

    void add_end(T val){
        arr[pos++] = val;
    }

    void print(){
        for(int i=0; i<pos; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};



int main(){
    Queue<string, 12> q_str;
    Queue<int, 12> q_nums;


    q_str.add_end("Hossam");
    q_str.add_end("Hamdy");
    q_str.print();

    q_nums.add_end(2);
    q_nums.add_end(3);
    q_nums.add_end(4);
    q_nums.add_end(3);
    q_nums.add_end(2);
    q_nums.add_end(1);
    sort(q_nums.arr, q_nums.arr + q_nums.pos);
    q_nums.print();

    return 0;
}
