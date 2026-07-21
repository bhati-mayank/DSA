#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int r, c;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int perimeter = 0;

    void bfs(int i, int j, vector<vector<int>>& visited,
             vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        q.emplace(i, j);
        visited[i][j] = 1;

        while (!q.empty()) {
            pair<int, int> f = q.front();
            q.pop();

            int no_of_nbr = 0;

            for (int a = 0; a < 4; a++) {
                int ii = f.first + dx[a];
                int jj = f.second + dy[a];

                if (ii < 0 || jj < 0 || ii >= r || jj >= c ||
                    grid[ii][jj] == 0) {
                    continue;
                } else {
                    no_of_nbr++;
                    if (!visited[ii][jj]) {
                        q.emplace(ii, jj);
                        visited[ii][jj] = 1;
                    }
                }
            }

            if (no_of_nbr == 1) {
                perimeter += 3;
            } else if (no_of_nbr == 2) {
                perimeter += 2;
            } else if (no_of_nbr == 3) {
                perimeter += 1;
            } else if (no_of_nbr == 4) {
                perimeter += 0;
            } else if (no_of_nbr == 0)
                perimeter += 4;
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        vector<vector<int>> visited(r, vector<int>(c));
        int i, j;

        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    break;
                }
            }

            if(grid[i][j] ==1)
                break;
        }

        bfs(i, j, visited, grid);

        return perimeter;

    }
};