#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n ;
    int t[100001][2][2];
    int Solve(vector<int>& prices , int i, bool flag, int trans){
        if( i == n)
            return 0;

        if(trans == 0)
            return 0;

        if(t[i][flag][trans] != -1)
            return t[i][flag][trans];

        //buy
        if(flag){
            t[i][flag][trans] = max(Solve(prices, i+1, false, trans) - prices[i],  Solve(prices, i+1, true , trans ));
        }

        //sell
        else{
            
            t[i][flag][trans] = max(prices[i] + Solve(prices, i+1, true, trans-1), Solve(prices, i+1, false, trans));
        }

        return t[i][flag][trans];

    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();

        memset(t, -1, sizeof(t));

        return Solve(prices, 0, true, 1);
    }
};