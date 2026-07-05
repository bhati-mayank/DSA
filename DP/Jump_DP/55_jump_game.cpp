#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    int t[10001];
    bool Solve(vector<int>& nums, int i){
        if(i == n-1)
            return true;

        if( i >= n)
            return false;

        if(t[i] != -1)
            return t[i];

        int jumps = nums[i];

        for(int jump = 1; jump <= jumps; jump++){
            if(Solve(nums, i+jump))
                return t[i] = true;
        }

        return t[i] = false;

        
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return Solve(nums, 0);
    }
};