#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int t[101];
    int Solve(string &s, int i){
        if(s[i] == '0')
            return 0;

        if(i == n)
            return 1;

        if(t[i] != -1)
            return t[i];

        int result = Solve(s, i+1);

        if(i+1 < n){
            if(s[i] =='1' || (s[i] == '2' && s[i+1] <= '6'))
                result += Solve(s,i+2);
        }

        return t[i] = result;
    }
    int numDecodings(string s) {
        n = s.size();

        memset(t, -1, sizeof(t));

        return Solve(s, 0);
    }
};