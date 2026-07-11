#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    vector<vector<int>> t;
    int Solve(vector<vector<int>>& triangle, int i, int j)
    {
        if(i == m -1)
            return triangle[i][j];
        if(i >= m)
            return INT_MAX;

        if(t[i][j] != INT_MAX)
            return t[i][j];


        int one = Solve(triangle, i+1, j);
        int two = Solve(triangle, i+1, j+1);

        if(one != INT_MAX)
            one += triangle[i][j];

        if(two != INT_MAX)
            two += triangle[i][j];

        return t[i][j] = min(one, two);


        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        m = triangle.size();

        t.resize(201, vector<int>(201, INT_MAX));
        

        return Solve(triangle, 0,0);  
    }
};