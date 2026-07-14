
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int curr_sum = 0;
        int cnt = 0;

        for(auto x : nums){
            curr_sum = curr_sum + x;

            if(mp.find(curr_sum - k) != mp.end()){
                cnt = cnt + mp[curr_sum - k];
            }

            mp[curr_sum]++;
        }

        return cnt;
    }
};