
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    vector<vector<int>> dir = {{0,1}, {1,0}};

    int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y){

        int p_x = find(x);
        int p_y = find(y);

        if(p_x == p_y)
            return false;

        if(rank[p_x] > rank[p_y])
            parent[p_y] = p_x;

        else if(rank[p_x] < rank[p_y])
            parent[p_x] = p_y;

        else{
            parent[p_x] = p_y;
            rank[p_y]++;
        }

        return true;
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();


        parent.resize(m*n);
        rank.resize(m*n, 1);

        for(int i = 0; i < m*n; i++)
            parent[i] = i;

        int islands = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1')
                    islands++;
            }
        }



        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0') continue;

                int node = i*n + j;

                for(auto &vec : dir){
                    int new_i = i + vec[0];
                    int new_j = j + vec[1];


                    if(new_i < m && new_i >= 0 && new_j < n && new_j >= 0 && grid[new_i][new_j] == '1'){
                        int adjNode = new_i*n + new_j;
                        if(Union(node, adjNode)){
                            islands--;
                        }
                    }
                }
            }
        }

        return islands;
    }
};