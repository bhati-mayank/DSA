#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    const int MOD = 1e9+7;
    long long t[31][1001];
    int Solve(int n, int k, int target){
        if(target < 0)
            return 0;

        if(n == 0)
            return target == 0;

        if(t[n][target] != -1)
            return t[n][target];

        long long ways = 0;

        for(int face = 1; face <= k; face++){
            ways = (ways%MOD + Solve(n-1, k, target - face)%MOD)%MOD;

        }

        return t[n][target] = ways;
    }
    int numRollsToTarget(int n, int k, int target) {

        memset(t, -1, sizeof(t));
        
        return Solve(n, k, target);
    }
};