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

    bool isHeap(int par){
        while(par>=0){

            int left_child = left(par);
            int right_child = right(par);

            if(left_child != -1 && Array[par] > Array[left_child])
                return false;

            if(right_child != -1 && Array[par] > Array[right_child])
                return false;

            --par;
        }
        return true;
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

    bool is_heap_array(int *p, const int& n){

        int *old_arr = Array;
        int old_sz = sz;

        Array = p;
        sz = n;

        bool result = isHeap(sz/2-1); // discard all leafs

        Array = old_arr;
        sz = old_sz;

        return result;
    }
};

void is_heap_array() {
	vector<int> v { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };
	MinHeap heap(v);

	int arr[] {2, 5, 12, 7,6, 22, 14, 19, 10, 17, 8, 37, 25, 30};
	cout<<heap.is_heap_array(arr, 14)<<"\n";	// 1
	swap(arr[0], arr[5]);
	cout<<heap.is_heap_array(arr, 14)<<"\n";	// 0
}

int main(){
    test1();
    test2();
    is_heap_array();

    return 0;
}
