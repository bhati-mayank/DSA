
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int t[21][1001];
    int Solve(vector<int>& nums , int n, int target){

        if(n == 0)
            return target == 0;

        if(t[n][target] != -1)
            return t[n][target];

        //take
        int take = 0;
        if(nums[n-1] <= target)
            take = Solve(nums, n-1, target - nums[n-1]);

        int skip = Solve(nums, n-1, target);


        return t[n][target] =  take + skip;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        int n = nums.size();

        for(auto &num : nums)
            sum += num;

        if(target + sum < 0 || (target + sum)%2 != 0)
            return 0;

        int find = (target + sum)/2;

        memset(t, -1, sizeof(t));

        return Solve(nums, n, find);
    }
};