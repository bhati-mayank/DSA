#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n,m;
    int t[1001][1001];
    int Solve(string &s1, string &s2, int i, int j){

        if(i >= n && j >= m)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];

        if(i >= n)
            return s2[j] + Solve(s1, s2, i, j+1);

        if(j >= m)
            return s1[i] + Solve(s1, s2, i+1, j);

        if(s1[i] ==s2[j])
            return Solve(s1, s2, i+1, j+1);

        int delete_ith_elm = s1[i] + Solve(s1, s2, i+1, j);
        int delete_jth_elm = s2[j] + Solve(s1, s2, i, j+1);

        return t[i][j] = min(delete_ith_elm, delete_jth_elm);
    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.length();
        m = s2.length();

        memset(t, -1, sizeof(t));

        return Solve(s1, s2, 0, 0);
    }
};