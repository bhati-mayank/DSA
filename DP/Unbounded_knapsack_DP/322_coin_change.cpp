#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int t[13][10001];
    long long Solve(vector<int>& coins, int amount, int i){
        if(i == n){
            if( amount == 0)
                return 0;

            return INT_MAX;
        }

        if(t[i][amount] != -1)
            return t[i][amount];

        //can skip the curr coin
        long long skip = Solve(coins, amount, i+1);

        //can take and since we have no limit to coins we can choose it again
        long long take = INT_MAX;
        if(coins[i] <= amount){
            int temp = Solve(coins, amount - coins[i], i);

            if(temp != INT_MAX)
                take = 1 + temp;
        }

        return t[i][amount]= min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();

        memset(t, -1, sizeof(t));

        int ans = Solve(coins, amount, 0);

        return ans == INT_MAX ? -1 : ans;
    }
};