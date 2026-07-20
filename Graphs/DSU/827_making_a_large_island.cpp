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

        if(p_x == p_y) return;

        if(size[p_y] < size[p_x]){
            parent[p_y] = p_x;
            size[p_x] += size[p_y];
        }

        else if(size[p_y] > size[p_x]){
            parent[p_x] = p_y;
            size[p_y] += size[p_x];
        }

        else{
            parent[p_x] = p_y;
            size[p_y] += size[p_x];           
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        parent.resize(m*n);
        size.resize(m*n, 1);

        for(int i = 0; i < m*n; i++)    
            parent[i] = i;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;

                int node = i*n+j;

                for(auto &vec : dir){
                    int ni = i + vec[0];
                    int nj = j + vec[1];

                    if( ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 1){
                        int adjNode = ni*n+nj;
                        Union(node, adjNode);
                    }
                }
            }
        }


        bool flag = false;
        int maxSize = INT_MIN;

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) continue;

                unordered_set<int> st;

                flag = true;

                for( auto &vec : dir){
                    int ni = i + vec[0];
                    int nj = j + vec[1];

                    if(ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 1)
                    {
                        int node = ni*n + nj;

                        int root = find(node);

                        st.insert(root);
                    }
                }

                int ans = 1;

                for(auto &it : st){
                    ans += size[it];
                }

                maxSize = max(maxSize, ans);
            }
        }
        if(!flag)
            return m*n;

        return maxSize;
    }
};