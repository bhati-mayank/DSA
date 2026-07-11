#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{0,1, 1},{0,-1, 2},{1,0, 3},{-1,0, 4}};
    int minCost(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        //min heap
        priority_queue<P, vector<P>, greater<P>> pq;

        //result array
        vector<vector<int>> result(row, vector<int>(col, INT_MAX));
        result[0][0] = 0;

        //push the src node and itd dist to pq
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            int curr_cost = p.first;
            auto coord = p.second;

            int x = coord.first;
            int y = coord.second;

            if(x == row-1 && y == col-1)
                return curr_cost;

            for(auto &vec : directions){
                int new_x = x + vec[0];
                int new_y = y + vec[1];
                int curr_dir = vec[2];

                if(new_x >= 0 && new_y >= 0 && new_x < row && new_y < col){
                    if(grid[x][y] == curr_dir){
                        int cost = 0;
                        if(result[new_x][new_y] > cost+curr_cost){
                            result[new_x][new_y] = cost+curr_cost;
                            pq.push({cost+curr_cost, {new_x, new_y}});
                        }
                    }
                    else{
                        int cost = 1;
                        if(result[new_x][new_y] > cost+curr_cost){
                            result[new_x][new_y] = cost+curr_cost;
                            pq.push({cost+curr_cost, {new_x, new_y}});
                        }                       
                    }
                }

            }
        }

        return -1;

    }
};