#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[101][101][601];
    int Solve(vector<pair<int, int>>& count, int m , int n, int i){
        if(i >= count.size() || (m == 0 && n == 0))
            return 0;

        if(t[m][n][i] != -1)
            return t[m][n][i];

        //take
        int take = 0;
        if(count[i].first <= m && count[i].second <= n){
            take = 1 + Solve(count, m - count[i].first, n - count[i].second, i+1);
        }

        int skip = Solve(count, m, n, i+1);

        return t[m][n][i] = max(take, skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        

        vector<pair<int, int>> count(strs.size());


        for(int i = 0; i < strs.size(); i++){
            int count_zero = 0;
            int count_one = 0;

            for(char &ch : strs[i]){
                if(ch == '0')
                    count_zero++;

                else 
                    count_one++;
            }

            count[i] = {count_zero, count_one};
        }

        memset(t , -1, sizeof(t));


        return Solve(count, m, n, 0);
    }
};