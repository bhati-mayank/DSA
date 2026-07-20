#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int x,ans;
    int t[2001][2001];
    int Solve(string &s, int i ,int j){

        if(i > j) return 0;
        if(i == j) return 1;

        if(t[i][j] != -1)
            return t[i][j];


        int len = 0;
        if(s[i] == s[j]){
            len = 2 + Solve(s, i+1, j -1);

            if(i < x && j >= x)
                ans = max(len, ans);
        }

        else
            len += max(Solve(s, i+1, j), Solve(s, i, j-1));


        return t[i][j] = len;
    }
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        x = word1.size();
        ans = 0;

        memset(t, -1, sizeof(t));

        Solve(s, 0, s.size() - 1);

        return ans;
    }
};