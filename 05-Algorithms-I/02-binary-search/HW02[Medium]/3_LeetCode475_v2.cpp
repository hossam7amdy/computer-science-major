#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<set>
using namespace std;

class Solution { /// RTE
public:
    int raduis(const vector<int>& heaters, const int &house_position){
        int r = INT_MAX, st = 0, en = (int)heaters.size() - 1;
        while(st <= en){
            int cur = min(abs(house_position - heaters[st]), abs(heaters[en] - house_position));
            if(r < cur)
                return r;
            r = cur;
            ++st, --en;
        }

        return r;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());

        int minimum_radius = INT_MIN;
        for(int i = 0; i < (int)houses.size(); ++i)
            minimum_radius = max(minimum_radius, raduis(heaters, houses[i]));

        return minimum_radius;
    }
};

int main() {
	vector<int> houses {636807826,563613512,101929267,580723810,704877633,358580979,624379149,128236579};
	vector<int> heaters {530511967,110010672};

	Solution s;
	cout<<s.findRadius(houses, heaters);

	return 0;
}
