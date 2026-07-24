#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> result;

    void Solve(int i, vector<int>& candidates, vector<int>& temp, int target)
    {
        if(target == 0){
            result.push_back(temp);
            return;
        }

        if(target < 0)
            return;

        for(int j = i; j < n; j++){
            temp.push_back(candidates[j]);
            Solve(j, candidates, temp, target - candidates[j]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();

        vector<int> temp;
        Solve(0, candidates, temp, target);

        return result;
    }
};