#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[10001];
    int Solve(int n){
        if(n == 0)
            return 0;

        if(t[n] != -1)
            return t[n];

        int ans = INT_MAX; 
        for(int i = 1; i*i <= n; i++){
            int result = 1 + Solve(n - i*i);

            ans = min(ans, result);
        }

        return t[n] = ans;
    }
    int numSquares(int n) {

        memset(t, -1, sizeof(t));
        
        return Solve(n);
    }
};