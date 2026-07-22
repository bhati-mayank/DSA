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

            if(curr_dist > ans[curr_node])
                continue;
                

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
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        
        //graph
        unordered_map<ll, vector<P>> graph;

        for(auto & edge : edges){
            ll u  = edge[0];
            ll v  = edge[1];
            ll wt = edge[2];

            graph[u].push_back({v, wt});
        }

        unordered_map<ll, vector<P>> reverse_graph;

        for(auto & edge : edges){
            ll u  = edge[0];
            ll v  = edge[1];
            ll wt = edge[2];

            reverse_graph[v].push_back({u, wt});
        }

        vector<ll> src_1(n,  LLONG_MAX);
        vector<ll> src_2(n,  LLONG_MAX);
        vector<ll> dst(n,  LLONG_MAX);

        dijkstra(graph, src_1, src1);
        dijkstra(graph, src_2, src2);
        dijkstra(reverse_graph, dst  , dest);

        ll ans = 1e18;

        for(int i = 0; i < n; i++){

            if(src_1[i] == LLONG_MAX || src_2[i] == LLONG_MAX || dst[i] == LLONG_MAX) continue;
            ans = min(ans, (src_1[i] + src_2[i]) +dst[i]);
        }

        return (ans == 1e18) ? -1 : ans;
    }
};