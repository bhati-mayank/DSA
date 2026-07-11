#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> grid(row, vector<int>(col, -1));

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int dis = 0;

        while(!q.empty()){

            int size = q.size();

            while(size--){
                int curr_i = q.front().first;
                int curr_j = q.front().second;

                q.pop();

                grid[curr_i][curr_j] = dis;

                //iterate to nbrs
                for(auto &vec : dir){
                    int new_i = vec[0] + curr_i;
                    int new_j = vec[1] + curr_j;

                //check for bounds
                    if(new_i >= 0 && new_i < row && new_j >= 0 && new_j < col && !visited[new_i][new_j]){
                        visited[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
                }
            }
            dis++;
        }
        return grid;
    }
};

