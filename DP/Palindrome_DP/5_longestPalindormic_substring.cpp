#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //length of string
        int n = s.length();

        //dp table
        bool t[n][n];

        //initialising the dp table
        memset(t, false, sizeof(t));

        string ans ="";
        int maxLen = INT_MIN;

        //computing the substrings
        for(int L = 1; L <= n; L++){
            for(int i = 0; i+L-1 < n; i++){
                int j = i+L-1;

                if(i == j)
                    t[i][j] = true;
                else if(i+1 == j)
                    t[i][j] = (s[i] == s[j]);
                else
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                
                if(t[i][j]){
                    //if the particular sustring is palindrome
                    //check its length with the previous max
                    if(L > maxLen){
                        maxLen = L;
                        //and replac e the answer with that substring
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }

        return ans;

    }
};