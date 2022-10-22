#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
 * Logically (Greedily), which monster to kill first?
 * The one that arrives the city first!
 *
 * So let's compute the time each monster needs to arrive: dist[i] / speed[i]
 * Sort them based on this arrival time
 * In each minute, kill one untill one of them arrives!
 *
 * Implementation notes:
 *
 * Just compute time (which is double) add to vector and sort
 * Passed. But this is a bad idea, as programming languages fail to arrange close real-numbers
 *
 * We handle this in a better way
 * We don't care if the monster arrives at 2.8 seconds. This just means arrive at 3 seconds.
 * So always use integers
 *
 *  O(nlogn) time and O(n) memroy
 */
int eliminateMaximum(const vector<int>& dist, const vector<int>& speed) {

    const int sz { (int)dist.size() };

    vector<int> arrival_time(sz);
    for(int i=0; i<sz; ++i){
        if(dist[i] % speed[i])
            arrival_time[i] = dist[i] / speed[i] + 1; // ceil
        else
            arrival_time[i] = dist[i] / speed[i];
    }

    sort(arrival_time.begin(), arrival_time.end());

    int monstCounter{0};
    for(int i=0; i < sz && arrival_time[i] > i; ++i)
        ++monstCounter;

    return monstCounter;
}

/*
 * This solution: for educational purposes (and challenging you): doesn't have the division/modulus operation at all
 * 		which is btw a very slow operation
 */
bool static customCMP(const pair<int,int> &p1, const pair<int,int> &p2) {
}

int eliminateMaximum_v2(const vector<int>& dist, const vector<int>& speed) {
    const int sz { (int)dist.size() };
    int monstCounter{};
    vector< pair<int, int> > vec(sz);

    /*
        ... TO-DO
    */

    return monstCounter;
}


int main(){
    cout << eliminateMaximum({6,9,6,7,9,7,10,6,6,7},{1,1,1,1,2,1,2,1,1,2}) << endl;
    cout << eliminateMaximum({1,1,2,3},{1,1,1,1}) << endl;
    cout << eliminateMaximum({3,2,4},{5,3,2}) << endl;
    cout << eliminateMaximum({4,2,3},{2,1,1}) << endl;
    return 0;
}
