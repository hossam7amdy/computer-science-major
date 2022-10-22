#include<iostream>
#include<assert.h>
using namespace std;

typedef int type;

class Queue{
private:
    int Front{ };
    int Rear { };
    int Size;
    type *Array;

    int next(int pos){
        ++pos;

        if(pos == Size)
            return 0;
        return pos;
    }

public:
    Queue(const int &Size):
        Size(Size+1){
            Array = new type[this->Size];
    }
    ~Queue(){
        delete[] Array;
    }

    bool isFull(){
        return next(Rear) == Front;
    }
    bool isEmpty(){
        return Front  == Rear;
    }

    void enqueue(const type &value){
        assert(!isFull());

        Array[Rear] = value;
        Rear = next(Rear);
    }
    type dequeue(){ // O(n)
        assert(!isEmpty());

        type value = Array[Front];
        Front = next(Front);

        return value;
    }

    void display(){
        //cout << "Front " << Front << " - rear " << Rear << "\t";
        if(isFull())
            cout << "Queue is Full\n";
        else if(isEmpty()){
            cout << "Queue is Empty\n";
            return;
        }
        for(int cur=Front; cur!=Rear; cur=next(cur))
            cout << Array[cur] << " ";
        cout << "\n";
    }
};

int main() {
	Queue qu(6);
	assert(qu.isEmpty());
	qu.display();

	for (int i = 1; i <= 6; ++i) {
		assert(!qu.isFull());
		qu.enqueue(i);
		qu.display();
	}
	assert(qu.isFull());

	for (int i = 1; i <= 6; ++i) {
		assert(!qu.isEmpty());
		qu.dequeue();
		//qu.display();
	}

	for (int i = 1; i <= 6; ++i) {
		assert(!qu.isFull());
		qu.enqueue(i);
		qu.display();
	}

	qu.dequeue();
	assert(!qu.isFull());
	qu.enqueue(7);
	assert(qu.isFull());
	qu.display();

	qu.dequeue();
	qu.dequeue();
	assert(!qu.isFull());
	qu.enqueue(8);
	assert(!qu.isFull());
	qu.display();
	qu.enqueue(9);
	assert(qu.isFull());
	qu.display();

	for (int i = 1; i <= 6; ++i) {
		assert(!qu.isEmpty());
		qu.dequeue();
		qu.display();
	}

	return 0;
}

/*
Front 0 - rear 0	empty

Front 0 - rear 1
1

Front 0 - rear 2
1 2

Front 0 - rear 3
1 2 3

Front 0 - rear 4
1 2 3 4

Front 0 - rear 5
1 2 3 4 5

Front 0 - rear 0	full
1 2 3 4 5 6

Front 0 - rear 1
1

Front 0 - rear 2
1 2

Front 0 - rear 3
1 2 3

Front 0 - rear 4
1 2 3 4

Front 0 - rear 5
1 2 3 4 5

Front 0 - rear 0	full
1 2 3 4 5 6

Front 1 - rear 1	full
2 3 4 5 6 7

Front 3 - rear 2
4 5 6 7 8

Front 3 - rear 3	full
4 5 6 7 8 9

Front 4 - rear 3
5 6 7 8 9

Front 5 - rear 3
6 7 8 9

Front 0 - rear 3
7 8 9

Front 1 - rear 3
8 9

Front 2 - rear 3
9

Front 3 - rear 3	empty
*/
