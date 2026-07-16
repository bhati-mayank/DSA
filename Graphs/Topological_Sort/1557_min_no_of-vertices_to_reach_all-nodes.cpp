#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> indegree(n);
        vector<int> result;

        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];

            indegree[v]++;
        }

        for(int i = 0; i < n ;i++){
            if(indegree[i] == 0)
                result.push_back(i);
        }

        return result;
    }
};