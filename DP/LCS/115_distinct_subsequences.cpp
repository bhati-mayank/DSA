#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    int dp[1001][1001];
    int Solve(string &s, string &t, int i, int j){

        if(i != m && j == n)    return 1;
        if(i == m && j == n)    return 1;
        if(i == m && j != n)    return 0;

        if(dp[i][j] != -1)
            return dp[i][j];


        int take = 0;
        if(s[i] == t[j]){
            take = Solve(s, t, i+1, j+1);
        }

        int skip = Solve(s, t, i+1, j);

        return dp[i][j] = (take + skip);
    }
    int numDistinct(string s, string t) {
        m = s.size();
        n = t.size();

        memset(dp, -1, sizeof(dp));

        return Solve(s, t, 0, 0);
    }
};