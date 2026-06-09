class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int n = board.size(), m = board[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' and (i == n-1 or j == m-1 or i == 0 or j == 0)) q.push({i, j});
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            board[curr.first][curr.second] = 'C';

            for(int i=0; i<4; i++) {
                int newX = curr.first + dx[i];
                int newY = curr.second + dy[i];

                if(newX >= 0 and newX < n and newY >= 0 and newY < m and board[newX][newY] == 'O') {
                    board[newX][newY] = 'C';
                    q.push({newX, newY});
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'C') board[i][j] = 'O';
            }
        }
    }
};
