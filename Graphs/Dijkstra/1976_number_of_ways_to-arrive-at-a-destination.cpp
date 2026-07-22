#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        

        //make graph
        unordered_map<int, vector<pair<int, int>>> mp;

        for(auto &vec : roads){
            int u = vec[0];
            int v = vec[1];
            int time = vec[2];

            mp[u].push_back({v, time});
            mp[v].push_back({u, time});
        }

        // min heap
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,  greater<pair<long long, int>>> pq;

        //from src to src
        pq.push({0, 0});

        //result array
        vector<long long> result(n , LLONG_MAX);

        result[0] = 0;

        //array to the the no of way to reach an node 
        vector<long long> ways(n);
        ways[0] = 1;

        //dijkstra
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            long long curr_time = p.first;
            int curr_node = p.second;

            for(auto &nbr : mp[curr_node]){
                auto p = nbr;

                int node = p.first;
                long long time = p.second;

                if(curr_time + time < result[node]){
                    ways[node] = ways[curr_node]; 
                    result[node] = curr_time + time;
                    pq.push({curr_time + time, node});
                }
                else if(curr_time + time == result[node]){
                    ways[node] = (ways[node] + ways[curr_node])%M;
                }
            }
        }

        return ways[n-1];

    }
};