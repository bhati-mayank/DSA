
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int t[201][20001];
    bool Solve(vector<int>& nums, int n , int sum){
        if(sum == 0)
            return true;

        if(n == 0)
            return false;

        if(t[n][sum] != -1)
            return t[n][sum]; 

        //take
        bool take = false;

        if(nums[n-1] <= sum){
            take = Solve(nums, n-1, sum - nums[n-1]);
        }

        //skip
        int skip = Solve(nums, n-1, sum);

        return t[n][sum] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        
            
        n = nums.size();

        int sum = 0;

        for(auto &num : nums)
            sum += num;

        if(sum % 2 ==1)
            return false;

        int target = sum/2;

        memset(t, -1, sizeof(t));


        return Solve(nums,n, target);
    }
};