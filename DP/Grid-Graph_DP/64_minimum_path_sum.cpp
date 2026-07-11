#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    int t[201][201];
    int Solve(vector<vector<int>>& grid, int i, int j){
        if( i >= m || j >= n) return INT_MAX;
        if( i == m-1 && j == n-1)
            return grid[i][j];

        if(t[i][j] != -1)
            return t[i][j];

        int right = Solve(grid, i, j+1);
        int down = Solve(grid, i+1, j);


        if(right != INT_MAX)
            right += grid[i][j];

        if(down != INT_MAX)
            down += grid[i][j];

        return t[i][j] = min(right, down);
   }
    int minPathSum(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));
        return Solve(grid, 0, 0);
    }
};