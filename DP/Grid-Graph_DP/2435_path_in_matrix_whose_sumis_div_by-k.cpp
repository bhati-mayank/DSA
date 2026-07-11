#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int row, col;
    const int MOD = 1e9 + 7;

    vector<vector<vector<int>>> dp;

    int Solve(vector<vector<int>>& grid, int k, int i, int j, int rem) {

        if (i >= row || j >= col)
            return 0;

        rem = (rem + grid[i][j]) % k;

        if (i == row - 1 && j == col - 1)
            return rem == 0;

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        int down = Solve(grid, k, i + 1, j, rem);
        int right = Solve(grid, k, i, j + 1, rem);

        return dp[i][j][rem] = (down + right) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {

        row = grid.size();
        col = grid[0].size();

        dp.assign(row, vector<vector<int>>(col, vector<int>(k, -1)));

        return Solve(grid, k, 0, 0, 0);
    }
};