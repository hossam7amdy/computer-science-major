#include<iostream>
using namespace std;

struct que{
    int arr[100];
    int idx;

    que(){
        idx = 0;
    }

    void add_front(int value){
        if(idx>0){
            for(int i=idx; i>0; i--) //shift right
                arr[i] = arr[i-1];
        }
        arr[0] = value;
        idx++;
    }

    void add_end(int value){
        arr[idx++] = value;
    }

    int remove_front(){
        int value = arr[0];
        for(int i=0; i<idx; i++){ //shift left
            arr[i] = arr[i+1];
        }
        idx--;
        return value;
    }

    void print(){
        for(int i=0; i<idx; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main(){
    que my_quque;
    my_quque.add_end(10);
    my_quque.add_end(20);
    my_quque.add_end(30);
    my_quque.print();

    my_quque.add_front(1);
    my_quque.add_front(4);
    my_quque.print();

    cout << my_quque.remove_front();
    cout << "\n";
    my_quque.print();

    return 0;
}
