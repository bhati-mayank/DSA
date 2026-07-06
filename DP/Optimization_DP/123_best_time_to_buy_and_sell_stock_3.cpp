#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    int t[100001][2][3];

    int Solve(vector<int>& prices, int day, int left, bool flag){
        //if we reach lsat day or beyond
        if(day >= n) return 0;

        //if transaction left are zero
        if(left == 0) return 0;

        if(t[day][flag][left] != -1)
            return t[day][flag][left];

        if(flag){
            //can buy today but can choose to or not to
            t[day][flag][left] = max(Solve(prices, day+1, left, false) - prices[day],
                                        Solve(prices, day+1, left, true));
        }

        //can sell today
        else{
            t[day][flag][left] = max(Solve(prices, day+1, left-1, true) + prices[day],
                                        Solve(prices, day+1, left, false));
        }

        return t[day][flag][left];
    }
    int maxProfit(vector<int>& prices) {
        
        n = prices.size();

        memset(t, -1, sizeof(t));

        return Solve(prices, 0, 2, true);
    }
};