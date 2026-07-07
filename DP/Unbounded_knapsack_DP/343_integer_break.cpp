#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[59];
    int Solve(int n){
        if(n == 0)
            return 0;

        if(t[n] != -1)
            return t[n];

        int ans = INT_MIN;

        for(int i = 1; i <= n-1; i++){
            int prod = i*max(n-i, Solve(n-i));

            ans = max(ans, prod);
        }

        return t[n] = ans;
    }
    int integerBreak(int n) {
        
        memset(t, -1, sizeof(t));
        return Solve(n);
    }
};