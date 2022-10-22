#include<iostream>
#include<assert.h>
using namespace std;


typedef int type;

class Stack{
private:
    type *Array{ };
    int length;
    int capacity;
public:
    Stack(const int &capacity):
        capacity(capacity), length(-1), Array(new type[capacity]) {
            assert(capacity>=0);
    }

    void push(const type &data){
        assert(!isFull());
        Array[++length] = data;
    }
    bool isEmpty(){
        return length == -1;
    }
    bool isFull(){
        return length == capacity-1;
    }
    type top(){
        assert(!isEmpty());
        return Array[length];
    }
    type pop(){
        assert(!isEmpty());
        return Array[length--];
    }
    void Display(){
        for(int i=0; i<length; i++)
            cout << Array[i] << " ";
        cout << "\n";
    }
    ~Stack(){ // time O(n) - memory O(1)
        delete[] Array;
    }
};

class Queue{
private:
    Stack st1;
    Stack st2;
    int Size;
    int added_elements { };

    void Move(Stack &from, Stack &to){
        while(!from.isEmpty())
            to.push(from.pop());
    }

public:
    Queue(const int &Size):
        Size(Size), st1(Size),st2(Size){
            assert(Size>=0);
    }

    bool isEmpty(){
        return added_elements == 0;
    }
    bool isFull(){
        return added_elements == Size;
    }

    void enqueue(const int &value){ // O(1) time/memory
        assert(!isFull());

        st1.push(value);
        added_elements++;

    }
    int dequeue(){
        assert(!isEmpty());

        if(st2.isEmpty())
            Move(st1, st2);

        --added_elements;
        return st2.pop();
    }
};

int main() {
	Queue qu(6);

	for (int i = 1; i <= 3; ++i)
		qu.enqueue(i);

	cout<<qu.dequeue()<<" ";

	for (int i = 4; i <= 5; ++i)
		qu.enqueue(i);

	while(!qu.isEmpty())
		cout<<qu.dequeue()<<" ";

	return 0;
}
