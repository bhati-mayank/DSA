#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> mp;
    int N;
    Graph(int n, vector<vector<int>>& edges) {

        N = n;
        
        for(auto &vec : edges){
            
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];

            mp[u].push_back({v, cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        mp[u].push_back({v, cost});
    }
    
    int shortestPath(int node1, int node2) {
        
        vector<int> dist(N, INT_MAX);
        dist[node1] = 0;

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>> > pq;
        pq.push({0, node1});

        while(!pq.empty()){

            int curr_dist = pq.top().first;
            int curr_node = pq.top().second;

            pq.pop();

            //nbrs
            for(auto &nbr : mp[curr_node]){

                int distance = nbr.second;
                int node = nbr.first;

                if(distance + curr_dist < dist[node]){
                    dist[node] = distance + curr_dist;
                    pq.push({distance + curr_dist, node});
                }
            }
        }

        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};