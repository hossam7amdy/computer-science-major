#include<iostream>
#include<queue>
using namespace std;

//sum of last k numbers (stream);

queue<int> q;
int sum = 0;

struct sum_of_last_k_numbers{
    int k;

    sum_of_last_k_numbers(int _k){
        k = _k;
    }

    int next(int new_num){ // 1 2 3 4
        if(k>0){
            sum+=new_num;
            q.push(new_num);
            k--;
        }
        else{
            sum-=q.front();
            q.pop();
            sum+=new_num;
            q.push(new_num);
        }
        //cout << q.size() << "\n";
        return sum;
    }
};

int main(){
    sum_of_last_k_numbers prossesor(4);

    int num;
    while(cin >> num) //first time to see this syntax
        cout << prossesor.next(num) << "\n";

    return 0;
}
