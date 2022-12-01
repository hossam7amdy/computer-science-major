// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// WARNING: this solution gives `TLE`

#include<bits/stdc++.h>
using namespace std;

int k;
int subset;
vector<int> numList;

vector<int> partitionSum;
vector<vector<int>> partitions;

bool tryPartition(int idx){ // O(K^N)
    if(idx == numList.size())
        return true;

    for(int i = 0; i < k; ++i){
        if(partitionSum[i] + numList[idx] <= subset){
            partitions[i].push_back(numList[idx]);
            partitionSum[i] += numList[idx];

            if(tryPartition(idx + 1))
                return true;

            partitionSum[i] -= numList[idx];
            partitions[i].pop_back();
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

    subset = sum / k;

    partitions = vector<vector<int>>(k);
    partitionSum = vector<int>(k, 0);

    return tryPartition(0);
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
    // partition_ksubsets_equalsum( { 10, 5, 5, 4, 3, 6, 6, 7, 6, 8, 6, 3, 4, 5, 3, 7 }, 8);
    partition_ksubsets_equalsum({18,20,39,73,96,99,101,111,114,190,207,295,471,649,700,1037}, 4);
	partition_ksubsets_equalsum( { 1739, 5391, 8247, 236, 5581, 11, 938, 58, 1884, 823, 686, 1760, 6498, 6513, 6316, 2867 }, 6);

    return 0;
}
