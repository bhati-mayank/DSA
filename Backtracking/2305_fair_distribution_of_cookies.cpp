#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int result = INT_MAX;

    void Solve(vector<int>& cookies, int i, int k, vector<int>& children){
        if(i >= n){
            int unfair = *max_element(begin(children), end(children));
            result = min(result, unfair);
            return;
        }

        int cookie = cookies[i];

        for(int j = 0; j < k; j++){
            children[j] += cookie;
            Solve(cookies, i+1, k, children);
            children[j] -= cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> children(n, 0);

        Solve(cookies, 0, k, children);

        return result;
    }
};