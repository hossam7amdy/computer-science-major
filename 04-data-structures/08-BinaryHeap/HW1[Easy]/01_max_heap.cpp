#include<iostream>
#include<assert.h>
using namespace std;

class MaxHeap{
private:
    int *Array{};
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

        if(rit != -1 && Array[lft] < Array[rit])
            lft = rit;

        if(Array[lft] > Array[par]){
            swap(Array[par], Array[lft]);
            HeapifyDown(lft);
        }
    }
public:
    MaxHeap(){
        Array = new int[capacity];
    }

    void push(const int& key){
        assert(sz <= capacity);
        Array[sz++] = key;

        HeapifyUp(sz-1);
    }
    int top(){
        assert(!isEmpty());
        return Array[0];
    }
    void pop(){
        assert(!isEmpty());
        Array[0] = Array[--sz];

        HeapifyDown(0);
    }
    bool isEmpty(){
        return !sz;
    }

    ~MaxHeap(){
        delete[] Array;
        Array = nullptr;
    }
};

void test1(){
    MaxHeap heap;
    heap.push(10);
    heap.push(33);
    heap.push(21);
    heap.push(20);
    heap.push(15);
    heap.push(40);
    heap.push(30);
    heap.push(50);

    while(!heap.isEmpty()){
        cout << heap.top() << " ";
        heap.pop();
    }
}

int main(){
    test1();

    return 0;
}
