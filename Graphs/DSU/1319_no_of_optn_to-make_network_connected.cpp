
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

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

        return true;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {


        parent.resize(n);

        for(int i = 0; i <n; i++)
            parent[i] = i;

        rank.resize(n, 0);
        
        int edges = connections.size();

        int components = n;


        for(auto &vec : connections){

            int u = vec[0];
            int v = vec[1];

            if(Union(u, v)){
                components--;
            }
        }

        if(edges < n-1)
            return -1;

        return components-1;
    }
};