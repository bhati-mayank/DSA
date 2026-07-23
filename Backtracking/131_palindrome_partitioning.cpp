#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Solve(string &s, int i, vector<string> &curr, vector<vector<string>> &result, vector<vector<bool>> &t){

        if(i == s.length()){
            result.push_back(curr);
            return;
        }

        for(int j = i; j < s.length(); j++){
            if(t[i][j]){
                curr.push_back(s.substr(i, j-i+1));
                Solve(s, j+1, curr, result, t);
                curr.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        int n = s.length();

        vector<vector<bool>> t(n, vector<bool>(n, false));

        for(int L = 1; L <= n; L++){
            for(int i = 0; i +L-1<n; i++){
                int j = i + L - 1;

                if(i == j) t[i][j] = true;
                else if(i + 1 == j) t[i][j] = (s[i] == s[j]);
                else t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
            }
        }

        vector<vector<string>> result;
        vector<string> curr;
        Solve(s, 0, curr, result, t);

        return result;
    }
};