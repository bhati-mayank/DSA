
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int Find(int x){
        if(parent[x] == x)
            return x ;

        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y){

        int p_x = Find(x);
        int p_y = Find(y);

        if(p_x == p_y)
            return;

        if(rank[p_x] < rank[p_y])
            parent[p_x] = p_y;


        else if(rank[p_x] > rank[p_y])
            parent[p_y] = p_x;
        
        else{
            parent[p_x] = p_y;
            rank[p_y]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n+1);

        for(int i = 1; i <= n; i++)
            parent[i] = i;

        rank.resize(n+1, 0);

        for(auto vec : edges){
            int u = vec[0];
            int v = vec[1];

           if(Find(u) == Find(v))
                return {u, v};

            Union(u, v);
        }
        return {};       
    }
};