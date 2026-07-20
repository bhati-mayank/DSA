#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.length();

        bool t[n][n];

        memset(t, false, sizeof(t));

        for(int L = 1; L <= n; L++){
            for(int i = 0; i+L-1 < n; i++){
                int j = i +L-1;

                if(i == j)
                    t[i][j] = true;
                else if(i+1 == j)
                    t[i][j] = (s[i] == s[j]);
                else t[i][j] = (s[i] == s[j] && t[i+1][j-1]);

                if(t[i][j]){
                    cnt++;
                }
            }
        }

        return cnt;

    }
};