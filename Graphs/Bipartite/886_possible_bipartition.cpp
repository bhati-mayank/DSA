
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkBipartite(unordered_map<int, vector<int>>&graph, vector<int> &color, int i){
        
        queue<int> q;
        q.push(i);

        color[i] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int &x : graph[node]){
                if(color[x] == color[node])
                    return false;

                if(color[x] == -1){
                    q.push(x);
                    color[x] = 1 - color[node];
                }
            }
        }

        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        unordered_map<int, vector<int>> graph;
        vector<int> color(n+1, -1);

        for(vector<int>&vec : dislikes){
            int u = vec[0];
            int v = vec[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i =1; i <= n; i++){
            if(color[i] == -1){
                if(checkBipartite(graph, color, i) == false)
                    return false;
            }
        }

        return true;
    }
};