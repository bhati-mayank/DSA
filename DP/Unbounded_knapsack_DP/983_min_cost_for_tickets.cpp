#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    int t[365];

    int Solve(vector<int>& days, vector<int>& cost, int i){
        if(i >= n)
            return 0;

        if(t[i] != -1)
            return t[i];

        //one-day pass
        int cost_1 = cost[0] + Solve(days, cost, i+1);

        //7-day pass
        //find the next index that will not be covered by a 7 day pass
        int max_day = days[i] + 7;

        int j = i;

        while(j < n && days[j] < max_day)
            j++;

        int cost_2 = cost[1] + Solve(days, cost, j);

        //30 - day pass
        
        max_day = days[i] + 30;
        j= i;

        while(j < n && days[j] < max_day)
            j++;

        int cost_3 = cost[2] + Solve(days, cost, j);

        return t[i] = min({cost_3, cost_2,cost_1});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        n = days.size();
        memset(t, -1, sizeof(t));
        return Solve(days, costs, 0);
    }
};