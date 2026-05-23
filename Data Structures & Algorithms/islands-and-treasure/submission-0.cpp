class Solution {
public:
        void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& ans) {
        queue<pair<pair<int, int>, int>> q;
        q.push({{i, j}, 0});
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            visited[curr.first.first][curr.first.second] = 1;
            int step = curr.second;
            for(int i=0; i<4; i++){
                int newx = curr.first.first + dx[i];
                int newy = curr.first.second + dy[i];
                if(newx >= 0 && newx < n && newy >=0 && newy < m){
                    if(grid[newx][newy] == 2147483647 && visited[newx][newy] == 0){
                        ans[newx][newy] = min(ans[newx][newy], step+1);
                        q.push({{newx, newy}, step+1});
                    }
                }
            }
        }
        return;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 2147483647));
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            ans[curr.first][curr.second] = 0;
            bfs(curr.first, curr.second, grid, ans);
        }

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(ans[i][j] == 2147483647) ans[i][j] = -1;
            }
        }
        grid = ans;
    }
};
