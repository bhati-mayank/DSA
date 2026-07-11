#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m , vector<int>(n,-1));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ;j++){
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int dist = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int curr_i = q.front().first;
                int curr_j = q.front().second;

                height[curr_i][curr_j] = dist;
                q.pop();

                for(auto &vec : dir){
                    int new_i = curr_i + vec[0];
                    int new_j = curr_j + vec[1];

                    if(new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && !visited[new_i][new_j]){
                        visited[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
                }
            }
            dist++;
        }

        return height;
    }
};