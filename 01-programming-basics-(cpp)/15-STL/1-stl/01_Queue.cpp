#include<iostream>
#include<queue>
using namespace std;

template<class type, int SIZE> // my trial of creating a queue
struct myqueue{
    type arr[SIZE];
    int len;
    myqueue(){ len = 0; }

    void mypush(type something){
        arr[len++] = something;
    }

    type myfront(){
        return arr[0];
    }

    void mypop(){
        len--;
        for(int i=0; i<len; i++)
            arr[i] = arr[i+1];

        return;
    }

    bool myempty(){
        if(len==0)
            return true;
        return false;
    }

    int mysize(){
        return len;
    }

    type myback(){
        return arr[len-1];
    }


};


template<class sometype>
void print(queue<sometype> &q){ //better provide the reference
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}

int main(){
    //Main feature: First IN First OUT
    queue<int> que;

    que.push(1);
    que.push(3);
    que.push(7);
    que.push(9);
    print(que);
    cout << "\nsize = " << que.size();

    cout << "\n****************************\n";
    myqueue<string, 12> mine; //trying my queue
    mine.mypush("Hossam");
    mine.mypush("Ahmed");
    mine.mypush("Emad");

    while(!mine.myempty()){
        cout << mine.myfront() << " ";
        mine.mypop();
        }

    cout << "\nsize = " << mine.mysize();



    return 0;
}
