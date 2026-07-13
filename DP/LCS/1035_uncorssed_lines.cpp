#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    int t[501][501];
    int Solve(vector<int>& nums1, vector<int>& nums2, int i, int j){

        if(i >= m || j >= n)
            return 0;

        if(t[i][j] != -1) return t[i][j];

        if(nums1[i] == nums2[j])
            return t[i][j] = 1 + Solve(nums1, nums2, i+1, j+1);

        else
            return t[i][j] = max(Solve(nums1, nums2, i+1, j), Solve(nums1, nums2, i, j+1));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        

        m = nums1.size();
        n = nums2.size();

        memset(t, -1, sizeof(t));

        return Solve(nums1, nums2, 0, 0);
    }
};