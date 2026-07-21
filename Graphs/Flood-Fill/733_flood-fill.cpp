#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int r,c;

    void dfs(int i, int j, int color, int org_color, vector<vector<int>> &image){
        if(i <0 || j <  0 || j>=c || i >= r || image[i][j] != org_color){
            return;
        }

        image[i][j] = color;

        dfs(i-1, j, color, org_color, image);
        dfs(i+1, j, color, org_color, image);
        dfs(i, j-1, color, org_color, image);
        dfs(i, j+1, color, org_color, image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        r = image.size();
        c = image[0].size();

        int org_color = image[sr][sc];

        if(color == org_color) return image;


        dfs(sr, sc, color, org_color, image);
        return image;
    }
};