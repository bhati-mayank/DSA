#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row,col;
    int t[71][71][71];
    int Solve(vector<vector<int>>& grid, int i, int j_1, int j_2){

        if(i < 0 || j_1 < 0 || j_2 < 0 ||  i >= row || j_1 >= col || j_2 >= col)
            return INT_MIN;

        if(i == row -1){
            if(j_1 == j_2)
                return grid[i][j_1];
            return (grid[i][j_1] + grid[i][j_2]);
        }

        if(t[i][j_1][j_2] != -1)
            return t[i][j_1][j_2] ;

        int ans = INT_MIN;

        for(int l = -1; l <= 1 ;l++){
            for(int k = -1; k <= 1; k++){
                ans = max(ans, Solve(grid, i+1, j_1+l, j_2+ k));
            }
        }


        if(j_1 == j_2)
            ans += grid[i][j_1];

        else ans += grid[i][j_1] + grid[i][j_2];


        return t[i][j_1][j_2]  = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        memset(t, -1, sizeof(t));

        return Solve(grid, 0, 0, col-1);
    }
};