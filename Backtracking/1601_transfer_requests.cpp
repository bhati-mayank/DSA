#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int result = INT_MIN;

    void Solve(int i, int cnt, vector<vector<int>>& requests,  vector<int>& request){
        if( i >= m){
            bool allzero = true;
            for(int x : request){
                if(x != 0){
                    allzero = false;
                    break;
                }
            }

            if(allzero){
                result = max(result, cnt);
            }

            return ;
        }

        int from = requests[i][0];
        int to = requests[i][1];

        request[from]--;
        request[to]++;

        Solve(i+1, cnt+1, requests, request);

        request[from]++;
        request[to]--;

        Solve(i+1, cnt, requests, request);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m = requests.size();

        vector<int> request(n, 0);

        Solve(0, 0, requests, request);

        return result;    
    }
};