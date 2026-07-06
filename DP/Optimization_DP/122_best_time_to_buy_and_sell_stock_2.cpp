#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    int t[30001][2];
    int Solve(vector<int>& prices, int day, bool flag){

        if(day >= n)
            return 0;

        if(t[day][flag] != -1)
            return t[day][flag];

        //can buy today
        if(flag){
            t[day][flag] = max(Solve(prices, day+1, false) - prices[day], Solve(prices, day+1, true));
        }

        else{
            //to sell
            t[day][flag] = max(Solve(prices, day+1, true) + prices[day], Solve(prices, day+1, false));
        }

        return t[day][flag];

        
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        memset(t, -1, sizeof(t));

        return Solve(prices, 0, true);
    }
};