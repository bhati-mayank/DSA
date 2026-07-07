#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n; 
    int t[21][10003];
    int Solve(int i, int diff, vector<int>& rods){

        //if we have consider all rods
        if( i == n ){
            if(diff == 0)
                return 0;

            return INT_MIN;
        }

        if(t[i][diff + 5000] != -1)
            return t[i][diff + 5000];


        //take the curr rod and add to left support
        int left = rods[i] + Solve(i+1,diff + rods[i], rods);

        //take the curr rod and add to right support
        int right = rods[i] + Solve(i+1, diff - rods[i], rods);

        //skip the rod
        int skip = Solve(i+1, diff, rods);


        return t[i][diff + 5000] = max({left, right, skip});


    }
    int tallestBillboard(vector<int>& rods) {

        n = rods.size();

        memset(t, -1, sizeof(t));

        return Solve(0, 0, rods)/2;
    }
};