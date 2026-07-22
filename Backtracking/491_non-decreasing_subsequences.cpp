
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    vector<vector<int>> result;

    void Solve(vector<int>& nums, int i, vector<int>& temp, int prev){

        if(temp.size() >= 2)
            result.push_back(temp);

        unordered_set<int> used;

        for(int j = i; j < n; j++){

            if(nums[j] < prev)
                continue;

            if(used.count(nums[j]))
                continue;

            used.insert(nums[j]);

            temp.push_back(nums[j]);
            Solve(nums, j + 1, temp, nums[j]);
            temp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {

        n = nums.size();

        vector<int> temp;

        Solve(nums, 0, temp, -101);

        return result;
    }
};