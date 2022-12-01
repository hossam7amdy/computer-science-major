// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// WARNING: this solution gives `TLE`

#include<bits/stdc++.h>
using namespace std;

const int MAX = 16 + 1;
bool visited[MAX];

int k;
int partitionSum;
vector<int> numList;

vector<vector<int>> partitions;

bool tryPartition(int partition_idx, int cur_idx, int cur_sum){ // O(K * 2^N)
    if(partition_idx == k)
        return true;

    if(cur_sum == partitionSum)
        return tryPartition(partition_idx + 1, 0, 0);

    if(cur_idx == numList.size())
        return false;

    for(int start_idx = cur_idx; start_idx < (int)numList.size(); ++start_idx){
        if(!visited[start_idx] && cur_sum + numList[start_idx] <= partitionSum){
            visited[start_idx] = true;
            partitions[partition_idx].push_back(numList[start_idx]);

            if(tryPartition(partition_idx, start_idx + 1, cur_sum + numList[start_idx]))
                return true; // pick it

            partitions[partition_idx].pop_back();
            visited[start_idx] = false;
        }
    }

    return false;
}

bool canPartitionKSubsets(const vector<int> &nums, int k_){
    k = k_;
    numList = nums;

    int sum = accumulate(numList.begin(), numList.end(), 0);
    if(sum % k != 0 || (int)numList.size() < k)
        return false;

    partitionSum = sum / k;
    partitions = vector<vector<int>>(k);
    memset(visited, false, sizeof(visited));

    return tryPartition(0,0,0);
}

void partition_ksubsets_equalsum(const vector<int> &nums, int k){
    if(!canPartitionKSubsets(nums, k)){
        cout << "Impossible\n";
        cout << "=================================\n";
        return;
    }

    for(int partition = 0; partition < partitions.size(); ++partition){
        for(auto item : partitions[partition])
            cout << item << " ";
        cout << "\n";
    }
    cout << "=================================\n";
}

int main() {
	partition_ksubsets_equalsum( { 6 }, 1);
	partition_ksubsets_equalsum( { 10 }, 2);
	partition_ksubsets_equalsum( { 5, 5 }, 2);
	partition_ksubsets_equalsum( { 1, 2, 3, 4 }, 4);
	partition_ksubsets_equalsum( { 2, 1, 4, 5, 6 }, 3);
	partition_ksubsets_equalsum( { 4, 3, 2, 3, 5, 2, 1 }, 4);
    partition_ksubsets_equalsum( { 10, 5, 5, 4, 3, 6, 6, 7, 6, 8, 6, 3, 4, 5, 3, 7 }, 8);
    partition_ksubsets_equalsum( {18,20,39,73,96,99,101,111,114,190,207,295,471,649,700,1037}, 4);
	partition_ksubsets_equalsum( { 1739, 5391, 8247, 236, 5581, 11, 938, 58, 1884, 823, 686, 1760, 6498, 6513, 6316, 2867 }, 6);

    return 0;
}
