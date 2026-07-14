
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n,N;
    int t[101][101][201];
    int Solve(int i, int j, int k, string& s1, string& s2, string& s3){

        if( i == m && j == n && k == N)
            return true;

        if(k >= N)
            return false;
        if( t[i][j][k] != -1 )
            return t[i][j][k];

        bool result = false;

        if(s1[i] == s3[k])
            result = Solve(i+1, j, k+1, s1, s2, s3);

        if(result)
            return true;

        if(s2[j] == s3[k])
            result = Solve(i, j+1, k+1, s1, s2, s3);

        return t[i][j][k] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        m = s1.size();
        n = s2.size();
        N = s3.size();

        memset(t, -1, sizeof(t));

        return Solve(0,0,0,s1,s2,s3);
        
    }
};