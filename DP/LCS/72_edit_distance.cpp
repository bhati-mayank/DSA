#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    vector<vector<int>> t;

    int Solve(string word1, string word2, int i, int j){

        if(i == m && j == n)   
            return 0;

        else if(i == m)
            return n-j;

        else if(j == n)
            return m - i;

        if(t[i][j] != -1)
            return t[i][j];


        if(word1[i] == word2[j])
            return Solve(word1, word2, i+1, j+1);


        int insert = 1 + Solve(word1, word2, i, j+1); 
        int del    = 1 + Solve(word1, word2, i+1, j); 
        int change = 1 + Solve(word1, word2, i+1, j+1);

        return t[i][j] = min({insert, del, change});
    }

    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();

        t.resize(m, vector<int>(n, -1));

        return Solve(word1, word2, 0, 0);
    }
};