
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    int m,n;
    vector<vector<bool>> visited;
    int Solve(vector<vector<int>>& grid, int i, int j){

        queue<pair<int, int>> q;
        // push the src
        q.push({i, j});
        //mark it visited
        visited[i][j] = true;

        int fish = 0;

        while(!q.empty()){
            
            auto cell = q.front();
            q.pop();

            int curr_i = cell.first;
            int curr_j = cell.second;

            fish += grid[curr_i][curr_j];

            //nbrs
            for(auto &vec : dir){
                int ni = curr_i + vec[0];
                int nj = curr_j + vec[1];

                if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] != 0 && !visited[ni][nj]){
                    q.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }

        return fish;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<bool>(n, false));

        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0 && !visited[i][j])//water cell{
                {
                    ans = max(ans, Solve(grid, i, j));
                }
            }
        }
        return ans;
    }
};