#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find( int x ){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){

        int p_x = find(x);
        int p_y = find(y);


        if(p_x == p_y) return ;

        if(rank[p_x] > rank[p_y]){
            parent[p_y] = p_x;
        }
        else if(rank[p_x] < rank[p_y]){
            parent[p_x] = p_y;
        }

        else{
            parent[p_x] = p_y;
            rank[p_y]++;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        parent.resize(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        rank.resize(n, 0);
        
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            Union(u, v);
        }

        return find(source) == find(destination);
    }
};