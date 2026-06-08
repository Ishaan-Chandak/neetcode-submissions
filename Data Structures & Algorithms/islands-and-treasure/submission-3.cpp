class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) q.push({i, j}); 
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;

            for(int i=0; i<4; i++) {
                int newX = row + dx[i];
                int newY = col + dy[i];

                if(newX < 0 or newX >= n or newY < 0 or newY >= m or grid[newX][newY] != INT_MAX) continue;

                grid[newX][newY] = grid[row][col] + 1;
                q.push({newX, newY});
            }
        }   
    }
};
