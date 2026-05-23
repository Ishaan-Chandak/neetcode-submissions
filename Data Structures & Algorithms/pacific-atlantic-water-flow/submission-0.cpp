class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    void bfs(int i, int j, int n, int m, vector<vector<int>>& visited, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1; // Mark the starting cell as visited

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) { // Use 'd' instead of 'i' to avoid confusion
                int newx = curr.first + dx[d];
                int newy = curr.second + dy[d];
                if (newx >= 0 && newx < n && newy >= 0 && newy < m) {
                    if (grid[newx][newy] >= grid[curr.first][curr.second] && visited[newx][newy] == 0) {
                        q.push({newx, newy});
                        visited[newx][newy] = 1; // Mark the new cell as visited
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));

        // Process Pacific border cells
        for (int i = 0; i < m; i++) {
            if (pac[0][i] == 0) bfs(0, i, n, m, pac, heights);
        }

        for (int i = 0; i < n; i++) {
            if (pac[i][0] == 0) bfs(i, 0, n, m, pac, heights);
        }

        // Process Atlantic border cells
        for (int i = 0; i < m; i++) {
            if (atl[n-1][i] == 0) bfs(n-1, i, n, m, atl, heights);
        }

        for (int i = 0; i < n; i++) {
            if (atl[i][m-1] == 0) bfs(i, m-1, n, m, atl, heights);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] == 1 && atl[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
