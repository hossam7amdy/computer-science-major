#include<iostream>
#include<queue>
using namespace std;


class KthNumberProcessor{
private:
    int k{};
    priority_queue<int> p_que; // or MaxHeap
public:
    KthNumberProcessor(const int& k):
        k(k){
    }
    int next(const int& num){
        // store first k inputs
        if((int)p_que.size() < k)
            p_que.push(num);
        // Keep updating them with any smaller than top
        else if(p_que.top() > num){
            p_que.push(num);
            p_que.pop();
        }

        return p_que.top();
    }
};

int main(){
   KthNumberProcessor processor(4);

   int num;
   while(cin >> num)
        cout << processor.next(num) << endl;

    return 0;
}
