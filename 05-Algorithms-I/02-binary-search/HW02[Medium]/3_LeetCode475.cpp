#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution { /// O(n log n)
public:
    bool possible(const vector<int>& heaters, const vector<int> &houses, const int &raduis){ // O(houses + heaters)
        int house_pos = 0;
        for(int heater_pos = 0; heater_pos < (int)heaters.size(); ++heater_pos){
            int left = heaters[heater_pos] - raduis, right = heaters[heater_pos] + raduis;

            while(house_pos < (int)houses.size() && left <= houses[house_pos] && right >= houses[house_pos])
                ++house_pos;

            if(house_pos == (int)houses.size())
                return true;
        }

        return house_pos == (int)houses.size();
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // O(n log n)
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int min_radius = -1, st = 0, en = INT_MAX;
        while(st <= en){ // O(log n)
            int mid = st + (en - st) / 2;
            if(possible(heaters, houses, mid))
                en = mid - 1, min_radius = mid;
            else
                st = mid + 1;
        }

        return min_radius;
    }
};

int main(){

    vector<int> houses{1,5}, heaters{10};

    Solution s;
    cout << s.findRadius(houses, heaters) << endl;

    return 0;
}
