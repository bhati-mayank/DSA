
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int u, vector<int> & color){

        visited[u] = true;
        for(int &v : graph[u]){
            if(!visited[v]){
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    if(!dfs(graph, visited, v ,color)){
                        return false;
                    }
                }
            }
            else if(color[v] == color[u])
            return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int>color(n, -1);
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                color[i] = 0;
                if(!dfs(graph, visited, i, color)){
                    return false;
                }
            }
        }
        return true;
    }
};