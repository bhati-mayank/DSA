
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    int cnt;
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    int Solve(vector<vector<int>>& grid, int i, int j, int obs){
    
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1 || grid[i][j] == -2)
            return 0;

        
        if(grid[i][j] == 2){

            if(cnt == obs)
                return 1;

            return 0;
        }

        int ans = 0;
        int temp = grid[i][j];
        grid[i][j] = -2;
        for(auto &vec : dir){
            int ni = i + vec[0];
            int nj = j + vec[1];
            ans += Solve(grid, ni,nj, obs+1);
        }

        grid[i][j] = temp;

        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        cnt = 0;

        int x,y;


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }

                if(grid[i][j] == 0)
                    cnt++;
            }
        }
        cnt++;
        return Solve(grid, x, y, 0);
        
    }
};