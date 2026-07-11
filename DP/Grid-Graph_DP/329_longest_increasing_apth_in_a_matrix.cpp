#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    int t[201][201];
    bool isSafe(int i, int j){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    vector<vector<int>> directions ={{1,0},{-1, 0},{0,1},{0,-1}};

    int Solve(vector<vector<int>> & matrix, int i, int j){
        int result = 1;

        if(t[i][j] != -1)
            return t[i][j];

        for(auto &vec : directions){
            int new_i = i + vec[0];
            int new_j = j + vec[1];

            if(isSafe(new_i, new_j) && matrix[new_i][new_j] > matrix[i][j]){
                result = max(result,1 + Solve(matrix, new_i, new_j));
            }
        }

        return t[i][j] = result;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        memset(t, -1, sizeof(t));

        int result = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                result = max(result , Solve(matrix, i, j));
            }
        }

        return result;
    }
};