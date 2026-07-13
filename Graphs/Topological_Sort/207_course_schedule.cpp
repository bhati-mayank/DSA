#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> mp;
        vector<int> indegrees(numCourses, 0);
        int n = 0;

        for(auto &vec : prerequisites){
            int u = vec[0];
            int v = vec[1];

            mp[v].push_back(u);
            indegrees[u]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegrees[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int curr_node = q.front();

            q.pop();
            n++;

            for(auto &nbrs : mp[curr_node]){
                indegrees[nbrs]--;
                if(indegrees[nbrs] == 0){
                    q.push(nbrs);
                }

            }
        }

        return n == numCourses;
    }
};