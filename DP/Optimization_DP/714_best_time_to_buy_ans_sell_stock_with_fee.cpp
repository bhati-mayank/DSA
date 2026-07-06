#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int cost;
    int t[50001][2];
    int Solve(vector<int>& prices, int day, bool to_buy){
        if(day >= n)
            return 0;

        if(t[day][to_buy] != -1)
            return t[day][to_buy];

        if(to_buy){
            int consider = Solve(prices, day+1, false) - prices[day];
            int not_consider = Solve(prices, day+1, true);

            t[day][to_buy] = max(consider, not_consider);
        }else{
            int consider = Solve(prices, day+1, true) + prices[day] - cost;
            int not_consider = Solve(prices, day+1, false);

            t[day][to_buy] = max( consider, not_consider);
        }
        return t[day][to_buy];
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        cost = fee;

        memset(t, -1, sizeof(t));

        return Solve(prices, 0, true);
    }
};