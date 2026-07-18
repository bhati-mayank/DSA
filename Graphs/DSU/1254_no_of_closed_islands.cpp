#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    int find(int x){
        if(x == parent[x])
            return x;

        return parent[x] = find(parent[x]);

    }

    void Union(int x, int y){

        int p_x = find(x);
        int p_y = find(y);

        if(p_x == p_y)
            return;

        if(rank[p_x] > rank[p_y])
            parent[p_y] = p_x;


        else if(rank[p_x] > rank[p_y])
            parent[p_x] = p_y;

        else{
            parent[p_x] = p_y;
            rank[p_y]++;
        }
    }
    int closedIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        parent.resize(m*n+1);
        rank.resize(m*n+1, 1);

        for(int i = 0; i <= m*n; i++){
            parent[i] = i;
        }

        int boundary = m*n;


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    continue;

                int node = i*n + j;

                if(i == 0 || j == 0 || i == m-1 || j == n-1)
                    Union(node, boundary);

                for(auto &vec : dir){
                    int ni = i + vec[0];
                    int nj = j + vec[1];

                    if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 0){
                        int adjNode = ni*n + nj;

                        Union(node, adjNode);
                    }
                }
            }
        }

        unordered_set<int> st;

        int boundary_root = find(boundary);

        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    int node = i*n+j;

                    int root = find(node);

                    if(root != boundary_root)
                        st.insert(root);
                }
            }
        }

        return st.size();
        
    }
};