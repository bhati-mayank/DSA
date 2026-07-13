#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int row, col;
    int ans = 0;
    int t[301][301];
    int Solve(vector<vector<char>> & grid, int i, int j){

        if(i >= row || j >= col) return 0;

        if(grid[i][j] == '0') return 0;

        if(t[i][j] != -1) return t[i][j];

        int below = Solve(grid, i+1, j);
        int diag = Solve(grid, i+1, j+1);
        int right = Solve(grid, i, j+1);

        ans = max(ans, 1 +  min({below, diag, right}) );

        return t[i][j] = 1 + min({below, diag, right});


    }
    int maximalSquare(vector<vector<char>>& matrix) {

        row = matrix.size();
        col = matrix[0].size();

        memset(t, -1, sizeof(t));

        for(int i = 0; i < row; i++){
            for(int j = 0; j< col; j++){
                Solve(matrix, i, j);
            }
        }

        return ans*ans;
        
    }
};