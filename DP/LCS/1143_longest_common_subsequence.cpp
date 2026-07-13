#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    int t[1001][1001];
    int Solve(string &a, string &b, int i, int j){
        if(i >= m  || j >= n) return 0;

        if(t[i][j] != -1) return t[i][j];

        if(a[i] == b[j]){
            return t[i][j] = 1 + Solve(a, b, i+1, j+1);
        }

        else
            return t[i][j] = max(Solve(a, b, i+1, j), Solve(a, b, i, j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {

        m = text1.size();
        n = text2.size();

        memset(t, -1, sizeof(t));

        return Solve(text1, text2, 0, 0);
    }
};