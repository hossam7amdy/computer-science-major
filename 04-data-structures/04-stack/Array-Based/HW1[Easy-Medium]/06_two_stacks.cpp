#include<iostream>
#include<assert.h>
using namespace std;

template<class type>
class Stack{
private:
    type *Array{ };
    int len1;
    int len2;
    int capacity;
public:
    Stack(const int &capacity):
        capacity(capacity), len1(-1), len2(capacity) {
            Array = new type[capacity];
    }

    void push(const int &id, const type &data){
        assert(!isFull());
        if(id==1)
            Array[++len1] = data;
        else
            Array[--len2] = data;
    }
    bool isEmpty(const int &id){
        if(id == 1)
            return len1==-1;
        return len2==capacity;
    }
    bool isFull(){
        return len1+1 >= len2;
    }
    type top(const int &id){
        assert(!isEmpty(id));
        if(id==1)
            return Array[len1];
        return Array[len2];
    }
    type pop(const int &id){
        assert(!isEmpty(id));
        if(id==1)
            return Array[len1--];
        return Array[len2++];
    }
    void Display() const {
        for(int i=len1; i>=0; i--)
            cout << Array[i] << " ";
        cout << "\n";
        for(int i=len2; i<capacity; i++)
            cout << Array[i] << " ";
        cout << "\n";
    }
    ~Stack(){ // time O(n) - memory O(1)
        delete[] Array;
    }
};


int main(){
	Stack<int> stk(7);
	cout << stk.isEmpty(1) << "\n";
	//cout << stk.pop(1) << "\n";
	//cout << stk.top(2) << "\n";
	stk.push(2, 5);
	stk.push(2, 6);
	stk.pop(2);
	stk.push(2, 7);
	stk.push(2, 9);
	cout << stk.isEmpty(1) << "\n";
	cout << stk.top(2) << "\n";
	stk.push(1, 4);
	stk.push(1, 6);
	stk.pop(2);
	cout << stk.pop(2) << "\n";
	stk.push(1, 8);
	stk.push(2, 3);
	stk.Display();
	cout << stk.top(1) << "\n";
	stk.push(2, 3);

	cout << stk.isFull() << "\n";




    cout << "\nNO RTE\n";

    return 0;
}
