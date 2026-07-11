#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        queue<pair<int,int>> q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        //cnt fresh oranges
        int fresh = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0)
            return 0;



        int level = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr_i = q.front().first;
                int curr_j = q.front().second;

                q.pop();

                //nbrs
                for(auto &vec : dir){
                    int new_i = vec[0] + curr_i;
                    int new_j = vec[1] + curr_j;

                    //bounds
                    if(new_i >= 0 && new_i < row && new_j >= 0 && new_j < col 
                        && !visited[new_i][new_j] && grid[new_i][new_j] == 1){

                            visited[new_i][new_j] = true;
                            q.push({new_i, new_j});
                            fresh--;
                        }
                }
            }
            level++;
        }

        if(fresh > 0)
            return -1;

        return level-1; //-1 because
    }
};