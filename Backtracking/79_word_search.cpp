
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    bool Solve(vector<vector<char>>& board, string &word, int i, int j, int indx){

        if(indx == word.size())
            return true;
        
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$')
            return false;

        if(board[i][j] != word[indx])
            return false;

        char temp = board[i][j];

        board[i][j] = '$';

        for(auto &vec : dir){
            int ni = i + vec[0];
            int nj = j + vec[1];

            if(Solve(board, word, ni,  nj, indx+1))
                return true;
        }

        board[i][j] = temp;

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(Solve(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};