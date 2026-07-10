#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int m,n;
    int t[101][101];
    int Solve(vector<vector<int>>& obstacleGrid, int i, int j){

        if(i >= m || j >= n)
            return 0;

        if(obstacleGrid[i][j] == 1)
            return 0;

        if(i == m-1 && j == n-1)
            return 1;

        if(t[i][j] != -1) return t[i][j];

        return t[i][j] = Solve(obstacleGrid, i+1, j) + Solve(obstacleGrid, i, j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        memset(t, -1, sizeof(t));

        return Solve(obstacleGrid, 0, 0);
    }
};