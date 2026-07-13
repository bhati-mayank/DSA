#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    int t[501][501];
    int Solve(string &word1, string &word2, int i, int j){
        if(i >= m || j >= n) return 0;

        if(t[i][j] != -1) return t[i][j];

        if(word1[i] == word2[j]) 
            return t[i][j] = 1 + Solve(word1, word2, i+1, j+1);

        else 
            return t[i][j] = max(Solve(word1, word2, i+1, j), Solve(word1, word2, i, j+1));
    }
    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();

        if(word1 == word2) return 0;

        memset(t, -1, sizeof(t));

        int ans = Solve(word1, word2, 0, 0);

        return (ans == 0) ? m+n : (m - ans + n - ans);
    }
};