#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void remove_neg(vector<int> &v){
    auto it = v.begin();
    while(it != v.end()){
        if(*it < 0)
            it = v.erase(it);
        else
            it++;
    }
    return;
}

void print_vec(const auto &v){
    for(auto val : v)
        cout << val << " ";
    cout << "\n";
    return;
}

void print_2d_vec(const auto &v2d){
    for(auto row : v2d){
        for(auto col : row)
            cout << col << " ";
        cout << "\n";
    }
}

void print_3d_vec(const auto &v3d){
    for(int i=0; i<(int)v3d.size(); i++)
        print_2d_vec(v3d[i]); //print 2D vector
}

int main(){
    vector<int> v1;
    v1.push_back(1), v1.push_back(3), v1.push_back(5), v1.push_back(7);
    v1.insert(v1.begin(),{-2, 2, 4, -6, 8});
    auto it = find(v1.begin(), v1.end(), -2);
    print_vec(v1);
    remove_neg(v1);
    print_vec(v1);
    cout << "2D Vectors*************************\n";

    vector<string> matrix {"Hossam", "Hamdy", "Torad"};
    cout << "Rows = " << matrix.size() << "\n";
    for(const auto col : matrix)
    cout << "Cols = " << col.size() << " ";
    cout << "\n";
    print_2d_vec(matrix); //internally: 2D matrix of chars

    vector< vector<int>> v2d(5, vector<int>(v1));
    cout << v2d.size() << "\n"; //how many rows
    cout << "size of 1st row = " <<  v2d[0].size() << "\n";
    //add new elements to the first row
    v2d[0].push_back(-2);
    v2d[0].push_back(26);
    cout << "size of 1st row = " <<  v2d[0].size() << "\n";
    //remove 1st element of 2nd row;
    v2d[1].erase(v2d[1].begin());
    cout << "size of 2nd row = " <<  v2d[1].size() << "\n";
    print_2d_vec(v2d);

    cout << "\n3D Vectors******************************\n";
    vector<vector<vector<int>>> v3d(3, vector<vector<int>>(5, vector<int>(v1)));
    cout << "Depth = " << v3d.size() << " Rows = " << v3d[0].size() << " Cols = " << v3d[0][0].size() << "\n";
    print_3d_vec(v3d);

    cout << "\n\n";

    vector<vector<vector<int>>> cool_v3d(3, v2d);
    print_3d_vec(cool_v3d);

    return 0;
}
