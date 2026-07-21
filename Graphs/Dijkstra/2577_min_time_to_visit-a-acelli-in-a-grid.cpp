#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    int minimumTime(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if(m > 1 && n > 1 && grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()){

            int curr_time = pq.top().first;
            auto cell = pq.top().second;
            pq.pop();

            int curr_i = cell.first;
            int curr_j = cell.second;

            if(curr_time > dist[curr_i][curr_j])
                continue;

            if(curr_i == m-1 && curr_j == n-1)
                return curr_time;

            for(auto &vec : dir){

                int ni = curr_i + vec[0];
                int nj = curr_j + vec[1];

                if(ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;

                int new_time;

                if(grid[ni][nj] <= curr_time + 1){
                    new_time = curr_time + 1;
                }
                else if((grid[ni][nj] - (curr_time)) % 2 == 0){
                    new_time = grid[ni][nj] + 1;
                }
                else{
                    new_time = grid[ni][nj];
                }

                if(new_time < dist[ni][nj]){
                    dist[ni][nj] = new_time;
                    pq.push({new_time, {ni, nj}});
                }
            }
        }

        return -1;
    }
};