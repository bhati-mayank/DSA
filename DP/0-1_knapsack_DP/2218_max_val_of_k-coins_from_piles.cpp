#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int t[1001][2001];
    int Solve(vector<vector<int>>& piles, int k, int i){
        if( i >= n)
            return 0;

        if(t[i][k] != -1) return t[i][k];

        int skip = Solve(piles, k, i+1);

        int take = 0;
        int sum = 0;
        for(int j = 0; j < min((int)piles[i].size(), k); j++){
            sum += piles[i][j];

            take = max(take, sum + Solve(piles, k-j-1, i+1));
        }


        return t[i][k] = max(take, skip);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();

        memset(t, -1, sizeof(t));

        return Solve(piles, k, 0);
    }
};