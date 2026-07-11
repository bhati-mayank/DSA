#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row,col;
    int t[1001][1001];
    int Solve(vector<vector<int>>& grid, int i, int j){

        if(i < 0 || j < 0 || i >= row || j >= col)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];

        int one = 0;

        if(i-1 >= 0 && j+1 < col)
            if(grid[i][j] < grid[i-1][j+1])
                one = 1 + Solve(grid, i-1, j+1);

        int two = 0;

        if(j+1 < col)
            if(grid[i][j] < grid[i][j+1])
                two = 1 + Solve(grid, i, j+1);

        int three = 0;

        if(i+1 < row && j+1 < col)
            if(grid[i][j] < grid[i+1][j+1])
                three = 1 + Solve(grid, i+1, j+1);  

        return t[i][j] = max({one, two ,three});     
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        int ans = INT_MIN;

        memset(t, -1, sizeof(t));

        for(int i = 0; i < row; i++){
            ans = max(ans, Solve(grid, i, 0));
        }

        return ans;
    }
};