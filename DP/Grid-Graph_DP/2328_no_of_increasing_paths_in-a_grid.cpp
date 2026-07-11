#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int m,n;
    int M = 1e9+7;
    vector<vector<int>> directions  ={{1, 0}, {-1, 0},{0,1},{0,-1}};

    int t[1001][1001];

    bool isSafe(int i, int j){
        return (i >= 0 && i < m && j >= 0 &&  j< n);
    }


    int Solve(vector<vector<int>>& grid, int i, int j){

        if(t[i][j] != -1)
            return t[i][j];
        int result = 1;

        for(auto &vec : directions){
            int new_i = i + vec[0];
            int new_j = j + vec[1];

            if(isSafe(new_i, new_j) && grid[new_i][new_j] < grid[i][j]){
                result = (result%M + Solve(grid, new_i, new_j)%M);
            }
        }

        return t[i][j]= result;
    }
    int countPaths(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();

        memset(t, -1, sizeof(t));

        int result = 0;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                result = (result%M+ Solve(grid, i, j)%M)%M;
            }
        }

        return result;
    }
};