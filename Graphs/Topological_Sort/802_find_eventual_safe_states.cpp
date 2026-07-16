
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<int>>& graph, int u, vector<bool>& visited, vector<bool>& currPath){
        currPath[u] = true;
        visited[u]  = true;

        for(auto &v : graph[u]){
            if(!visited[v]){
                if(dfs(graph, v, visited, currPath))
                    return true;
            }else{
                if(currPath[v])
                    return true;
            }
        }

        currPath[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();

        vector<bool> currPath(V);
        vector<bool> visited(V, false);

        for(int i = 0; i < V; i++){
            if(!visited[i])
                dfs(graph, i, visited, currPath);
        }

        vector<int> safeNodes;


        for(int i = 0; i < V; i++){
            if(currPath[i] == false){
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};