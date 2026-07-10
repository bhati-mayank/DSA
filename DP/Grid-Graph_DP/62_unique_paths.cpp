#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[101][101];
    int Solve(int i, int j, int m, int n){
        if(i >= m || j >= n )
            return 0;

        if(i == m-1 && j == n-1)
            return 1;

        if(t[i][j] != -1)
            return t[i][j];

        return  t[i][j] = Solve(i, j+1, m, n) + Solve(i+1, j,m, n);
    }
    int uniquePaths(int m, int n) {
        
        memset(t, -1, sizeof(t));
        return Solve(0, 0, m, n);
    }
};