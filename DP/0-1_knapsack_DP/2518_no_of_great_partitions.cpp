#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    vector<vector<int>> t;

    int Solve(vector<int>& nums, int i, int sum, int k) {

        // Once sum reaches k, we don't care anymore.
        if (sum >= k)
            return 0;

        if (i == n)
            return 1;   // This subset has sum < k

        if (t[i][sum] != -1)
            return t[i][sum];

        long long take = Solve(nums, i + 1, sum + nums[i], k);
        long long skip = Solve(nums, i + 1, sum, k);

        return t[i][sum] = (take + skip) % MOD;
    }

    int countPartitions(vector<int>& nums, int k) {

        long long totalSum = 0;
        for (int x : nums)
            totalSum += x;

        if (totalSum < 2LL * k)
            return 0;

        n = nums.size();

        t.assign(n, vector<int>(k, -1));

        long long bad = Solve(nums, 0, 0, k);

        long long total = 1;
        for (int i = 0; i < n; i++)
            total = (total * 2) % MOD;

        long long ans = (total - (2 * bad) % MOD + MOD) % MOD;

        return ans;
    }
};