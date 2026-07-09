#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {

        int num = 0;
        int sum = 0;

        for(char &ch : to_string(n)){
            if(ch != '0'){
                num = num*10 + (ch -'0');
                sum += (ch-'0');
            }
        }
        return (long long)sum*num;
        
    }
};