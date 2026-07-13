#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> topo(vector<vector<int>>& edges, int n){

        // degree array
        vector<int> degree(n+1, 0);

        vector<int> result;

        //map
        unordered_map<int, vector<int>> mp;

        for(auto &vec : edges){

            int u = vec[0];
            int v = vec[1];

            mp[u].push_back(v);
            degree[v]++;
        }


        queue<int> q;

        for(int i = 1; i <= n; i++){
            if(degree[i] == 0)
                q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            
            int node = q.front();
            result.push_back(node);
            cnt++;
            q.pop();

            for(auto &nbr : mp[node]){
                degree[nbr]--;
                if(degree[nbr] == 0)
                    q.push(nbr);
            }
        }

        if(cnt != n)
            return {};

        return result;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>> matrix(k, vector<int>(k, 0));

        vector<int> topoRow = topo(rowConditions, k);
        vector<int> topoCol = topo(colConditions, k);

        if(topoRow.empty() || topoCol.empty())
            return {};

        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){

                if(topoRow[i] == topoCol[j])
                    matrix[i][j] = topoRow[i];
            }
        }

        return matrix;
    }
};