#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({grid[0][0], {0, 0}});

        vector<vector<int>> result(n, vector<int>(n, INT_MAX));
        result[0][0] = grid[0][0];

        while(!pq.empty()){

            auto p = pq.top();
            pq.pop();

            auto cell = p.second;
            int curr_i = cell.first;
            int curr_j = cell.second;
            int curr_time = p.first;

            if(curr_i == n-1 && curr_j == n-1)
                return curr_time;

            if(curr_time > result[curr_i][curr_j])
                continue;

            for(auto &vec : dir){

                int ni = curr_i + vec[0];
                int nj = curr_j + vec[1];

                if(ni >= 0 && nj >= 0 && ni < n && nj < n){

                    int new_time = max(curr_time, grid[ni][nj]);

                    if(new_time < result[ni][nj]){

                        result[ni][nj] = new_time;
                        pq.push({new_time, {ni, nj}});
                    }
                }
            }
        }

        return -1;
    }
};