class Solution {
public:

    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            visited[curr.first][curr.second] = 1;

            for(int i=0; i<4; i++) {
                int newx = curr.first + dx[i]; 
                int newy = curr.second + dy[i];

                if(newx >= 0 and newx < n and newy >= 0 and newy < m) {
                    if(visited[newx][newy] == 0 and grid[newx][newy] == '1') {
                        q.push({newx, newy});
                    }
                } 
            }
        }

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int cnt = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1' and visited[i][j] == 0) {
                    bfs(i, j, grid, visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
