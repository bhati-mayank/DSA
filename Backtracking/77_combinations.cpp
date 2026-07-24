#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void Solve(int n, int k, int i, vector<int>& temp){
        if(k == 0){
            result.push_back(temp);
            return;
        }
        if(i > n)
            return;
        temp.push_back(i);
        Solve(n, k-1, i+1, temp);
        temp.pop_back();
        Solve(n, k, i+1, temp);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        Solve(n, k, 1, temp);
        return result;
    }
};