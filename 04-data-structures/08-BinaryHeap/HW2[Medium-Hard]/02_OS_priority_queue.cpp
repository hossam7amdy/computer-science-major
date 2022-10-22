#include<iostream>
#include<assert.h>
using namespace std;

class PriorityQueue{
private:
    pair<int, int> *Array{};
    int sz{};
    int capacity{ 1000 };

    int parent(const int& node){
        return !node ? -1 : (node-1) / 2;
    }
    int left(const int& node){
        int l = node*2+1;
        return l >= sz ? -1 : l;
    }
    int right(const int& node){
        int r = node*2+2;
        return r >= sz ? -1 : r;
    }

    void HeapifyUp(const int& child){
        int par = parent(child);
        if(par == -1 || Array[par] >= Array[child])
            return;

        swap(Array[par], Array[child]);
        HeapifyUp(par);
    }
    void HeapifyDown(const int& par){
        int lft = left(par);
        int rit = right(par);

        if(lft == -1)
            return;

        if(rit != -1 && Array[lft] <= Array[rit])
            lft = rit;

        if(Array[lft] >= Array[par]){
            swap(Array[par], Array[lft]);
            HeapifyDown(lft);
        }
    }
public:
    PriorityQueue(){
        Array = new pair<int, int>[capacity];
    }

    void enqueue(const int& task_id, const int& priority){
        assert(sz <= capacity);
        Array[sz++] = make_pair(priority, task_id);

        HeapifyUp(sz-1);
    }
    int dequeue(){
        assert(!isEmpty());
        pair<int, int> ret = Array[0];
        pop();
        return ret.second;
    }
    void pop(){
        assert(!isEmpty());
        Array[0] = Array[--sz];

        HeapifyDown(0);
    }
    bool isEmpty(){
        return !sz;
    }

    ~PriorityQueue(){
        delete[] Array;
        Array = nullptr;
    }
};

void test1(){
    PriorityQueue tasks;
    tasks.enqueue(1131,1);
    tasks.enqueue(3111,3);
    tasks.enqueue(2211,2);
    tasks.enqueue(3161,3);
    tasks.enqueue(7761,7);

    cout << tasks.dequeue() << "\n";
    cout << tasks.dequeue() << "\n";

    tasks.enqueue(1535,1);
    tasks.enqueue(2815,2);
    tasks.enqueue(3845,3);
    tasks.enqueue(3145,3);

    while(!tasks.isEmpty())
        cout << tasks.dequeue() << " ";

}

int main(){
    test1();

    return 0;
}
