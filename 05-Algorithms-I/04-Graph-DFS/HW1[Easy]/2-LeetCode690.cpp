#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(unordered_map<int, Employee*> &graph, int id, int &sum){
        Employee* emp =  graph[id];
        sum += emp->importance;

        for(auto emp_id : emp->subordinates)
            dfs(graph, emp_id, sum);
    }

    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        unordered_map<int, Employee*> graph;

        for(auto emp : employees)
            graph[emp->id] = emp;


        dfs(graph, id, sum);
        return sum;
    }
};

int main(){
    return 0;
}
