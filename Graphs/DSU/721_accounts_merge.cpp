#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){

        int p_x = find(x);
        int p_y = find(y);

        if(p_x == p_y)
            return ;

        if(rank[p_x] > rank[p_y])
            parent[p_y] = p_x;

        else if(rank[p_x] < rank[p_y])
            parent[p_x] = p_y;

        else{
            parent[p_y] = p_x;
            rank[p_x]++;
        }
    }


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n  = accounts.size();

        parent.resize(n);

        for(int i = 0; i<n; i++)
            parent[i] = i;

        rank.resize(n, 0);

        unordered_map<string, int> mp;


        for(int i = 0; i <n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end())
                    mp[accounts[i][j]] = i;

                else{
                    Union(mp[accounts[i][j]], i);
                }
            }
        }

        vector<vector<string>> ans;
        vector<vector<string>> merge(n);

        for(auto &it : mp){
            string mail = it.first;
            int node = find(it.second);
            merge[node].push_back(mail);
        }

        for(int i = 0; i < n; i++){
            if(merge[i].size() == 0)
                continue;
            
            sort(merge[i].begin(), merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto &it : merge[i])
                temp.push_back(it);

            ans.push_back(temp);
        }
        return ans;
    }
};