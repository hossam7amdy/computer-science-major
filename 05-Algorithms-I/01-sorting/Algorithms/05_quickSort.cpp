#include<iostream>
#include<vector>
using namespace std;

void print(const vector<int> &dataset){
    for(auto item : dataset)
        cout << item << " ";
    cout << "\n";
}

int Partition(vector<int> &dataset, int first, int last){
    int pivotValue = dataset[first];
    int lower = first + 1, upper = last;

    while(lower <= upper){
        while(dataset[lower] < pivotValue)
            ++lower;
        while(dataset[upper] > pivotValue)
            --upper;
        if(lower < upper)
            swap(dataset[lower], dataset[upper]);
    }
    swap(dataset[first], dataset[upper]);
    return upper;
}

void quickSort(vector<int> &dataset, int first, int last){
    if(first < last){
        int pivotIdx = Partition(dataset, first, last);

        quickSort(dataset, first, pivotIdx - 1);
        quickSort(dataset, pivotIdx + 1, last);
    }
}

int main(){
    vector<int> items = {6, 20, 8, 19, 56, 23, 87, 41, 49, 53};
    print(items);
    quickSort(items, 0, (int)items.size() - 1);
    print(items);

    return 0;
}
