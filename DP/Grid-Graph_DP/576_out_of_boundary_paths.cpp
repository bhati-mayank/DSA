#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row,col;
    int t[51][51][51];
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    const int MOD = 1e9+7;
    int Solve(int i,  int j, int maxMove){

        if(maxMove < 0)
            return 0;

        if(i < 0 || j < 0 || i >= row || j >= col)
            return 1;

        if(t[i][j][maxMove] != -1)
            return t[i][j][maxMove];

        int ans = 0;

        for(auto &vec : dir){

            int new_i = i + vec[0];
            int new_j = j + vec[1];

            ans =(ans%MOD + Solve(new_i, new_j, maxMove-1)%MOD)%MOD;
        }

        return t[i][j][maxMove] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        row = m;
        col = n;
        memset(t, -1, sizeof(t));
        return Solve(startRow,startColumn, maxMove);

    }
};