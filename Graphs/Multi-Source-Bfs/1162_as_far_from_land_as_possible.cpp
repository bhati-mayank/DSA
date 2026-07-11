
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int maxDistance(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> result(row, vector<int>(col,-1));
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        //push all the src to a queue--> src is land since we need to max the dist from land

        queue<pair<int, int>> q;

        //land --> 1
        int land = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    land++;
                    visited[i][j] = true;
                }
            }
        }

        if(land == 0 || land == row*col)
            return -1;

        int level = 0;
        int ans = INT_MIN;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr_i = q.front().first;
                int curr_j = q.front().second;

                result[curr_i][curr_j] = level;
                ans = max(ans, level);
                q.pop();

                //nbrs
                for(auto &vec : dir){
                    int new_i = vec[0] + curr_i;
                    int new_j = vec[1] + curr_j;

                    //bounds
                    if(new_i < row && new_j < col && new_i >= 0 && new_j >= 0 && !visited[new_i][new_j]){
                        visited[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
                }
            }
            level++;
        }

        return ans == INT_MIN ? -1 : ans;
        
    }
};