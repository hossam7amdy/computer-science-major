// https://www.spoj.com/problems/GLASNICI/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<iomanip>
using namespace std;

bool possible(const vector<double> &positions, const double &move_dist, const double &msg_dist){
    double pos_after_move = positions[0] + move_dist;

    for(int i = 1; i < (int)positions.size(); ++i){
        if(pos_after_move + msg_dist < positions[i] - move_dist)
            return false;
        pos_after_move = min(pos_after_move + msg_dist, positions[i] + move_dist);
    }

    return true;
}

double min_time(vector<double> &positions, double msg_dist) {
	if(msg_dist >= positions.back() - positions[0])
        return 0;

    double st = 0, en = 1e9;
    for(int i = 0; i < 100; ++i){
        double mid = st + (en - st) / 2.0;
        if(possible(positions, mid, msg_dist))
            en = mid;
        else
            st = mid;
    }

    return en;
}

int main() {
	int cases, n;
	double msg_dist;
	cin >> cases;

	while (cases--) {
		cin >> msg_dist >> n;
		vector<double> positions(n);

		for (int i = 0; i < n; i++)
			cin >> positions[i];

		double time = min_time(positions, msg_dist);

		cout << fixed;
		cout << setprecision(2) << time << "\n";
	}
	return 0;
}
