#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> result;
    void Solve(vector<int>& nums, unordered_set<int>& st, vector<int>& temp){
        if(temp.size() == n){
            result.push_back(temp);
            return;
        }

        for(int j = 0; j < n; j++){

            if(st.count(j)) continue;
            st.insert(j);
            temp.push_back(nums[j]);
            Solve(nums, st, temp);
            st.erase(j);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        unordered_set<int> st;
        vector<int> temp;
        Solve(nums, st, temp);
        return result;
    }
};