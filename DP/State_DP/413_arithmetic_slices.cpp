#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();

        if(n < 3)
            return 0;


        vector<int> t(n, 0);

        int ans = 0;

        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                t[i] =1 + t[i-1];

            ans += t[i];
        }
        

        return ans;
    }
};