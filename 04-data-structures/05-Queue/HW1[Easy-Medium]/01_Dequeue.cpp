#include<iostream>
#include<assert.h>
using namespace std;

typedef int type;

class Deque{
private:
    int Front{ };
    int Rear { };
    int Size;
    int added_elements{ };
    type *Array;

    int next(int pos){
        ++pos;

        if(pos == Size)
            return 0;
        return pos;
    }
    int prev(int pos){
        --pos;

        if(pos==-1)
            return Size-1;
        return pos;
    }
public:
    Deque(const int &Size):
        Size(Size){
            assert(Size>=0);
            Array = new type[Size];
    }
    ~Deque(){
        delete[] Array;
    }

    bool isFull(){
        return added_elements == Size;
    }
    bool isEmpty(){
        return added_elements == 0;
    }

    void enqueue_front(const type &value){
        assert(!isFull());

        Front = prev(Front); // first move then use
        Array[Front] = value;
        added_elements++;
    }
    void enqueue_rear(const type &value){
        assert(!isFull());

        Array[Rear] = value; // use then move
        Rear = next(Rear);
        added_elements++;
    }
    type dequeue_front(){
        assert(!isEmpty());

        type value = Array[Front]; // first use then move
        Front = next(Front);
        --added_elements;

        return value;
    }
    type dequeue_rear(){
        assert(!isEmpty());

        Rear = prev(Rear); // move then use
        type value = Array[Rear];
        --added_elements;

        return value;
    }

    void display(){
        cout << "Front " << Front << " - rear " << Rear << "\t";
        if(isFull())
            cout << "Queue is Full\n";
        else if(isEmpty()){
            cout << "Queue is Empty\n";
            return;
        }
        for(int cur=Front, elements = 0; elements<added_elements; elements++, cur=next(cur))
            cout << Array[cur] << " ";
        cout << "\n";
    }
};

int main() {

	Deque dq(6);

	dq.enqueue_front(3);
	dq.display();
	dq.enqueue_front(2);
	dq.enqueue_rear(4);
	dq.enqueue_front(1);
	dq.enqueue_front(5);
	dq.enqueue_front(6);
	dq.display();	// 1 2 3 4
	cout<<dq.dequeue_rear()<<"\n";	// 4
	dq.display();	// 1 2 3
	cout<<dq.dequeue_front()<<"\n";	// 1
	dq.display();	// 2 3
	cout<<dq.dequeue_rear()<<"\n";	// 3
	cout<<dq.dequeue_front()<<"\n";	// 2

	while(!dq.isEmpty())
		dq.dequeue_rear();
	dq.display();	//
	for (int i = 0; i < 6; ++i)
		dq.enqueue_rear(i+10);
	dq.display();	//



	return 0;
}

