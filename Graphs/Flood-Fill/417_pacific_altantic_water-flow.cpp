#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

    void bfs(queue<pair<int,int>> &q,
             vector<vector<bool>> &visited,
             vector<vector<int>> &heights) {

        while (!q.empty()) {
        auto cell = q.front();
        int i = cell.first;
        int j = cell.second;
            q.pop();

            for (auto &d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni >= 0 && nj >= 0 &&
                    ni < m && nj < n &&
                    !visited[ni][nj] &&
                    heights[ni][nj] >= heights[i][j]) {

                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int,int>> pacificQ;
        queue<pair<int,int>> atlanticQ;

        // Left & Right borders
        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            pacificQ.push({i,0});

            atlantic[i][n-1] = true;
            atlanticQ.push({i,n-1});
        }

        // Top & Bottom borders
        for (int j = 0; j < n; j++) {
            if (!pacific[0][j]) {
                pacific[0][j] = true;
                pacificQ.push({0,j});
            }

            if (!atlantic[m-1][j]) {
                atlantic[m-1][j] = true;
                atlanticQ.push({m-1,j});
            }
        }

        bfs(pacificQ, pacific, heights);
        bfs(atlanticQ, atlantic, heights);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};