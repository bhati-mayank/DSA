#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<bool>> visited;

    bool Solve(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        bool subIsland = true;


        while(!q.empty()){
            auto cell = q.front();
            q.pop();

            int curr_i = cell.first;
            int curr_j = cell.second;

            if(grid1[curr_i][curr_j] != 1)
                subIsland = false;

            //nbrs
            for(auto &vec : dir){
                int ni = vec[0] + curr_i;
                int nj = vec[1] + curr_j;

                if(ni >= 0 && nj >= 0 && nj < n && ni < m && !visited[ni][nj] && grid2[ni][nj] == 1){
                    q.emplace(ni, nj);
                    visited[ni][nj] = true;
                }
            }

        }

        return subIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();

        visited.assign(m, vector<bool>(n, false));

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1 && !visited[i][j]){
                    if(Solve(grid1, grid2, i, j))
                        ans++;
                }
            }
        }

        return ans;
    }
};