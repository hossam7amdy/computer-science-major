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

    bool isFull(){
        return added_elements == Size;
    }
    bool isEmpty(){
        return added_elements == 0;
    }

    void enqueue(const type &value){
        assert(!isFull());

        Array[Rear] = value;
        Rear = next(Rear);
        added_elements++;
    }
    type dequeue(){
        assert(!isEmpty());

        type value = Array[Front];
        Front = next(Front);
        --added_elements;

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
        for(int cur=Front, elements = 0; elements<added_elements; elements++, cur=next(cur))
            cout << Array[cur] << " ";
        cout << "\n";
    }
};

class last_k_numbers_sum_stream{
    Queue q;
    int sum{};
    int k;
public:
    last_k_numbers_sum_stream(const int &k):
        k(k), q(k){
    }
    int next(const int &new_num){
        sum += new_num;
        if(q.isFull())
            sum -= q.dequeue();

        q.enqueue(new_num);
        return sum;
    }
};

int main(){
    last_k_numbers_sum_stream prossesor(4);

    int num;
    while(cin >> num)
        cout << prossesor.next(num) << "\n";

    return 0;
}
