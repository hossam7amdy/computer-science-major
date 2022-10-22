#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
 This problem involves 2 styles we learned:
 - Operation-based problem
 - Multi-src BFS

 Observe: Given a positive number, we can generate maximum 2 new numbers
 34 ==> 345 or 343
 30 ==> 301
 39 ==> 398

 The idea, we can use DFS or BFS to generate ALL the numbers. Then add only the numbers in the range

 Start with the numbers from 1 to 9
 Each number generates new numbers and so on
 1 => 10 and 11
 2 => 21 and 23
 ..
 9 => 98

 and so on
 10 => 101
 11 => 110 or 112

 Observe: ALL generated numbers are unique. No need for visited array
 Observe: As we generate the numbers in order, ONCE we have a number > high
 we can safely stop as all next numbers are high
 Generated sequence: 10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98, 101, 121, 123, 210, 212, 232, 234, 321

 So the idea:
 - Number is a node. 2 edges are maximum
 - Start from 9 values as BFS states
 - Handle 0 as special case

 With careful thinking and verifying ==> easy code. Rush? Messy code

 */

class Solution {
    bool inRange(const long long &num, const int &low, const int &high){
        return low <= num && num <= high;
    }

    bool process(queue<int> &q, vector<int> &res, const int &low, const int &high, const int &num){
        if(!inRange(num, low, high))
            return false;

        res.push_back(num);
        q.push(num);
        return true;
    }

public:
    vector<int> countSteppingNumbers(int low, int high) {
        queue<int> q;
        vector<int> result;

        if(inRange(0, low, high))
            result.push_back(0);

        for(int i = 1; i <= 9; ++i){
            q.push(i);

            if(inRange(i, low, high))
                result.push_back(i);
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            int last_digit = cur % 10;
            if(last_digit != 0 && !process(q, result, low, high, cur * 10 + last_digit - 1))
                break;

            if(last_digit != 9 && !process(q, result, low, high, cur * 10 + last_digit + 1))
                break;
        }

        return result;
    }
};

void test1(){
    Solution s;
    vector<int> ans = s.countSteppingNumbers(0, 21);
    cout << ans.size() << endl;

    //for(const auto &val : ans)
    //    cout << val << " ";
    cout << "\n====================\n";
}

void test2(){
    Solution s;
    vector<int> ans = s.countSteppingNumbers(10, 15);
    cout << ans.size() << endl;

    //for(const auto &val : s.countSteppingNumbers(10, 15))
     //   cout << val << " ";
    cout << "\n====================\n";
}

void test3(){
    Solution s;
    vector<int> ans = s.countSteppingNumbers(0, 2000000000);
    cout << ans.size() << endl;

    //for(const auto &val : ans)
    //    cout << val << " ";
    cout << "\n====================\n";
}

int main(){
    test1();
    test2();
    test3();

    return 0;
}
