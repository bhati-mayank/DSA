#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        //push src 0,0


        if(grid[0][0] == 0)
            cost[0][0] = 0;
        else cost[0][0] = 1;

        q.push({cost[0][0], {0, 0}});

        while(!q.empty()){
            int curr_dist = q.front().first;

            auto coor = q.front().second;

            q.pop();

            int curr_i = coor.first;
            int curr_j = coor.second;

            //nbrs
            for(auto &vec : dir){
                int new_i = curr_i + vec[0];
                int new_j = curr_j + vec[1];

                //bounds
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                    int curr_cost;
                    if(grid[new_i][new_j] == 0)
                        curr_cost = 0;
                    else curr_cost = 1;

                    if(cost[new_i][new_j] > curr_dist + curr_cost){
                        cost[new_i][new_j] = curr_dist + curr_cost;
                        q.push({curr_dist + curr_cost, {new_i, new_j}});
                    }
                }

            }
        }

        //min cost to reach m-1 n-1
        int min_cost = cost[m-1][n-1];

        return health > min_cost;
    }
};