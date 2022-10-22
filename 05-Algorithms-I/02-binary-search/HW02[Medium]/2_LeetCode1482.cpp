#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution { /// O(n log(n))
public:
    bool possible(const vector<int>& bloomDay, const int &total_bouquets, const int &flowers_per_bouquet, const int &waiting_days){ // O(n)
        int adj_flowers = 0, bouquets = 0;
        for(int i = 0; i < (int)bloomDay.size(); ++i){
            if(waiting_days >= bloomDay[i]){
                ++adj_flowers;

                if(adj_flowers >= flowers_per_bouquet)
                    adj_flowers -= flowers_per_bouquet, ++bouquets;
                if(bouquets == total_bouquets)
                    return true;
            }
            else
                adj_flowers = 0;
        }

        return false;
    }
    int minDays(vector<int>& bloomDay, int total_bouquets, int flowers_per_bouquet) {
        if((int)bloomDay.size() < flowers_per_bouquet / total_bouquets)
            return -1;

        int midDays = -1, st = 1, en = *max_element(bloomDay.begin(), bloomDay.end()); // O(n)
        while(st <= en){ // O(log n)
            int mid = st + (en - st) / 2;
            if(possible(bloomDay, total_bouquets, flowers_per_bouquet, mid))
                en = mid - 1, midDays = mid;
            else
                st = mid + 1;
        }
        return midDays;
    }
};

int main(){
    Solution s;

    vector<int> v1{1,10,3,10,2};
    cout << s.minDays(v1, 3, 1) << endl;

    return 0;
}

