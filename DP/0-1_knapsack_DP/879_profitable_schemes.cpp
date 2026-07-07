#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N;
    int t[101][101][101];
    const int MOD = 1e9 + 7;
    int Solve(int i, int pro, int people,  vector<int>& group, vector<int>& profit, int &minProfit){

        if(people > N)
            return 0;

        if(i == group.size() ){
            if(pro >= minProfit)
                return 1;

            return 0;
        }

        if(t[i][pro][people] != -1)
            return t[i][pro][people];


        long long not_taken = Solve(i+1, pro, people, group, profit, minProfit)%MOD;
        long long     taken = Solve(i+1, min(pro + profit[i], minProfit), people+ group[i], group, profit, minProfit)%MOD;

        return t[i][pro][people] = (taken + not_taken)%MOD;


    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {

        N = n;

        memset(t, -1, sizeof(t));

        return Solve(0, 0, 0, group, profit, minProfit);
    }
};