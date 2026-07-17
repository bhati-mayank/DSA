
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> parent;
    vector<int> size;

    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1},{-1,0}};

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

        if(size[p_x] > size[p_y]){
            parent[p_y] = p_x;
            size[p_x] += size[p_y];
        }

        else if(size[p_x] < size[p_y]){
            parent[p_x] = p_y;
            size[p_y] += size[p_x];
        }

        else{
            parent[p_x] = p_y;
            size[p_y] += size[p_x];
        }

        return true;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        parent.resize(m*n);
        size.resize(m*n, 0);

        for(int i = 0; i < m*n; i++){
            parent[i] = i;
        }

        int cells = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    cells++;
                    size[i*n+j] = 1;
                }

                
            }
        }

        for(int i = 0; i < m; i++){
            for(int j  = 0; j < n; j++){
                if(grid[i][j] == 0)
                    continue;

                int node = i*n + j;

                for(auto &vec : dir){
                    int new_i = i + vec[0];
                    int new_j = j + vec[1];

                    if(new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && grid[new_i][new_j] == 1){
                        int adjNode = new_i*n+new_j;

                        if(Union(node, adjNode))
                            cells--;
                    }
                }
            }
        }

        int ans = *max_element(size.begin(), size.end());

        return ans;
    }
};