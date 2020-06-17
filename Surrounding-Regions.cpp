class Solution {
public:
    map<pair<int,int>, int> visited;
    bool ok = false;
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i == 0 or i == board.size()-1 or j == 0 or j == board[0].size() - 1) {
            if(board[i][j] =='O') ok = true;
        }
        else if(i > 0 and i < board.size()-1 and j>0 and j<board[0].size()-1) {
            if(!visited[{i,j}]) {
                if(board[i][j] == 'O') {
                    visited[{i,j}] = 1;
                    dfs(board, i+1, j);
                    dfs(board, i-1, j);
                    dfs(board, i, j+1);
                    dfs(board, i, j-1);
                }
            }
        }
    }
    void fill(vector<vector<char>>& board, int i, int j) {
        if(i > 0 and i < board.size()-1 and j>0 and j<board[0].size()-1) {
            if(board[i][j] == 'O') {
                board[i][j] = 'X';
                fill(board, i+1, j);
                fill(board, i-1, j);
                fill(board, i, j+1);
                fill(board, i, j-1);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j] == 'O') {
                    ok = false;
                    visited.clear();
                    dfs(board, i, j);
                    if(!ok) {
                        fill(board, i, j);
                    }
                }
            }
        }
    }
};
