#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9 +7;
    int t[100001][2][3];
    int Solve(int n, int total_abs, int consec_late){

        if(total_abs > 1 || consec_late > 2)
            return 0;
            
        if(n == 0)
            return 1;
        


        if(t[n][total_abs][consec_late] != -1)
            return t[n][total_abs][consec_late];

        int A = Solve(n-1, total_abs+1, 0)%M;
        int L = Solve(n-1, total_abs, consec_late+1)%M;
        int P = Solve(n-1, total_abs, 0)%M;

        return t[n][total_abs][consec_late] = ((long long)A%M + L%M + P%M)%M;
    }
    int checkRecord(int n) {

        memset(t , -1, sizeof(t));
        
        return Solve(n, 0, 0);
    }
};