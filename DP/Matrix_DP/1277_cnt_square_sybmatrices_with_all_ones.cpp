#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t[301][301];
    int row, col;
    int Solve(vector<vector<int>>& grid, int i, int j){
        if(i >= row || j >= col)
            return 0;

        if(grid[i][j] == 0)
            return t[i][j] = 0;

        if(t[i][j] != -1) return t[i][j];

        int right = Solve(grid, i, j+1);
        int below = Solve(grid, i+1, j);
        int diag = Solve(grid, i+1, j+1);

        return t[i][j] = 1 + min({right, below, diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        

        row = matrix.size();
        col = matrix[0].size();

        memset(t, -1, sizeof(t));

        int result = 0;
        for(int i =0; i < row; i++){
            for(int j = 0; j < col;j++){
                result += Solve(matrix, i, j);
            }
        }
        return result;
    }
};