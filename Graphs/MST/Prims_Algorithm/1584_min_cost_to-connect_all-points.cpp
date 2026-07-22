
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<int, int> P;
    int Prims_algo(vector<vector<pair<int, int>>>&graph, int V){

        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, 0});

        vector<bool> inMst(V, false);

        int sum = 0;

        while(!q.empty()){
            auto p = q.top();
            q.pop();

            int wt = p.first;
            int node = p.second;

            if(inMst[node] == true)
                continue;

            sum += wt;
            inMst[node] = true;

            for(auto &nbr : graph[node]){
                int n = nbr.first;
                int d = nbr.second;

                if(inMst[n] == false){
                    q.push({d, n});
                }
            }
        }

        return sum;


    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> graph(points.size());
        int V = points.size();

        for(int i = 0; i < V; i++){
            for(int j = i+1; j < V; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);

                graph[i].push_back({j, dist});
                graph[j].push_back({i, dist});
            }
        }

        return Prims_algo(graph, V);
    }
};