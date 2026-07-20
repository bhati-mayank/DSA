#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";

        for(char &ch : s){
            if(isalnum(ch)){
                t.push_back(tolower(ch));
            }
        }


        int i = 0;
        int j = t.size() -1;

        while(i <= j){
            if(t[i] != t[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};