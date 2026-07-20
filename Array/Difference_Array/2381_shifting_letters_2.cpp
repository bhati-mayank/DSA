#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.length();

        vector<int> diff(n, 0);

        for(auto &vec : shifts){
            int start = vec[0];
            int end   = vec[1];
            int dir   = vec[2];

            if(dir == 1){
            diff[start] += 1;
            if(end + 1 < n)
                diff[end+1] -= 1;
            }

            else if(dir == 0){
                diff[start] -= 1;
                if(end + 1 < n)
                    diff[end+1] += 1;
            }
        }

        int sum = 0;

        for(int i = 0; i < n ; i++){
            
            sum += diff[i];

            int x = s[i] - 'a';
            x = (x + sum)%26;
            if( x < 0)
                x += 26;

            s[i] = x + 'a';
        }

        return s;
    }
};