
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        int sum = 0;

        mp[0] = -1;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            int remain = sum%k;

            if(remain < 0)
                remain += k;

            if(mp.find(remain) != mp.end()){
                int temp = i - mp[remain];

                if(temp >= 2)
                    return true;
            }
            else
                mp[remain] = i;
                
        }

        return false;
    }
};