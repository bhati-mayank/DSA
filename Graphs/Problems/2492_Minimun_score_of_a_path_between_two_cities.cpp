#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> graph;

        for(vector<int> &vec : roads){
            int u = vec[0];
            int v = vec[1];
            int d = vec[2];

            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }

        vector<bool> visited(n+1, false);

        int result = INT_MAX;

        queue<int> q;
        q.push(1);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &nbr : graph[u]){
                int v = nbr.first;
                int d = nbr.second;

                result = min(result, d);

                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        return result;
    }
};