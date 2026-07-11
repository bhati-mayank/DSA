#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row,col;
    vector<vector<int>> t;
    int Solve(vector<vector<int>>& grid, int i, int j){

        if(i == row - 1)
            return grid[i][j];

        if(t[i][j] != 100)
            return t[i][j];

        int ans = INT_MAX;

        for(int k = 0;k < col; k++){
            
            if(k == j) continue;

            ans = min(ans, Solve(grid, i+1, k));
        }
        return t[i][j] = grid[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        row = col = n;
        t.assign(201, vector<int>(201, 100));

        int ans = INT_MAX;

        for(int j = 0; j < col; j++){
            ans =  min(ans, Solve(grid, 0, j));
        }

        return ans;
    }
};