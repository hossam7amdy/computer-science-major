#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

class MinHeap{
private:
    int *Array{};
    int sz{};
    int capacity { 1000 };

    int parent(const int& node){
        return node == 0 ? -1 : (node-1) / 2;
    }
    int left(const int& node){
        int l = (node*2) + 1;
        return l >= sz ? -1 : l;
    }
    int right(const int& node){
        int r = (node*2) + 2;
        return r >= sz ? -1 : r;
    }

    void HeapifyUp(const int& child_pos){
        int par_pos = parent(child_pos);
        if(par_pos == -1 || Array[par_pos] < Array[child_pos])
            return;

        swap(Array[par_pos], Array[child_pos]);
        HeapifyUp(par_pos);
    }
    void HeapifyDown(const int& par_pos){
        int left_child = left(par_pos);
        int right_child = right(par_pos);

        if(left_child == -1)
            return;

        if(right_child != -1 && Array[right_child] < Array[left_child])
            left_child = right_child; // next valid direction

        if(Array[left_child] < Array[par_pos]){
            swap(Array[left_child], Array[par_pos]);
            HeapifyDown(left_child);
        }
    }
    void Heapify(){
        for(int i=sz/2-1; i>=0; i--)
            HeapifyDown(i);
    }
public:
    MinHeap():
        Array(new int[capacity]){
    }
    MinHeap(const vector<int> &v){
        assert((int)v.size() <= capacity);
        Array = new int[capacity];
        sz = (int)v.size();

        for(int i=0; i<sz; i++)
            Array[i] = v[i];

        Heapify();
    }
    int top(){
        assert(!isEmpty());
        return Array[0];
    }
    void push(const int& value){
        assert(sz < capacity);
        Array[sz++] = value;

        HeapifyUp(sz - 1);
    }
    void pop(){
        assert(!isEmpty());
        Array[0] = Array[--sz];

        HeapifyDown(0);
    }
    bool isEmpty(){
        return sz == 0;
    }
    ~MinHeap(){
        delete[] Array;
        Array = nullptr;
    }

    void heap_sort(int *p, int n){
        int* old_arr = Array;
        int old_size = sz;

        Array = p;
        sz = n;

        Heapify();

        while(sz--){
            swap(p[0], p[sz]);
            HeapifyDown(0);
        }

        for(int i=0; i<n/2; i++)
            swap(p[i], p[n-i-1]);

        Array = old_arr;
        sz = old_size;
    }
};

void test1(){
    int *arr = new int[14]{2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30};

    MinHeap heap;

    heap.heap_sort(arr, 14);

    for(int i=0; i<14; i++)
        cout << arr[i] << " ";

    cout << "\n";
    delete[] arr;
}

void test2(){
    int arr[]{50, 30, 40, 15, 20, 21, 33, 10};

    MinHeap heap;

    heap.heap_sort(arr, 8);

    for(int i=0; i<8; i++)
        cout << arr[i] << " ";
}

int main(){
    test1();
    test2();

    return 0;
}
