#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

    void Solve(vector<vector<char>>& grid, int i, int j){

        queue<pair<int, int>> q;
        q.emplace(i, j);

        visited[i][j] = true;

        while(!q.empty()){
            auto cell = q.front();
            q.pop();

            int curr_i = cell.first;
            int curr_j = cell.second;

            //nbrs
            for(auto &vec : dir){
                int ni = vec[0] + curr_i;
                int nj = vec[1] + curr_j;

                if(ni >= 0 && nj >= 0 && ni < m && nj < n && !visited[ni][nj] && grid[ni][nj] == 'O'){
                    q.emplace(ni, nj);
                    visited[ni][nj] = true;
                }
            }

        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        visited.assign(m, vector<bool>(n, false));


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !visited[i][j] && (i == 0 || j == 0 || i == m-1 || j == n-1)){
                    Solve(board, i, j);
                }
            }
        }

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X') continue;
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};