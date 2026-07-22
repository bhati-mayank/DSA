#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    typedef long long ll;
    typedef pair<ll, ll> P;

    void dijkstra(unordered_map<ll, vector<pair<ll, ll>>>& graph, vector<ll>& ans, ll src){

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});

        ans[src] = 0;


        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            ll curr_dist = p.first;
            ll curr_node = p.second;

            //nbrs
            for(auto &nbr : graph[curr_node]){
                ll v  = nbr.first;
                ll wt = nbr.second;

                if(curr_dist + wt < ans[v]){
                    ans[v] = curr_dist + wt;
                    pq.push({curr_dist+wt, v});
                }
            }
        }
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {


        int m = edges.size();

        // graph
        unordered_map<ll, vector<pair<ll, ll>>> mp;

        for(auto &edge : edges){
            ll  u  = edge[0];
            ll  v  = edge[1];
            ll  wt = edge[2];

            mp[u].push_back({v, wt});
            mp[v].push_back({u, wt});
        }

        vector<ll> src_all(n, INT_MAX);
        vector<ll> dest_all(n, INT_MAX);
        vector<bool> result;

        dijkstra(mp, src_all, 0);
        dijkstra(mp, dest_all, n-1);

        ll min_dst = src_all[n-1];

       for(auto &edge :  edges){
            ll u      = edge[0];
            ll v      = edge[1];
            ll wt = edge[2];

            if( src_all[u] + dest_all[v] + wt == min_dst)
                result.push_back(true);

            else if( src_all[v] + dest_all[u] + wt == min_dst)
                result.push_back(true);

            else 
                result.push_back(false);

       } 

       return result;
    }
};