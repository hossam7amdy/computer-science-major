// https://www.spoj.com/problems/PIE/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<iomanip>
using namespace std;

double circle_area(double r) {
	const double PI = acos(-1.0);
	return PI * r * r;
}

bool possible(const vector<double>& pie_radius, const double& possible_area, int people){
    double area = 0;

    for(int i = 0; i < (int)pie_radius.size(); ++i){
         area = circle_area(pie_radius[i]);
         if(possible_area > area)
            continue;

         while(people && area > possible_area){
            --people;
            area -= possible_area;
         }
         area = 0;
    }

    return !people;
}

double largest_area(vector<double> &pie_radius, int people) {
	double st = 0, en = 10000, area = 0;

	for(int i=0; i < 100; ++i){
        double mid = st + (en - st) / 2;
        double possible_area = circle_area(mid);

        if(possible(pie_radius, possible_area, people))
            st = mid, area = possible_area;
        else
            en = mid;
	}

	return area;
}

int main() {
	int cases, n, f;
	cin >> cases;

	while (cases--) {
		cin >> n >> f;
		vector<double> pie_radius(n);

		for (int i = 0; i < n; i++)
			cin >> pie_radius[i];

		double area = largest_area(pie_radius, f + 1);	// +1 for the host person

		cout << fixed;
		cout << setprecision(4) << area << "\n";
	}
	return 0;
}
