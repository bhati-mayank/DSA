#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int r[1001][1001];
    int Solve(string &s , string &t, int i, int j){

        if(i >= m || j >= n)
            return 0;

        if(r[i][j] != -1) return r[i][j];

        if(s[i] == t[j])
            return r[i][j] = 1 + Solve(s, t, i+1, j+1);

        else 
            return r[i][j] = max(Solve(s,t, i+1, j), Solve(s, t, i, j+1));
    }
    int longestPalindromeSubseq(string s) {

        string t = s;
        
        reverse(begin(s), end(s));

        memset(r, -1, sizeof(r));

        m = s.size();
        n = t.size();

        return Solve(s, t, 0, 0);

    }
};