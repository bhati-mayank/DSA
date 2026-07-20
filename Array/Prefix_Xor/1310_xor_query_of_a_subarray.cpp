#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int n = arr.size();
        
        vector<int> prefix_xor(n);
        prefix_xor[0] = arr[0];

        for(int i = 1;i < arr.size(); i++){
            prefix_xor[i] = prefix_xor[i-1]^arr[i];
        }

        vector<int> result;

        for(auto &vec : queries){
            int l = vec[0];
            int r = vec[1];

            int xor_val = prefix_xor[r]^ ((l == 0) ? 0 : prefix_xor[l-1]);

            result.push_back(xor_val);
        }

        return result;
    }
};