#include<iostream>
#include<vector>
using namespace std;

void print(const vector<int> &dataset){
    for(auto item : dataset)
        cout << item << " ";
    cout << "\n";
}

void mergeSets(vector<int> &left, vector<int> &right, vector<int> &result){
    int i, j ,k;
    i = j = k = 0;

    while(i < (int)left.size() && j < (int)right.size()){
        if(left[i] < right[j])
            result[k] = left[i++];
        else
            result[k] = right[j++];
        ++k;
    }

    while(i < (int)left.size())
        result[k++] = left[i++];
    while(j < (int)right.size())
        result[k++] = right[j++];
}

void mergeSort(vector<int> &dataset){
    int length = (int)dataset.size();
    if(length > 1){
        int mid = length / 2;

        vector<int> leftSet(dataset.begin(), dataset.begin() + mid);
        vector<int> rightSet(dataset.begin() + mid, dataset.end());

        mergeSort(leftSet);
        mergeSort(rightSet);

        mergeSets(leftSet, rightSet, dataset);
    }
}




int main(){
    vector<int> items = {6, 20, 8, 19, 56, 23, 87, 41, 49, 53};
    print(items);
    mergeSort(items);
    print(items);

    return 0;
}
