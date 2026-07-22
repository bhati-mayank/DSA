
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        

        //create the graph
        unordered_map<int, vector<P>> mp;

        for(auto &vec : times){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];

            mp[u].push_back({v, wt});
        }

        //create a min heap
        priority_queue<P, vector<P>, greater<P>> pq;

        //result array
        vector<int> result(n+1, INT_MAX);

        //result of src node is zero as it takes 0 dist from src to src
        result[k] = 0;

        //push the src node and its dist to pq
        pq.push({0, k});

        //dijkstra
        while(!pq.empty()){
            auto p = pq.top();
            int dist = p.first;
            int curr_node = p.second;
            pq.pop();

            //nbr of curr node
            for(auto &nbr : mp[curr_node]){
                int v = nbr.first;
                int wt = nbr.second;


                //update result if neccesary
                if(dist + wt < result[v]){
                    result[v] = dist+wt;

                    pq.push({dist+wt, v});
                }
            }
        }

        int ans = INT_MIN;

        for(int i = 1; i <= n ; i++){
            ans = max(result[i], ans);
        }

        if(ans == INT_MAX)
            return -1;
        return ans;
        
    }
};