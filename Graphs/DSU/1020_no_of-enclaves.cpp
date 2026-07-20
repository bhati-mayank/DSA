#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    vector<int> parent;
    vector<int> size;

    int find(int x){
        if( x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);


    }

    void Union(int x, int y){

        int p_x = find(x);
        int p_y = find(y);

        if(p_x == p_y)
            return;

        if(size[p_x] > size[p_y]){
            parent[p_y] = p_x;
            size[p_x] += size[p_y];
        }

        else if(size[p_x] < size[p_y]){
            parent[p_x] = p_y;
            size[p_y] += size[p_x];
        }

        else{
            parent[p_y] = p_x;
            size[p_x] += size[p_y];
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();


        parent.resize(m*n+1);
        size.resize(m*n+1, 1);

        for(int i = 0; i <= m*n; i++)
            parent[i] = i;

        int boundary = m*n;

        size[boundary] = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                    continue;
                
                int node = i*n+j;

                if(i == 0 || j == 0 || i == m-1 || j ==n-1)
                    Union(node, boundary);

                for(auto &vec : dir){
                    int ni = i + vec[0];
                    int nj = j + vec[1];

                    if(ni >= 0 && nj >= 0 && nj < n && ni < m && grid[ni][nj] == 1){
                        int adjNode = ni*n + nj;

                        Union(node, adjNode);
                    }
                }
            }
        }

        int boundary_root = find(boundary);

        unordered_set<int> st;

        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int node = i*n +j;

                    int root  = find(node);

                    if(root != boundary_root)
                        st.insert(root);
                }
            }
        }

        int ans = 0;

        for(auto &it : st){
            ans += size[it];
        }

        return ans;  
    }
};