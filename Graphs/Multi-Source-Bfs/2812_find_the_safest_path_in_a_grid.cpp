#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    bool path_exists(int safeness, vector<vector<int>>& nearest_dist){

        if(nearest_dist[0][0] < safeness)
            return false;

        vector<vector<bool>> visited(n, vector<bool>(n , false));

        //0,0 --> n-1, n-1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while(!q.empty()){
            int curr_i = q.front().first;
            int curr_j = q.front().second;

            q.pop();

            if(curr_i == n-1 && curr_j == n-1)
                return true;

            //if not then traverse and check for nbrs
            for(auto &vec : dir){
                int new_i = vec[0] + curr_i;
                int new_j = vec[1] + curr_j;

                //cehck for bounds
                if( new_i  >= 0 && new_i < n && new_j >= 0 && new_j < n && !visited[new_i][new_j]){
                    if(nearest_dist[new_i][new_j] < safeness)
                        continue;

                    q.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        n = grid.size();
        // pre-compute the nearest distance of each cell   from a thief
        vector<vector<int>> nearest_dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i ,j});
                    visited[i][j] = true;
                }
            }
        }   

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr_i = q.front().first;
                int curr_j = q.front().second;

                q.pop();

                nearest_dist[curr_i][curr_j] = level;

                //push there not visited nbrs to queue
                for(auto &vec : dir){
                    int new_i = curr_i + vec[0];
                    int new_j = curr_j + vec[1];

                    //check for bounds
                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && !visited[new_i][new_j]){
                        q.push({new_i, new_j});
                        visited[new_i][new_j] = true;
                    }
                }            
            }
            level++;
        }

        //now use binary search to find the safeness factor
        int l = 0;
        int r = 400; //acc to contraints
        int result = -1;

        while(l <= r){

            int mid_sf = l + (r-l)/2;

            if(path_exists(mid_sf, nearest_dist)){

                result = mid_sf;
                l = mid_sf + 1; //found a path with mid_sf but look for a greater one
            }
            else 
                r = mid_sf - 1;
        }
        return result;
    }
};