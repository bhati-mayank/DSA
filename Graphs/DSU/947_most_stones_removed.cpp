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
    int removeStones(vector<vector<int>>& stones) {
        

        int n = stones.size();

        parent.resize(n);
        for(int i = 0; i<n ; i++)
            parent[i] = i;

        rank.resize(n, 0);

        int comp = 0;

        for(int i = 0; i < n ;i++){
            for(int j = i; j< n; j++){
                if(stones[i][0] == stones[j][0]
                    || stones[i][1] == stones[j][1]){
                        Union(i, j);
                    }
            }
        }

        for(int i = 0; i < n; i++){
            if(i == find(i))
                comp++;
        }

        return n - comp;
    }
};