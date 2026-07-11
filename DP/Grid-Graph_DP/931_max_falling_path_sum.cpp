#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row,col;
    vector<vector<int>> t;
    int Solve(vector<vector<int>>& matrix, int i, int j){

        if(i < 0 || j < 0 || i >= row || j >= col)
            return INT_MAX;

        if( i == row -1 )
            return matrix[i][j];

        if(t[i][j] != 101)
            return t[i][j];

        int one = Solve(matrix, i+1, j);
        int two = Solve(matrix, i+1, j+1);
        int three = Solve(matrix, i+1, j-1);

        if(one != INT_MAX)
            one += matrix[i][j];

        if(two != INT_MAX)
            two += matrix[i][j];

        if(three != INT_MAX)
            three += matrix[i][j];

        return t[i][j] = min({one, two, three});


    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        row = n;
        col = n;

        t.assign(101, vector<int>(101, 101));

        int ans = INT_MAX;


        for(int j = 0; j < col; j++){
            ans = min(ans, Solve(matrix, 0, j));
        }

        return ans;
    }
};