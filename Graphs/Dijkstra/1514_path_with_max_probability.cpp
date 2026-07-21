

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        unordered_map<int, vector<pair<int, double>>> graph;

        vector<double> result(n);


        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            graph[u].push_back({v , prob});
            graph[v].push_back({u , prob});
        }

        priority_queue<pair<double, int>> pq;

        pq.push({1.0, start_node});

        result[start_node   ] = 1.0;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            double prob = p.first;
            int u = p.second;

            for(auto &temp : graph[u]){
                int node = temp.first;
                double tempprob = temp.second;

                if(result[node] < prob*tempprob){
                    result[node] = prob*tempprob;
                    pq.push({result[node], node});
                }
            }

        }

        return result[end_node];
    }
};