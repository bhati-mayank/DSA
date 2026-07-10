#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){

        int p_x = find(x);
        int p_y = find(y);

        if(p_x == p_y) return;

        if(rank[p_x] < rank[p_y]){
            parent[p_x] = p_y;
        }

        else if(rank[p_x] > rank[p_y]){
            parent[p_y] = p_x;

        }

        else{
            parent[p_x] = p_y;
            rank[p_y]++;
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        parent.resize(n, 0);
        rank.resize(n, 0);

        vector<bool> result;

        for(int i = 0; i < n; i++)
            parent[i] = i;
        

        for(int i = 0; i < nums.size()-1; i++){
            if(abs(nums[i] - nums[i+1]) <= maxDiff)
                Union(i, i+1);

        }

        for(auto &vec : queries){
            int u = vec[0];
            int v = vec[1];

            if(parent[u] == parent[v])
                result.push_back(true);

            else result.push_back(false);
        }

        return result;
    }
};