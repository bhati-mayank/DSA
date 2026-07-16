#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n = recipes.size();

        unordered_set<string> st(begin(supplies), end(supplies));

        unordered_map<string, vector<int>> mp;

        vector<int>indegree(n,0);

        for(int i = 0; i < n ; i++){
            for(string &ing : ingredients[i]){
                if(!st.count(ing)){
                    mp[ing].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> q;
        vector<string> result;

        for(int i =0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int i = q.front();
            q.pop();

            string recipe = recipes[i];

            result.push_back(recipe);

            for(int &idx : mp[recipe]){
                indegree[idx]--;
                if(indegree[idx] == 0)
                    q.push(idx);
            }
        }

        return result;
    }
};