#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int t[301][5001];
    int Solve(vector<int>& coins, int amount, int i){
        if(i == n){
            return amount == 0;
        }

        if(t[i][amount] != -1)
            return t[i][amount];


        //skip the curr coin
        int skip = Solve(coins, amount, i+1);

        //take it
        int take = 0;
        if(coins[i] <= amount){
            take = Solve(coins, amount-coins[i], i);
        }


        return t[i][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();

        memset(t, -1, sizeof(t));

        return Solve(coins, amount, 0);
    }
};