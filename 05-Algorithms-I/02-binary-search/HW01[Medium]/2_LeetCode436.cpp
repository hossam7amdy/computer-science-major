#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


class Solution {
public:
    /// My Implementation ///
    int lower(vector<pair<int,int>> &startings, int target){
        int st = 0, en = (int)startings.size() - 1, position = -1;

        while(st <= en){
            int mid = st + (en - st) / 2;
            int cur = startings[mid].first;

            if(cur < target)
                st = mid + 1;
            else
                en = mid - 1, position = startings[mid].second;
        }

        return position;
    }
    vector<int> findRightIntervalMINE(vector<vector<int>>& intervals) {
        int sz = (int)intervals.size();

        vector<pair<int, int>> startings;
        for(int i = 0; i < sz; ++i)
            startings.push_back(make_pair(intervals[i][0], i));

        sort(startings.begin(), startings.end());

        vector<int> res(sz, -1);
        for(int i = 0; i < sz; ++i){
            int idx = lower(startings, intervals[i][1]);

            if(idx != -1)
                res[i] = idx;
        }

        return res;
    }
    /// Using STL ///
    vector<int> findRightIntervalSTL(vector<vector<int>>& intervals) {
        int sz = (int)intervals.size();

        vector<vector<int>> startings;
        for(int i = 0; i < sz; ++i)
            startings.push_back({intervals[i][0], i});
        sort(startings.begin(), startings.end());

        vector<int> res(sz, -1);
        for(int i = 0; i < sz; ++i){
            vector<int> val = {intervals[i][1], 0};
            auto iter = lower_bound(startings.begin(), startings.end(), val);

            if(iter == startings.end())
                continue;

            int idx = iter - startings.begin();
            res[i] = startings[idx][1];
        }
        return res;
    }
    /// Using STL map ///
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(int i = 0; i < (int)intervals.size(); ++i)
            mp[intervals[i][0]] = i;

        vector<int> ans((int)intervals.size(), -1);
        for(int i = 0; i < (int)intervals.size(); ++i){
            auto iter = mp.lower_bound(intervals[i][1]);

            if(iter != mp.end())
                ans[i] = iter->second;
        }

        return ans;
    }
};

int main(){
    //freopen ("myfile.txt","w",stdout);
    //for(int i=1; i<20001; ++i)
      //  cout << "[" << i << "," << i + 1 << "],";

    return 0;
}
