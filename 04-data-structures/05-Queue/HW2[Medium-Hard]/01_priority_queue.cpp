#include<iostream>
#include<assert.h>
using namespace std;

typedef int type;

class Queue{
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
public:
    Queue(const int &Size):
        Size(Size){
            assert(Size>=0);
            Array = new type[Size];
    }
    ~Queue(){
        delete[] Array;
    }

    bool isFull() const {
        return added_elements == Size;
    }
    bool isEmpty() const {
        return added_elements == 0;
    }

    void Enqueue(const type &value){
        assert(!isFull());

        Array[Rear] = value;
        Rear = next(Rear);
        added_elements++;
    }
    type Dequeue(){
        assert(!isEmpty());

        type value = Array[Front];
        Front = next(Front);
        --added_elements;

        return value;
    }

    void display() {
        //cout << "Front " << Front << " - rear " << Rear << "\t";
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

class PriorityQueue{
private:
    Queue q1, q2, q3;
    int added_elements{ };
    int Size;

public:
    PriorityQueue(const int &Size):
        Size(Size), q1(Size), q2(Size), q3(Size){
            assert(Size>=0);
    }

    bool isEmpty() const {
        return added_elements == 0;
    }
    bool isFull() const {
        return added_elements == Size;
    }

    void Enqueue(const int &value, const int &priority){
        assert(!isFull());

        added_elements++;

        if(priority == 1)
            q1.Enqueue(value);
        else if(priority == 2)
            q2.Enqueue(value);
        else if(priority == 3)
            q3.Enqueue(value);
        else
            assert(false);
    }
    int Dequeue(){
        assert(!isEmpty());

        --added_elements;

        if(!q1.isEmpty())
            return q1.Dequeue();
        else if(!q2.isEmpty())
            return q2.Dequeue();

        return q3.Dequeue();
    }

    void Display() {
        assert(!isEmpty());

        if(!q1.isEmpty())
            cout << "Priority #1 tasks: ", q1.display();
        if(!q2.isEmpty())
            cout << "Priority #2 tasks: ", q2.display();
        if(!q3.isEmpty())
            cout << "Priority #3 tasks: ", q3.display();
    }
};

int main() {


	PriorityQueue tasks(8);

	tasks.Enqueue(1131, 1);
	tasks.Enqueue(3111, 3);
	tasks.Enqueue(2211, 2);
	tasks.Enqueue(3161, 3);

	tasks.Display();
	//Priority #3 tasks: 3111 3161
	//Priority #2 tasks: 2211
	//Priority #1 tasks: 1131

	cout << tasks.Dequeue() << "\n";	// 3111
	cout << tasks.Dequeue() << "\n";	// 3161

	tasks.Enqueue(1535, 1);
	tasks.Enqueue(2815, 2);
	tasks.Enqueue(3845, 3);
	tasks.Enqueue(3145, 3);

	tasks.Display();
	//Priority #3 tasks: 3845 3145
	//Priority #2 tasks: 2211 2815
	//Priority #1 tasks: 1131 1535

	while (!tasks.isEmpty())
		cout << tasks.Dequeue() << " ";
	// 3845 3145 2211 2815 1131 1535

	return 0;
}

/*
Priority #3 tasks: 3111 3161
Priority #2 tasks: 2211
Priority #1 tasks: 1131
******************
3111
3161
Priority #3 tasks: 3845 3145
Priority #2 tasks: 2211 2815
Priority #1 tasks: 1131 1535
******************
3845 3145 2211 2815 1131 1535
 */
