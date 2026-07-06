
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int N;
    unordered_set<int> st;
    unordered_map<int, unordered_map<int, int>> t;

    bool Solve(int post, int last_jump){

        if(post == N)
            return true;

        if(post > N)
            return false;

        if(st.find(post) == st.end())
            return false;

        if(t.count(post) && t[post].count(last_jump))
            return t[post][last_jump];

        bool jump_1 = false;
        if(last_jump > 1)
            jump_1 = Solve(post + last_jump - 1, last_jump - 1);

        bool jump_2 = Solve(post + last_jump + 1, last_jump + 1);

        bool jump_3 = Solve(post + last_jump, last_jump);

        return t[post][last_jump] = (jump_1 || jump_2 || jump_3);
    }

    bool canCross(vector<int>& stones) {

        if(stones[1] != 1)
            return false;

        N = stones.back();

        for(int stone : stones)
            st.insert(stone);

        return Solve(1, 1);
    }
};