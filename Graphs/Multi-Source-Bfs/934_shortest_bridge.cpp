#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int N;
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool isSafe(int i, int j){
        return (i >= 0 && j >= 0 && i < N && j < N);
    }
    void DFS(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q, vector<vector<bool>>& visited){
        visited[i][j] = true;
        q.push({i, j});

        for(auto &vec : dir){
            int new_i = vec[0] + i;
            int new_j = vec[1] + j;

            if(isSafe(new_i, new_j) && !visited[new_i][new_j] && grid[new_i][new_j] == 1){
                DFS(grid, new_i, new_j, q, visited);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        N = n;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        bool flag = false;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    DFS(grid, i, j, q, visited);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
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

                    if(isSafe(new_i, new_j) && !visited[new_i][new_j]){
                        if(grid[new_i][new_j] == 1) return level;
                       q.push({new_i, new_j});
                       visited[new_i][new_j] = true; 
                    }
                }
            }
            level++;
        }
        return -1;
    }
};