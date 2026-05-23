class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            visited[curr.first][curr.second] = 1;
            for(int i=0; i<4; i++){
                int newx = curr.first + dx[i];
                int newy = curr.second + dy[i];
                if(newx >= 0 && newx < n && newy >=0 && newy < m){
                    if(grid[newx][newy] == '1' && visited[newx][newy] == 0){
                        q.push({newx, newy});
                    }
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int cnt = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    bfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
