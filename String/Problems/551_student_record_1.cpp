#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool checkRecord(string s) {
        
        int abt = 0;

        int n = s.size();

        for(char &ch : s){
            if(ch == 'A')
                abt++;
        }

        if(abt > 1)
            return false;

        for(int i = 1; i <= n-2; i++){
            if(s[i] == 'L' && s[i-1] == 'L' && s[i+1] == 'L')
                return false;
        }

        return true;
    }
};