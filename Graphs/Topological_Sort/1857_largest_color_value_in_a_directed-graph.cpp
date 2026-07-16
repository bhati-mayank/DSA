#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size();

        vector<vector<int>> t(N, vector<int>(26, 0));

        vector<int> indegree(N, 0);

        queue<int> q;

        unordered_map<int, vector<int>> mp;

        for(auto vec : edges){

            int u = vec[0];
            int v = vec[1];

            mp[u].push_back(v);

            indegree[v]++;


        }


        for(int i = 0; i < N; i++){
            if(indegree[i] == 0){
                q.push(i);
                t[i][colors[i]  - 'a'] = 1;
            }
        }       

        int ans = INT_MIN;
        
        int process = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            process++;

            ans = max(ans, t[u][colors[u] - 'a']);

            for(int &v : mp[u]){

                for(int c= 0; c < 26; c++){

                    t[v][c] = max(t[v][c], t[u][c] + ((colors[v] - 'a') == c ));
                }

                indegree[v]--;

                if(indegree[v] == 0)
                    q.push(v);
            }

        }

        if(process != N)
            return -1;
        return ans;
    }
};