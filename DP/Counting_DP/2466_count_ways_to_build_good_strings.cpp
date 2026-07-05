#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int t[100001];
    int M = 1e9 + 7;
    int Solve(int low, int high, int zero, int one, int len){
        if(len > high)
            return 0;

        if(t[len] != -1)
            return t[len];
        
        int addOne = 0;
        if(len >= low && len <= high)
            addOne = 1;

        int append_one  = Solve(low, high, zero, one, len + one);
        int append_zero = Solve(low, high, zero, one, len + zero);

        return t[len] = (addOne + append_one + append_zero)%M;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {

        memset(t, -1, sizeof(t));

        return Solve(low, high, zero, one, 0);
    }
};