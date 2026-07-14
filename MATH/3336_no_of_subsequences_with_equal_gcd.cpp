
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int t[201][201][201];
    const int MOD = 1e9+7;
    int Solve(int i, int first, int second, vector<int>&nums){
        if(i == n){
            bool bothempty = (first != 0 && second != 0);
            bool gcd_match = first == second;

            return  bothempty && gcd_match;
        }

        if( t[i][first][second] != -1) 
            return t[i][first][second];
        
        int skip = Solve(i+1, first, second, nums)%MOD;
        int one = Solve(i+1, __gcd(first, nums[i]), second, nums)%MOD;
        int two = Solve(i+1, first, __gcd(second, nums[i]), nums)%MOD;


        return t[i][first][second] = ( 0LL + skip + one + two)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        
        n = nums.size();

        memset(t, -1, sizeof(t));

        return Solve(0, 0, 0, nums);

    }
};