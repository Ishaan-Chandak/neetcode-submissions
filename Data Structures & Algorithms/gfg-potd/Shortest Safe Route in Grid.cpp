class Solution {
  public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    
    
    void markUnsafe(int i, int j, int &n, int &m, vector<vector<int>> &mat) {
        for(int k=0; k<4; k++){
            int newx = i + dx[k];
            int newy = j + dy[k];
            if(newx >= 0 and newx < n and newy >= 0 and newy < m) mat[newx][newy] = 0;
        }
    }
    
    // backtracking approach - TLE
    
    // int dfs(int i, int j, int &n, int &m, vector<vector<int>> &mat, vector<vector<int>> &visted) {
    //     if(i < 0 or i >= n or j < 0 or j >= m) return 1e8;
        
    //     if(mat[i][j] == 0 or visted[i][j] == 1) return 1e8;
        
    //     if(j == m-1 and (i >= 0 and i < n)) return 1;
        
    //     int ans = INT_MAX;
    //     visted[i][j] = 1;
    //     for(int k=0; k<4; k++) {
    //         int newx = i + dx[k];
    //         int newy = j + dy[k];
    //         int temp = 1 + dfs(newx, newy, n, m, mat, visted);
    //         ans = min(ans, temp);
    //     }
    //     visted[i][j] = 0;
        
    //     return ans;
    // }
  
    int shortestPath(vector<vector<int>> &mat) {
        // code here
        vector<pair<int, int>> mines;
        int m = mat[0].size(), n = mat.size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) mines.push_back({i, j});
            }
        }
        
        for(auto i : mines) {
            markUnsafe(i.first, i.second, n, m, mat);
        }
        
        int ans = -1;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        
        for(int i=0; i<n; i++) {
            if(mat[i][0] == 1) {
                q.push({1, {i, 0}});
                vis[i][0] = 1;
            } 
        }
        
        while(!q.empty()) {
            auto it = q.top();
            q.pop();
            
            if(it.second.second == m - 1) {
                ans = it.first;
                break;
            }
            
            int i = it.second.first, j = it.second.second, dist = it.first;
            for(int k=0; k<4; k++) {
                int newx = i + dx[k];
                int newy = j + dy[k];
                
                if(newx >= 0 and newx < n and newy >= 0 and newy < m and mat[newx][newy] != 0 and vis[newx][newy] == 0) {
                    q.push({dist + 1, {newx, newy}});
                    vis[newx][newy] = 1;
                }
            }
        }
        
        return ans;
    }
};
