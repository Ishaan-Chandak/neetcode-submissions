class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int cnt = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) q.push({{i, j}, 0});
            }
        }

        int ans = INT_MIN;
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

           
            grid[curr.first.first][curr.first.second] = 2;

            if(visited[curr.first.first][curr.first.second] != 1) {
                ans = max(ans, curr.second);
            }

            visited[curr.first.first][curr.first.second] = 1;

        
            for(int i=0; i<4; i++) {
                int newX = curr.first.first + dx[i];
                int newY = curr.first.second + dy[i];
                if(newX >= 0 and newX < n and newY >= 0 and newY < m and visited[newX][newY] == 0 and grid[newX][newY] == 1) {
                    q.push({{newX, newY}, curr.second+1});
                    // grid[newX][newY] = 2;
                }
            }

        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }


        return ans == INT_MIN ? 0 : ans;
    }
};
