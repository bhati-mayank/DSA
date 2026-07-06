#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int t[100001][2];
    int Solve(vector<int>& prices, int day, bool to_buy){

        if(day >= n)
            return 0;

        if(t[day][to_buy] != -1)
            return t[day][to_buy];

        int profit = 0;

        if(to_buy){
            int consider = Solve(prices, day+1, false) - prices[day];
            int not_consider = Solve(prices, day+1, true);

            profit = max({profit, consider, not_consider});
        }else{ //sell --> true
            int consider = Solve(prices, day+2, true) + prices[day];
            int not_consider = Solve(prices, day+1, false);

            profit = max({profit, consider, not_consider});
        }


        return t[day][to_buy] = profit;
    }
    int maxProfit(vector<int>& prices) {

        memset(t, -1, sizeof(t));
        
        n = prices.size();

        return Solve(prices, 0, true);
    }
};