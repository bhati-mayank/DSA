
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int small = *min_element(begin(nums), end(nums));
        int large = *max_element(begin(nums), end(nums));

        return __gcd(small, large);
    }
};
