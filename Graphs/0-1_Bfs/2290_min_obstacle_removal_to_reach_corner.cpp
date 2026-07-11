#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    typedef pair<int, pair<int, int>> P;
    int minimumObstacles(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<vector<int>> result(row, vector<int>(col, INT_MAX));

        if(grid[0][0] == 0)
            result[0][0] = 0;

        else result[0][0] = 1;

        pq.push({result[0][0], {0,0}});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            int curr_cost = p.first;

            auto coord = p.second;

            int x = coord.first;
            int y = coord.second;

            for(auto &vec : dir){
                int new_x =  x + vec[0];
                int new_y = y + vec[1];

                if(new_x >= 0 && new_y >=0 && new_x < row && new_y < col){
                    int cost;
                    if(grid[new_x][new_y] == 0){
                        cost = 0;
                    }else cost = 1;

                    if(curr_cost + cost < result[new_x][new_y]){
                        result[new_x][new_y] = curr_cost+cost;
                        pq.push({curr_cost+cost, {new_x, new_y}});
                    }
                }
            }
        }
        return result[row-1][col-1]; 

    }
};