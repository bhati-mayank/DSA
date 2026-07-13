#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int>indegree(numCourses);

        //graph
        for(int i = 0; i < prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int pre    = prerequisites[i][1];

            graph[pre].push_back(course);
            indegree[course]++;
        }


        queue<int> q;

        vector<int>result;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            result.push_back(node);

            for(int nbr : graph[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        if(result.size() != numCourses)
            return {};

        else return result;
    }
};